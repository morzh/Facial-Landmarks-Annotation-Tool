/*
 * Copyright (C) 2016 Luiz Carlos Vieira (http://www.luiz.vieira.nom.br)
 *
 * This file is part of FLAT.
 *
 * FLAT is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * FLAT is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "childwindow.h"
#include "mainwindow.h"
#include "application.h"
#include "Landmarks95Interpolator.h"

#include <QMessageBox>
#include <QGridLayout>
#include <QApplication>
#include <QtMath>
#include <QDebug>

#include <vector>
#include <iostream>

using namespace std;

// +-----------------------------------------------------------
ft::ChildWindow::ChildWindow(QWidget *pParent) :
    QWidget(pParent)
{
	setAutoFillBackground(true);
	setBackgroundRole(QPalette::Dark);
	setAttribute(Qt::WA_DeleteOnClose);

	QGridLayout *pLayout = new QGridLayout(this);
	pLayout->setMargin(0);
	setLayout(pLayout);

	m_pFaceWidget = new FaceWidget(this);
	pLayout->addWidget(m_pFaceWidget);

	m_pFaceWidget->setPixmap(QPixmap(":/images/noface"));

	m_pFaceDatasetModel = new FaceDatasetModel();
	m_pFaceSelectionModel = new QItemSelectionModel(m_pFaceDatasetModel);

	// Capture of relevant signals
	connect(m_pFaceWidget, SIGNAL(onScaleFactorChanged(const double)), this, SLOT(onScaleFactorChanged(const double)));
	connect(m_pFaceWidget, SIGNAL(onRotateFactorChanged(const double)), this, SLOT(onRotateFactorChanged(const double)));
	connect(m_pFaceWidget, SIGNAL(onFaceFeaturesSelectionChanged()), this, SLOT(onFaceFeaturesSelectionChanged()));
	connect(m_pFaceWidget, SIGNAL(onFaceFeaturesChanged()), this, SLOT(onDataChanged()));
	connect(m_pFaceDatasetModel, SIGNAL(dataChanged(const QModelIndex&, const QModelIndex&, const QVector<int>&)), this, SLOT(onDataChanged()));
	connect(m_pFaceSelectionModel, SIGNAL(currentChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(onCurrentChanged(const QModelIndex &, const QModelIndex &)));

	// Indicate that it is a brand new dataset (i.e. not yet saved to a file)
	setProperty("new", true);
	m_iCurrentImage = -1;

    proxy = new QSortFilterProxyModel(this);
    proxy->setDynamicSortFilter(true);

    proxy->setSourceModel(m_pFaceDatasetModel);
    m_pFaceSelectionProxyModel = new KLinkItemSelectionModel(proxy, m_pFaceSelectionModel, this);


}

// +-----------------------------------------------------------
ft::ChildWindow::~ChildWindow()
{
	delete m_pFaceSelectionModel;
	delete m_pFaceDatasetModel;
	delete proxy;
	delete m_pFaceSelectionProxyModel;
}

// +-----------------------------------------------------------
ft::FaceDatasetModel* ft::ChildWindow::dataModel() const
{
	return m_pFaceDatasetModel;
}

// +-----------------------------------------------------------
QItemSelectionModel* ft::ChildWindow::selectionModel() const
{
	return m_pFaceSelectionModel;
}

// +-----------------------------------------------------------
bool ft::ChildWindow::save(QString &sMsgError)
{
	if(!m_pFaceDatasetModel->saveToFile(windowFilePath(), sMsgError))
		return false;

	onDataChanged(false);
	setProperty("new", QVariant()); // No longer a new dataset
	return true;
}

// +-----------------------------------------------------------
bool ft::ChildWindow::saveToFile(const QString &sFileName, QString &sMsgError)
{
	if(!m_pFaceDatasetModel->saveToFile(sFileName, sMsgError))
		return false;

	setWindowFilePath(sFileName);
	onDataChanged(false);
	setProperty("new", QVariant()); // No longer a new dataset
	return true;
}

// +-----------------------------------------------------------
bool ft::ChildWindow::loadFromFile(const QString &sFileName, QString &sMsgError)
{
	if(!m_pFaceDatasetModel->loadFromFile(qPrintable(sFileName), sMsgError))
		return false;

	setWindowFilePath(sFileName);
	onDataChanged(false);
	setProperty("new", QVariant()); // No longer a new dataset
	return true;
}

// +-----------------------------------------------------------
void ft::ChildWindow::setZoomLevel(const int iLevel)
{
	int iSteps = iLevel - 11; // Because 11 is the middle slider value, equivalent to the scale of 1.0 (100%)
	double dBase = iSteps < 0 ? FaceWidget::ZOOM_OUT_STEP : FaceWidget::ZOOM_IN_STEP;
	
	double dFactor = 1.0 * qPow(dBase, abs(iSteps));
	m_pFaceWidget->setScaleFactor(dFactor);
}

// +-----------------------------------------------------------
int ft::ChildWindow::getZoomLevel() const
{
	double dFactor = m_pFaceWidget->getScaleFactor();
	double dBase = dFactor < 1.0 ? FaceWidget::ZOOM_OUT_STEP : FaceWidget::ZOOM_IN_STEP;

	int iSteps = qCeil(qLn(abs(dFactor)) / qLn(dBase));
	if(dFactor > 1.0)
		return iSteps + 11;
	else
		return 11 - iSteps;
}

// +-----------------------------------------------------------
void ft::ChildWindow::zoomIn()
{
	m_pFaceWidget->zoomIn();
}

// +-----------------------------------------------------------
void ft::ChildWindow::zoomOut()
{
	m_pFaceWidget->zoomOut();
}

// +-----------------------------------------------------------
void ft::ChildWindow::onScaleFactorChanged(const double dScaleFactor)
{
	Q_UNUSED(dScaleFactor);

	QModelIndex oCurrent = m_pFaceSelectionModel->currentIndex();
	QString sImageName = m_pFaceDatasetModel->data(m_pFaceDatasetModel->index(oCurrent.row(), 0), Qt::UserRole).toString();
	emit onUIUpdated(sImageName, getZoomLevel());
}

// +-----------------------------------------------------------
void ft::ChildWindow::onRotateFactorChanged(const double dScaleFactor)
{
	Q_UNUSED(dScaleFactor);

	QModelIndex oCurrent = m_pFaceSelectionModel->currentIndex();
	QString sImageName = m_pFaceDatasetModel->data(m_pFaceDatasetModel->index(oCurrent.row(), 0), Qt::UserRole).toString();
	emit onUIUpdated(sImageName, getZoomLevel());
}

// +-----------------------------------------------------------

void ft::ChildWindow::onModelChanged(const bool bModified){

    if(bModified)
        updateFeaturesFromDataset();
    setWindowModified(bModified);
    emit onDataModified();

}
void ft::ChildWindow::onDataChanged(const bool bModified)
{
	if(bModified)
		updateFeaturesInDataset();
	setWindowModified(bModified);
	emit onDataModified();
}



// +-----------------------------------------------------------
void ft::ChildWindow::onCurrentChanged(const QModelIndex &oCurrent, const QModelIndex &oPrevious)
{
	Q_UNUSED(oPrevious);

	if(!oCurrent.isValid())
	{
		m_iCurrentImage = -1;
		m_pFaceWidget->setPixmap(QPixmap(":/images/noface"));
		emit onUIUpdated("", 0);
	}
	else
	{
		m_iCurrentImage = oCurrent.row();
		QVariant oData = m_pFaceDatasetModel->data(m_pFaceDatasetModel->index(m_iCurrentImage, 2), Qt::UserRole);
		if(oData.isValid())
			m_pFaceWidget->setPixmap(oData.value<QPixmap>());
		else
			m_pFaceWidget->setPixmap(QPixmap(":/images/brokenimage"));

		QString sImageName = oCurrent.data(Qt::UserRole).toString();
		emit onUIUpdated(sImageName, getZoomLevel());

		refreshFeaturesInWidget();
	}
}

// +-----------------------------------------------------------
void ft::ChildWindow::refreshFeaturesInWidget()
{
	vector<FaceFeature*> vFeats = m_pFaceDatasetModel->getFeatures(m_iCurrentImage);
	QList<FaceFeatureNode*> lsNodes = m_pFaceWidget->getFaceFeatures(m_pFaceDatasetModel->numFeatures()); // This call automatically guarantees that there are "m_pFaceDatasetModel->numFeatures()" features in the editor
	for(int i = 0; i < (int) vFeats.size(); i++)
	{
		lsNodes[i]->setData(0, true); // Indication to avoid emitting position change event

		// Refresh the feature visual in the widget:
		//    - (re)position the feature
		//    - (re)do any connections
		lsNodes[i]->setPos(vFeats[i]->x(), vFeats[i]->y());
		lsNodes[i]->setRadius(vFeats[i]->getRadius());
		foreach(int iID, vFeats[i]->getConnections())
			m_pFaceWidget->connectFaceFeatures(vFeats[i]->getID(), iID);

		lsNodes[i]->setData(0, false);
	}

	calcFeaturesRadiusAdd(lsNodes);
}

// +-----------------------------------------------------------
void ft::ChildWindow::updateFeaturesFromDataset(){

    QList<FaceFeatureNode*> lsNodes = m_pFaceWidget->getFaceFeatures();
    vector<FaceFeature*> vFeats = m_pFaceDatasetModel->getFeatures(m_iCurrentImage);

    FaceFeatureNode* pNode;
    int id;
    for(int i = 0; i < (int) lsNodes.size(); i++)
    {
        if(i >= lsNodes.size()) // Sanity check (vFeats and lsNodes are supposed to have the same size, but who knows?)
        {
            qCritical() << tr("An update of face features in dataset was not performed due to inconsistences.");
            continue;
        }

        pNode = lsNodes.at(i);
        id    =  pNode->getID();

        pNode->setX( vFeats[id]->x());
        pNode->setY( vFeats[id]->y());
    }
}

void ft::ChildWindow::updateFeaturesInDataset()
{
	QList<FaceFeatureNode*> lsNodes = m_pFaceWidget->getFaceFeatures();
	vector<FaceFeature*> vFeats = m_pFaceDatasetModel->getFeatures(m_iCurrentImage);

	FaceFeatureNode* pNode;
	for(int i = 0; i < (int) vFeats.size(); i++)
	{
		if(i >= lsNodes.size()) // Sanity check (vFeats and lsNodes are supposed to have the same size, but who knows?)
		{
			qCritical() << tr("An update of face features in dataset was not performed due to inconsistences.");
			continue;
		}
		pNode = lsNodes.at(i);
		vFeats[i]->setID(pNode->getID());
		vFeats[i]->setX(pNode->x());
		vFeats[i]->setY(pNode->y());
		vFeats[i]->setRadius(pNode->getRadius());
	}
}

// +-----------------------------------------------------------
void ft::ChildWindow::onFaceFeaturesSelectionChanged()
{
	emit onFeaturesSelectionChanged();
}

// +-----------------------------------------------------------
bool ft::ChildWindow::displayFaceFeatures() const
{
	return m_pFaceWidget->displayFaceFeatures();
}
// +-----------------------------------------------------------
void ft::ChildWindow::setDisplayFaceFeatures(const bool bValue)
{
	m_pFaceWidget->setDisplayFaceFeatures(bValue);
}

// +-----------------------------------------------------------
bool ft::ChildWindow::displayConnections() const
{
	return m_pFaceWidget->displayConnections();
}

// +-----------------------------------------------------------
void ft::ChildWindow::setDisplayConnections(const bool bValue)
{
	m_pFaceWidget->setDisplayConnections(bValue);
}

// +-----------------------------------------------------------
bool ft::ChildWindow::displayFeatureIDs() const
{
	return m_pFaceWidget->displayFeatureIDs();
}

// +-----------------------------------------------------------
void ft::ChildWindow::setDisplayFeatureIDs(const bool bValue)
{
	m_pFaceWidget->setDisplayFeatureIDs(bValue);
}

// +-----------------------------------------------------------
const QList<ft::FaceFeatureNode*>& ft::ChildWindow::getFaceFeatures() const
{
	return m_pFaceWidget->getFaceFeatures();
}

// +-----------------------------------------------------------
QList<ft::FaceFeatureNode*> ft::ChildWindow::getSelectedFeatures() const
{
	return m_pFaceWidget->getSelectedFeatures();
}

// +-----------------------------------------------------------
QList<ft::FaceFeatureEdge*> ft::ChildWindow::getSelectedConnections() const
{
	return m_pFaceWidget->getSelectedConnections();
}

// +-----------------------------------------------------------
void ft::ChildWindow::setContextMenu(QMenu *pMenu)
{
	m_pFaceWidget->setContextMenu(pMenu);
}

// +-----------------------------------------------------------
void ft::ChildWindow::addFeature(const QPoint &oPos)
{
	FaceFeatureNode *pNode = m_pFaceWidget->addFaceFeature(oPos, true);
	m_pFaceDatasetModel->addFeature(pNode->getID(), pNode->x(), pNode->y());
	onDataChanged();
}

// +-----------------------------------------------------------
void ft::ChildWindow::removeSelectedFeatures()
{
	bool bUpdated = false;
	QList<FaceFeatureNode*> lsFeats = m_pFaceWidget->getSelectedFeatures();
	foreach(FaceFeatureNode *pNode, lsFeats)
	{
		m_pFaceDatasetModel->removeFeature(pNode->getID());
		m_pFaceWidget->removeFaceFeature(pNode);
		bUpdated = true;
	}
	if(bUpdated)
	{
		updateFeaturesInDataset();
		onDataChanged();
	}
}

// +-----------------------------------------------------------
void ft::ChildWindow::connectFeatures()
{
	bool bUpdated = false;
	QList<FaceFeatureNode*> lsFeats = m_pFaceWidget->getSelectedFeatures();
	QList<FaceFeatureNode*>::iterator oFirst, oSecond;

	for(oFirst = lsFeats.begin(); oFirst != lsFeats.end(); oFirst++)
	{
		for(oSecond = oFirst + 1; oSecond != lsFeats.end(); oSecond++)
		{
			m_pFaceWidget->connectFaceFeatures(*oFirst, *oSecond);
			m_pFaceDatasetModel->connectFeatures((*oFirst)->getID(), (*oSecond)->getID());
			bUpdated = true;
		}
	}
	if(bUpdated)
		onDataChanged();
}

// +-----------------------------------------------------------
void ft::ChildWindow::disconnectFeatures()
{
	bool bUpdated = false;
	QList<FaceFeatureNode*> lsFeats = m_pFaceWidget->getSelectedFeatures();
	QList<FaceFeatureNode*>::iterator oFirst, oSecond;

	for(oFirst = lsFeats.begin(); oFirst != lsFeats.end(); oFirst++)
	{
		for(oSecond = oFirst + 1; oSecond != lsFeats.end(); oSecond++)
		{
			m_pFaceWidget->disconnectFaceFeatures(*oFirst, *oSecond);
			m_pFaceDatasetModel->disconnectFeatures((*oFirst)->getID(), (*oSecond)->getID());
			bUpdated = true;
		}
	}
	if(bUpdated)
		onDataChanged();
}

// +-----------------------------------------------------------
bool ft::ChildWindow::positionFeatures(std::vector<QPoint> vPoints)
{
	QList<FaceFeatureNode *> lFeats = m_pFaceWidget->getFaceFeatures(vPoints.size()); // this call automatically adds or removes features to match vPoints.size()
	
	// Adjust the dataset so it has the same amount of features as the widget
	vector<FaceFeature*> vFeats = m_pFaceDatasetModel->getFeatures(m_iCurrentImage);
	int iDiff = lFeats.size() - vFeats.size();

	// If the widget has more features than the dataset, add the difference
	if (iDiff > 0)
	{
		for (int i = 0; i < iDiff; i++)
			m_pFaceDatasetModel->addFeature(lFeats.size() + i - 1, 0, 0);
	}

	// Else, if the widget has less features than the dataset, remove the difference
	else if (iDiff < 0)
	{
		for (int i = 0; i < abs(iDiff); i++)
			m_pFaceDatasetModel->removeFeature(lFeats.size() - i - 1);
	}

	// Move the features
	FaceFeatureNode *pFeat;
	for (unsigned int i = 0; i < vPoints.size(); i++)
	{
		pFeat = lFeats.at(i);
		pFeat->setPos(vPoints[i]);
	}
	updateFeaturesInDataset();
	setWindowModified(true);
	emit onDataModified();

	return true;
}

void ft::ChildWindow::calcFeaturesRadiusAdd(QList<FaceFeatureNode *>& list) {

    int min_radius = 1e6;

//    auto list_it = list.begin();

    for (int i=0; i<list.size(); ++i){

        int r = list[i]->getRadius();
        if( r < min_radius)
            min_radius = r;
    }


    for (int i=0; i<list.size(); ++i){

        int r = list[i]->getRadius();
        list[i]->addToRadiusMult =   (float) r/min_radius ;

    }
}

void ft::ChildWindow::hideOvalUpperLandmarks() {
    hideLandmarks(17,27);
}
void ft::ChildWindow::showOvalUpperLandmarks() {
    showLandmarks(17,27);
}

void ft::ChildWindow::hideOvalLowLandmarks() {
    hideLandmarks(0,16);
}
void ft::ChildWindow::showOvalLowLandmarks() {
    showLandmarks(0,16);
}




void ft::ChildWindow::hideBrowRightLandmarks() {
    hideLandmarks(28,32);
}
void ft::ChildWindow::showBrowRightLandmarks() {
    showLandmarks(28,32);
}

void ft::ChildWindow::hideBrowLeftLandmarks() {
    hideLandmarks(33,37);
}
void ft::ChildWindow::showBrowLeftLandmarks() {
    showLandmarks(33,37);
}



void ft::ChildWindow::hideEyeRightLandmarks() {
    hideLandmarks(38,47);
}
void ft::ChildWindow::showEyeRightLandmarks() {
    showLandmarks(38,47);
}

void ft::ChildWindow::hideEyeLeftLandmarks() {
    hideLandmarks(48,57);
}
void ft::ChildWindow::showEyeLeftLandmarks() {
    showLandmarks(48,57);
}



void ft::ChildWindow::hideNoseShapeLandmarks() {
    hideLandmarks(62,74);
}
void ft::ChildWindow::showNoseShapeLandmarks() {
    showLandmarks(62,74);
}

void ft::ChildWindow::showNoseRidgeLandmarks() {
    showLandmarks(58,61);
}
void ft::ChildWindow::hideNoseRidgeLandmarks() {
    hideLandmarks(58,61);
}



void ft::ChildWindow::hideMouthOuterLandmarks() {
    hideLandmarks(75,86);
}
void ft::ChildWindow::showMouthOuterLandmarks() {
    showLandmarks(75,86);
}

void ft::ChildWindow::showMouthInnerLandmarks() {
    showLandmarks(87,94);
}
void ft::ChildWindow::hideMouthInnerLandmarks() {
    hideLandmarks(87,94);
}



void ft::ChildWindow::showLandmarks(int idx_start, int idx_end) {

    QList<FaceFeatureNode *> lsFeats = m_pFaceWidget->getFaceFeatures(-1);
    for (int idx = idx_start; idx <= idx_end; ++idx){
        lsFeats[idx]->isVisible = true;
        lsFeats[idx]->setFlag(QGraphicsItem::ItemIsSelectable, true);
        lsFeats[idx]->setFlag(QGraphicsItem::ItemIsMovable, true);
    }
    onDataChanged();
}
void ft::ChildWindow::hideLandmarks(int idx_start, int idx_end) {

    QList<FaceFeatureNode *> lsFeats = m_pFaceWidget->getFaceFeatures(-1);
    for (int idx = idx_start; idx <= idx_end; ++idx){
        lsFeats[idx]->isVisible = false;
        lsFeats[idx]->setFlag(QGraphicsItem::ItemIsSelectable, false);
        lsFeats[idx]->setFlag(QGraphicsItem::ItemIsMovable, false);
    }
    onDataChanged();
}

void ft::ChildWindow::InterpolateLandmarks95(const QList<int> &indices) {

    if (m_pFaceDatasetModel == nullptr)    return;

    Landmarks95Interpolator interp;

    for (auto idx : indices ) {
        std::vector<ft::FaceFeature*> sFaceFeatures = m_pFaceDatasetModel->getFeatures(idx);
        interp.interpolate(sFaceFeatures);
        sFaceFeatures[0]->setX(0.0);
        sFaceFeatures[0]->setY(0.0);
    }
    onModelChanged();
}

QList<QString> ft::ChildWindow::getImageNamesList() {

    return m_pFaceDatasetModel->getImageNamesList();
}

QItemSelectionModel *ft::ChildWindow::selectionProxyModel() const {
    return m_pFaceSelectionProxyModel;
}

QAbstractItemModel* ft::ChildWindow::dataProxyModel() const {
    return proxy;
}

void ft::ChildWindow::setFilterString(const QString &qString) {

    proxy->setFilterFixedString(qString);

}

const QString &ft::ChildWindow::getSearchBoxText() const {
    return searchBoxText;
}

void ft::ChildWindow::setSearchBoxText(const QString &searchBoxText) {
    ChildWindow::searchBoxText = searchBoxText;
}

