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

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutwindow.h"
#include "landmarksproperties.h"
#include "facefitconfig.h"
#include "utils.h"
#include "application.h"

#include <vector>

#include <QApplication>
#include <QImage>
#include <QFileDialog>
#include <QDesktopServices>
#include <QAction>
#include <QMessageBox>
#include <QTemporaryFile>
#include <QPushButton>
#include <iostream>


using namespace std;

// +-----------------------------------------------------------
ft::MainWindow::MainWindow(QWidget *pParent) :   QMainWindow(pParent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	QPalette oROPalette = ui->textFileName->palette();
	oROPalette.setColor(QPalette::Base, oROPalette.midlight().color());
	ui->textFileName->setPalette(oROPalette);

    setWindowState( Qt::WindowMaximized );

    m_pLandmarkGroupsButton = new QMenu(ui->toolsToolBar);
    ui->toolsToolBar->addAction(m_pLandmarkGroupsButton->menuAction());

    setWindowIcon(QIcon(":/icons/progicon"));
	ui->tabWidget->setAutoFillBackground(true);
	ui->tabWidget->setBackgroundRole(QPalette::Midlight);

	// Setup the TAB changing events
	connect(ui->tabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(on_tabCloseRequested(int)));
	connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(on_tabChanged(int)));

	// Add the view dropdown button manually (because Qt designer does not allow it...)
	m_pViewButton = new QMenu(ui->imagesToolbar);
	ui->imagesToolbar->addSeparator();
    ui->imagesToolbar->addAction(m_pViewButton->menuAction());

    //Add sorting dropdown button manually
    m_pSortButton = new QMenu(ui->imagesToolbar);
    ui->imagesToolbar->addSeparator();
    ui->imagesToolbar->addAction(m_pSortButton->menuAction());


    QPushButton * closeButton = new QPushButton(ui->menuBar);
    QPushButton * restoreButton = new QPushButton(ui->menuBar);
    QPushButton * minimizeButton = new QPushButton(ui->menuBar);
    QPushButton * fullScreenButton = new QPushButton(ui->menuBar);
    closeButton->setFixedSize(18, 18);
    restoreButton->setFixedSize(18, 18);
    minimizeButton->setFixedSize(18, 18);
    fullScreenButton->setFixedSize(18, 18);

    closeButton->setIcon(QIcon(":/icons/close"));
    fullScreenButton->setIcon(QIcon(":/icons/fullscreen"));
    minimizeButton->setIcon(QIcon(":/icons/minimize"));

    if ( windowState().testFlag(Qt::WindowMaximized)  ) {
        std::cout << "MAximized" << std::endl;
        restoreButton->setIcon(QIcon(":/icons/unmaximize"));
    }
    else if ( windowState().testFlag(Qt::WindowNoState)) {
        std::cout << "No State" << std::endl;
        restoreButton->setIcon(QIcon(":/icons/maximize"));
    }


    closeButton->setIconSize(QSize(16, 16));
    fullScreenButton->setIconSize(QSize(16, 16));

    QString flatButtonStyle = "QPushButton {\n"
                            "border: none;\n"
                            "margin: 0px;\n"
                            "padding: 0px;\n"
                            "} \n"
                            "QPushButton:hover{\n"
                             "border: 1px solid;\n"
                            "}";

    closeButton->setStyleSheet(flatButtonStyle);
    minimizeButton->setStyleSheet(flatButtonStyle);
    fullScreenButton->setStyleSheet(flatButtonStyle);
    restoreButton->setStyleSheet(flatButtonStyle);

    QWidget*        menuWidget = new QWidget(this);
    QGridLayout*    menuWidgetLayout = new QGridLayout(menuWidget);

    menuWidgetLayout->setMargin(0);
    menuWidget->setLayout(menuWidgetLayout);
    // Add the menu bar and all tool buttons to the widget
    menuWidgetLayout->addWidget(ui->menuBar, 0, 0, 1,1);
    menuWidgetLayout->addWidget(minimizeButton, 0, 1, 1, 1);
    menuWidgetLayout->addWidget(fullScreenButton, 0, 2, 1, 1);
    menuWidgetLayout->addWidget(restoreButton, 0, 3, 1, 1);
    menuWidgetLayout->addWidget(closeButton, 0, 4, 1, 1);

    setMenuWidget(menuWidget);

    connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(fullScreenButton, SIGNAL(clicked()), this, SLOT(on_actionFullScreen_triggered()));
    connect(minimizeButton, SIGNAL(clicked()), this, SLOT(on_actionMinimize_triggered()));
    connect(restoreButton, SIGNAL(clicked()), this, SLOT(on_actionRestore_triggered()));



    QAction *pViewDetails = new QAction(QIcon(":/icons/viewdetails_bw"), tr("&Details"), this);
    QAction *pViewIcons = new QAction(QIcon(":/icons/viewicons_bw"), tr("&Icons"), this);
    pViewDetails->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_D));
    pViewIcons->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_I));
    m_pViewButton->addAction(pViewDetails);
	m_pViewButton->addAction(pViewIcons);


    QSignalMapper *pMapView = new QSignalMapper(ui->imagesToolbar);
    connect(pViewDetails, SIGNAL(triggered()), pMapView, SLOT(map()));
    connect(pViewIcons, SIGNAL(triggered()), pMapView, SLOT(map()));
    pMapView->setMapping(pViewDetails, QString("details"));
    pMapView->setMapping(pViewIcons, QString("icons"));

    connect(pMapView, SIGNAL(mapped(QString)), this, SLOT(setImageListView(QString)));
    connect(m_pViewButton->menuAction(), SIGNAL(triggered()), this, SLOT(toggleImageListView()));


    QAction *pSortAZ        = new QAction(QIcon(":/icons/sort_az"),  tr("Sort A→Z"), this);
    QAction *pSortZA        = new QAction(QIcon(":/icons/sort_za"),  tr("Sort Z→A"), this);
    QAction *pSortUnsorted  = new QAction(QIcon(":/icons/unsorted"), tr("Unsorted"), this);
    m_pSortButton->addAction(pSortAZ);
    m_pSortButton->addAction(pSortZA);
    m_pSortButton->addAction(pSortUnsorted);

    QSignalMapper *pMapSort = new QSignalMapper(ui->imagesToolbar);
    connect(pSortAZ, SIGNAL(triggered()), pMapSort, SLOT(map()));
    connect(pSortZA, SIGNAL(triggered()), pMapSort, SLOT(map()));
    connect(pSortUnsorted, SIGNAL(triggered()), pMapSort, SLOT(map()));
    pMapSort->setMapping(pSortAZ, QString("sort_az"));
    pMapSort->setMapping(pSortZA, QString("sort_za"));
    pMapSort->setMapping(pSortUnsorted, QString("sort_unsorted"));

    connect(pMapSort, SIGNAL(mapped(QString)), this, SLOT(setImageListSort(QString)));
    connect(m_pSortButton->menuAction(), SIGNAL(triggered()), this, SLOT(toggleImageListSort()));

	m_pLandmarkGroupsButton->setIcon(QIcon(":/icons/landmarksgroups")); // By default display the image thumbnails
	m_pSortButton->setIcon(QIcon(":/icons/unsorted")); // By default display the image thumbnails
	m_pViewButton->setIcon(QIcon(":/icons/viewicons_bw")); // By default display the image thumbnails
	ui->treeImages->setVisible(false);

	m_sLastPathUsed = QDir::toNativeSeparators(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)) + QDir::separator();
	m_sFaceFitPath = ""; /// Default path for the face-fit utility
	m_oFitProcess = new QProcess(this);
	connect(m_oFitProcess, SIGNAL(error(QProcess::ProcessError)), this, SLOT(onFitError(::ProcessError)));
	connect(m_oFitProcess, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(onFitFinished(int, QProcess::ExitStatus)));

	// Add the action shortcuts to the tooltips (in order to make it easier for the user to know they exist)
	// P.S.: I wonder why doesn't Qt do that automatically... :)
	QObjectList lsObjects = children();
	QAction *pAction;
	for(int i = 0; i < lsObjects.size(); i++)
	{
		pAction = qobject_cast<QAction*>(lsObjects.at(i));
		if(pAction && !pAction->shortcut().isEmpty())
			pAction->setToolTip(QString("%1 (%2)").arg(pAction->toolTip()).arg(pAction->shortcut().toString()));
	}

	connect(ui->zoomSlider, SIGNAL(valueChanged(int)), this, SLOT(onZoomSliderValueChanged(int)));

    ui->menuBar->installEventFilter(this);

}

// +-----------------------------------------------------------
ft::MainWindow::~MainWindow()
{
	// Save the current window state and geometry
	QSettings oSettings;
	oSettings.setValue("geometry", saveGeometry());
	oSettings.setValue("windowState", saveState());
	oSettings.setValue("lastPathUsed", m_sLastPathUsed);
	oSettings.setValue("faceFitPath", m_sFaceFitPath);

    if(m_pAbout)
        delete m_pAbout;
    if(m_pLProperties)
        delete m_pLProperties;
	if(m_pViewButton)
		delete m_pViewButton;
	if(m_pSortButton)
		delete m_pSortButton;
	if(m_pLandmarkGroupsButton)
		delete m_pLandmarkGroupsButton;
	if (m_oFitProcess)
		delete m_oFitProcess;


    delete ui;
}

// +-----------------------------------------------------------
void ft::MainWindow::closeEvent(QCloseEvent *pEvent)
{
	QList<ChildWindow*> lModified;
	ChildWindow *pChild;

	// Get the list of modified child windows
	for(int i = 0; i < ui->tabWidget->count(); i++)
	{
		pChild = (ChildWindow*) ui->tabWidget->widget(i);
		if(pChild->isWindowModified())
			lModified.append(pChild);
	}

	// Ask for saving the modifiled child windows
	if(lModified.size() > 0)
	{
		QString sMsg;
		if(lModified.size() == 1)
		{
			pChild = lModified[0];
			sMsg = tr("There are pending changes in the face annotation dataset named [%1]. Do you wish to save it before closing?").arg(QFileInfo(pChild->windowFilePath()).baseName());
		}
		else
			sMsg = tr("There are %1 face annotation datasets opened with pending changes. Do you wish to save them before closing?").arg(lModified.size());

		QMessageBox::StandardButton oResp = QMessageBox::question(this, tr("Pending changes"), sMsg, QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);

		// Do not close the tab if the user has chosen "cancel" or if she has chosen "yes" but then
		// cancelled the file save dialog in any of the modified tab
		if(oResp == QMessageBox::Cancel)
		{
			pEvent->ignore();
			return;
		}
		else if(oResp == QMessageBox::Yes)
		{
			for(int i = 0; i < lModified.size(); i++)
			{
				pChild = lModified[i];
				ui->tabWidget->setCurrentWidget(pChild);
				if(!saveCurrentFile())
				{
					pEvent->ignore();
					return;
				}
			}
		}
	}

	pEvent->accept();
}

// +-----------------------------------------------------------
void ft::MainWindow::showEvent(QShowEvent *pEvent)
{
	// Restore the previous window state and geometry
	QSettings oSettings;
	restoreState(oSettings.value("windowState").toByteArray());
	restoreGeometry(oSettings.value("geometry").toByteArray());
	QVariant vValue = oSettings.value("lastPathUsed");
	if (vValue.isValid())
		m_sLastPathUsed = vValue.toString();
	vValue = oSettings.value("faceFitPath");
	if (vValue.isValid())
		m_sFaceFitPath = vValue.toString();
	
	// Update UI elements
	updateUI();
	ui->actionShowImagesList->setChecked(ui->dockImages->isVisible());
	ui->actionShowImageProperties->setChecked(ui->dockProperties->isVisible());

	pEvent->accept();
}

// +-----------------------------------------------------------
void ft::MainWindow::on_actionNew_triggered()
{
    createChildWindow();
}

// +-----------------------------------------------------------
void ft::MainWindow::on_actionOpen_triggered()
{
    QString sFile = QFileDialog::getOpenFileName(this, tr("Open face annotation dataset..."), m_sLastPathUsed, tr("Face Annotation Dataset files (*.fad);; All files (*.*)"));
    if(sFile.length())
	{
		m_sLastPathUsed = QFileInfo(sFile).absolutePath();
		sFile = QDir::toNativeSeparators(sFile);
		int iPage = getFilePageIndex(sFile);
		if(iPage != -1)
		{
			ui->tabWidget->setCurrentIndex(iPage);
			showStatusMessage(QString(tr("The face annotation dataset [%1] is already opened in the editor.")).arg(Utils::shortenPath(sFile)));
		}
		else
		{
			ChildWindow *pChild = createChildWindow(sFile, false);

			QString sMsg;
			if(!pChild->loadFromFile(sFile, sMsg))
			{
				destroyChildWindow(pChild);
				QMessageBox::warning(this, tr("Fail to load the face annotation dataset"), tr("It was not possible to open the face annotation dataset:\n%1").arg(sMsg), QMessageBox::Ok);
				return;
			}

			if(pChild->dataModel()->rowCount() > 0)
				pChild->selectionModel()->setCurrentIndex(pChild->dataModel()->index(0, 0), QItemSelectionModel::Select);

            pChild->createGroupsData();
			updateUI();
		}
	}
}

// +-----------------------------------------------------------
void ft::MainWindow::on_actionSave_triggered()
{
	saveCurrentFile();
}

// +-----------------------------------------------------------
void ft::MainWindow::on_actionSaveAs_triggered()
{
	saveCurrentFile(true);
}

// +-----------------------------------------------------------
bool ft::MainWindow::saveCurrentFile(bool bAskForFileName)
{
	ChildWindow *pChild = (ChildWindow*) ui->tabWidget->currentWidget();
	if(!pChild || (!bAskForFileName && !pChild->isWindowModified()))
		return false;

	if(bAskForFileName)
	{
		QString sFileName = QFileDialog::getSaveFileName(this, tr("Save face annotation dataset..."), windowFilePath(), tr("Face Annotation Dataset files (*.fad);; All files (*.*)"));
		if(sFileName.length())
		{
			QString sMsg;
			if(!pChild->saveToFile(sFileName, sMsg))
			{
				QMessageBox::warning(this, tr("Fail to save the face annotation dataset"), tr("It was not possible to save the face annotation dataset:\n%1").arg(sMsg), QMessageBox::Ok);
				return false;
			}

			m_sLastPathUsed = QFileInfo(sFileName).absolutePath();
			return true;
		}
		else
			return false;
	}
	else
	{
		// Force the user to chose a file name if the dataset has not yet been saved
		if(pChild->property("new").toBool())
			return saveCurrentFile(true);
		else
		{
			QString sMsg;
			if(!pChild->save(sMsg))
			{
				QMessageBox::warning(this, tr("Fail to save the face annotation dataset"), tr("It was not possible to save the face annotation dataset:\n%1").arg(sMsg), QMessageBox::Ok);
				return false;
			}

			return true;
		}
	}
}

// +-----------------------------------------------------------
void ft::MainWindow::on_actionExit_triggered()
{
    close();
//    QApplication::exit(0);
}
void ft::MainWindow::on_actionMinimize_triggered()
{
    this->setWindowState(Qt::WindowMinimized);
}

void ft::MainWindow::on_actionFullScreen_triggered()
{
    this->setWindowState(Qt::WindowFullScreen);
}
void ft::MainWindow::on_actionRestore_triggered(){

    auto wState = windowState();

    if ( wState== Qt::WindowFullScreen)
        setWindowState(Qt::WindowMaximized);
    else if ( wState == Qt::WindowMaximized)
        setWindowState(Qt::WindowNoState);
    else if ( wState != Qt::WindowMaximized)
        setWindowState(Qt::WindowMaximized);
}


void ft::MainWindow::on_actionLandmarksProperties_triggered(){

    (new LandmarksProperties(this))->show();
}

// +-----------------------------------------------------------
void ft::MainWindow::on_actionConfigure_triggered()
{
	FaceFitConfig oConfig;
	if (oConfig.exec() == FaceFitConfig::Accepted)
		m_sFaceFitPath = oConfig.getFaceFitPath();
}

// +-----------------------------------------------------------
void ft::MainWindow::on_actionFitLandmarks_triggered()
{
	// Only continue if the face-fit utilility is properly configured
	if (m_sFaceFitPath.length() < 0 || !QFileInfo(m_sFaceFitPath).exists())
	{
		QMessageBox::critical(this, tr("Error running face-fit utility"), tr("The face-fit utility executable could not be executed. Please check its configuration."), QMessageBox::Ok);
		return;
	}

	// Get the selected face annotation dataset
	ChildWindow *pChild = (ChildWindow*)ui->tabWidget->currentWidget();
	if (!pChild) // Sanity check
		return;

	// Get the path of the selected image in the dataset
	QModelIndex oSelectedImage = pChild->selectionModel()->currentIndex();
	QModelIndex oIdx = pChild->dataModel()->index(oSelectedImage.row(), 1);
	QString sImageFile = pChild->dataModel()->data(oIdx, Qt::DisplayRole).toString();

	// Build the arguments for the face-fit utility
	QTemporaryFile oTemp("face-fit-results");
	oTemp.open();
	m_sFitTempFile = oTemp.fileName();
	oTemp.close();
	
	QStringList oArgs;
	oArgs << sImageFile << m_sFitTempFile;
	m_oFitProcess->start(m_sFaceFitPath, oArgs, QProcess::ReadOnly);
	showStatusMessage(tr("Face fit started. Please wait..."), 0);
}

// +-----------------------------------------------------------
void ft::MainWindow::onFitError(QProcess::ProcessError eError)
{
	Q_UNUSED(eError);
	QFile::remove(m_sFitTempFile);
	m_sFitTempFile = "";
	showStatusMessage(tr("The face fit utility executable failed to execute. Please check its configuration."));
}


// +-----------------------------------------------------------
void ft::MainWindow::onFitFinished(int iExitCode, QProcess::ExitStatus eExitStatus)
{
	QFileInfo oFileInfo(m_sFitTempFile);
	if (!oFileInfo.exists())
	{
		showStatusMessage(tr("The face fit utility could not fit the landmarks to this image."));
		QFile::remove(m_sFitTempFile);
		m_sFitTempFile = "";
		return;
	}

	vector<QPoint> vPoints = Utils::readFaceFitPointsFile(m_sFitTempFile);
	if (vPoints.size() == 0)
	{
		showStatusMessage(tr("The face fit utility could not fit the landmarks to this image."));
		QFile::remove(m_sFitTempFile);
		m_sFitTempFile = "";
		return;
	}

	QFile::remove(m_sFitTempFile);
	m_sFitTempFile = "";


	// Get the selected face annotation dataset
	ChildWindow *pChild = (ChildWindow*)ui->tabWidget->currentWidget();
	if (!pChild) // Sanity check
		return;

	// Reposition the features according to the face-fit results
	pChild->positionFeatures(vPoints);
	showStatusMessage(tr("Face fit completed successfully."));
}

// +-----------------------------------------------------------
void ft::MainWindow::on_actionExportPointsFile_triggered()
{
	ChildWindow *pChild = (ChildWindow*)ui->tabWidget->currentWidget();
	if (!pChild) // Sanity check
		return;

	QList<FaceFeatureNode *> lFeats = pChild->getFaceFeatures();
	if(lFeats.size() == 0)
	{
		QMessageBox::critical(this, tr("Error exporting data"), tr("The exporting can not be done because there are no landmarks to export."), QMessageBox::Ok);
		return;
	}

	QString sFileName = QFileDialog::getSaveFileName(this, tr("Export CSIRO points file..."), windowFilePath(), tr("CSIRO Face Analysis SDK points file (*.pts);; All files (*.*)"));
	if (sFileName.length())
	{
		QFile oFile(sFileName);
		if (!oFile.open(QFile::WriteOnly | QFile::Text))
		{
			QMessageBox::critical(this, tr("Error exporting data"), tr("The exporting failed because it was not possible to write to file [%1].").arg(sFileName), QMessageBox::Ok);
			return;
		}

		QTextStream oStream(&oFile);
		QString sData = QString("n_points: %1").arg(lFeats.size());
		oStream << sData << endl;
		oStream << "{" << endl;

		foreach(FaceFeatureNode *pFeat, lFeats)
		{
			sData = QString("%1\t%2").arg(pFeat->x()).arg(pFeat->y());
			oStream << sData << endl;
		}
		oStream << "}" << endl;
		oFile.close();
	}
}

// +-----------------------------------------------------------
void ft::MainWindow::on_actionProject_triggered()
{
	QDesktopServices::openUrl(QUrl("https://github.com/luigivieira/Facial-Landmarks-Annotation-Tool.git"));
}

// +-----------------------------------------------------------
void ft::MainWindow::on_actionAbout_triggered()
{
	(new AboutWindow(this))->show();
}

// +-----------------------------------------------------------
void ft::MainWindow::on_tabCloseRequested(int iTabIndex)
{
	ChildWindow* pChild = (ChildWindow*) ui->tabWidget->widget(iTabIndex);

	if(pChild->isWindowModified())
	{
		QString sMsg = tr("There are pending changes in the face annotation dataset named [%1]. Do you wish to save it before closing?").arg(QFileInfo(pChild->windowFilePath()).baseName());
		QMessageBox::StandardButton oResp = QMessageBox::question(this, tr("Pending changes"), sMsg, QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);

		// Do not close the tab if the user has chosen "cancel" or if she has chosen "yes" but then
		// cancelled the file save dialog
		ui->tabWidget->setCurrentIndex(iTabIndex);
		if(oResp == QMessageBox::Cancel || (oResp == QMessageBox::Yes && !saveCurrentFile()))
			return;
	}

	destroyChildWindow(pChild);

	if(ui->tabWidget->count() == 0) // no more tabs
	{
		ui->textFileName->setText("");
		ui->zoomSlider->blockSignals(true);
		ui->zoomSlider->setValue((ui->zoomSlider->maximum() - ui->zoomSlider->minimum()) / 2 + 1);
		ui->zoomSlider->blockSignals(false);
	}
}

// +-----------------------------------------------------------
void ft::MainWindow::on_tabChanged(int iTabIndex)
{
	Q_UNUSED(iTabIndex);
	updateUI();
}

// +-----------------------------------------------------------
void ft::MainWindow::on_actionAddImage_triggered()
{
	ChildWindow *pChild = (ChildWindow*) ui->tabWidget->currentWidget();
	if(!pChild)
		return;

    QStringList lsFiles = QFileDialog::getOpenFileNames(this, tr("Select face images..."), m_sLastPathUsed, tr("Common image files (*.bmp *.png *.jpg *.gif);; All files (*.*)"));
	if(lsFiles.size())
	{
		m_sLastPathUsed = QFileInfo(lsFiles[0]).absolutePath();
		pChild->dataModel()->addImages(lsFiles);

		if(!pChild->selectionModel()->currentIndex().isValid())
			pChild->selectionModel()->setCurrentIndex(pChild->dataModel()->index(0, 0), QItemSelectionModel::Select);
	}
}

// +-----------------------------------------------------------
void ft::MainWindow::on_actionRemoveImage_triggered()
{
	ChildWindow *pChild = (ChildWindow*) ui->tabWidget->currentWidget();
	if(!pChild)
		return;

	QModelIndexList lsSelected = pChild->selectionModel()->selectedRows();
	if(lsSelected.size() > 0)
	{
		QString sMsg;
		if(lsSelected.size() == 1)
			sMsg = tr("Do you confirm the removal of the selected image?");
		else
			sMsg = tr("Do you confirm the removal of %1 selected images?").arg(lsSelected.size());
		if(QMessageBox::question(this, tr("Confirmation"), sMsg, QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes)
		{
			QList<int> lIndexes;
			for(int i = 0; i < lsSelected.size(); i++)
				lIndexes.append(lsSelected[i].row());
			pChild->dataModel()->removeImages(lIndexes);
		}
	}
}

// +-----------------------------------------------------------
void ft::MainWindow::on_actionShowImagesList_triggered(bool bChecked)
{
	ui->dockImages->setVisible(bChecked);
}

// +-----------------------------------------------------------
void ft::MainWindow::on_actionShowImageProperties_triggered(bool bChecked)
{
	ui->dockProperties->setVisible(bChecked);
}

// +-----------------------------------------------------------
void ft::MainWindow::on_actionShowFeatures_triggered(bool bChecked)
{
	if(!bChecked)
	{
		ui->actionShowConnections->setChecked(false);
		ui->actionShowFeatureIDs->setChecked(false);
	}
	updateUI();
}


void  ft::MainWindow::on_actionSpaceEvenly_triggered(){

    ChildWindow *pChild = (ChildWindow*) ui->tabWidget->currentWidget();
    if(!pChild)   return;

//    QModelIndexList     lsSelected = pChild->selectionProxyModel()->selectedRows();
    QList<int>          lIndexes = getIndicesOfSelectedImages(pChild);

    pChild->interpolateLandmarksPositions(lIndexes);
}

// =========================================================================================
// ==================================================================================================
// =========================================================================================

void ft::MainWindow::on_actionShowConnections_triggered(bool bChecked)
{
	if(bChecked && !ui->actionShowFeatures->isChecked())
		ui->actionShowFeatures->setChecked(true);
	updateUI();
}

// +-----------------------------------------------------------
void ft::MainWindow::on_actionShowFeatureIDs_triggered(bool bChecked)
{
	if(bChecked && !ui->actionShowFeatures->isChecked())
		ui->actionShowFeatures->setChecked(true);
	updateUI();
}

// +-----------------------------------------------------------
void ft::MainWindow::on_actionAddFeature_triggered()
{
	ChildWindow *pChild = (ChildWindow*) ui->tabWidget->currentWidget();
	if(!pChild)
		return;

	// The position of the mouse  is stored in this action data  if the action is called from a context menu in the face features  editor (see method FaceWidget::contextMenuEvent)
	QVariant vPos = ui->actionAddFeature->data();
	QPoint oPos;
	if(vPos.isValid())
		oPos = vPos.value<QPoint>();
	else
		oPos = QCursor::pos();

	pChild->addFeature(oPos);
}

// +-----------------------------------------------------------
void ft::MainWindow::on_actionRemoveFeature_triggered()
{
	ChildWindow *pChild = (ChildWindow*) ui->tabWidget->currentWidget();
	if(!pChild)
		return;

	QString sMsg = tr("Do you confirm the removal of the selected facial landmarks? This action can not be undone.");
	QMessageBox::StandardButton oResp = QMessageBox::question(this, tr("Confirmation"), sMsg, QMessageBox::Yes|QMessageBox::No);

	if(oResp == QMessageBox::Yes)
		pChild->removeSelectedFeatures();
}

// +-----------------------------------------------------------
void ft::MainWindow::on_actionConnectFeatures_triggered()
{
	ChildWindow *pChild = (ChildWindow*) ui->tabWidget->currentWidget();
	if(!pChild)
		return;

	pChild->connectFeatures();
}

// +-----------------------------------------------------------
void ft::MainWindow::on_actionDisconnectFeatures_triggered()
{
	ChildWindow *pChild = (ChildWindow*) ui->tabWidget->currentWidget();
	if(!pChild)
		return;

	pChild->disconnectFeatures();
}

// +-----------------------------------------------------------
void ft::MainWindow::showStatusMessage(const QString &sMsg, const int iTimeout)
{
	ui->statusBar->showMessage(sMsg, iTimeout);
}

// +-----------------------------------------------------------
int ft::MainWindow::getFilePageIndex(const QString &sFile)
{
	int iRet = -1;
	for(int iPage = 0; iPage < ui->tabWidget->count(); iPage++)
	{
		ChildWindow* pChild = (ChildWindow*) ui->tabWidget->widget(iPage);
		if(pChild->windowFilePath() == sFile)
		{
			iRet = iPage;
			break;
		}
	}
	return iRet;
}


// +-----------------------------------------------------------
void ft::MainWindow::setImageListSort(QString sType){

    ChildWindow *pChild = (ChildWindow*) ui->tabWidget->currentWidget();
    if (!pChild) return;

    pChild->setImageListSortType(sType);

    if(sType == "sort_az")
    {
        m_pSortButton->setIcon(QIcon(":/icons/sort_az"));
        pChild->setSortMethod(Qt::AscendingOrder);
    }
    else if(sType == "sort_za")
    {
        m_pSortButton->setIcon(QIcon(":/icons/sort_za"));
        pChild->setSortMethod(Qt::DescendingOrder);
    }
    else if (sType == "sort_unsorted"){
        m_pSortButton->setIcon(QIcon(":/icons/unsorted"));
        pChild->setSortMethod(-1);
    }
}

void ft::MainWindow::setImageListView(QString sType){

    ChildWindow *pChild = (ChildWindow*) ui->tabWidget->currentWidget();
    if (!pChild) return;

    pChild->setImageListViewType(sType);

	if(sType == "details")
	{
		m_pViewButton->setIcon(QIcon(":/icons/viewdetails_bw"));
		ui->listImages->setVisible(false);
		ui->treeImages->setVisible(true);
	}
	else if(sType == "icons")
	{
		m_pViewButton->setIcon(QIcon(":/icons/viewicons_bw"));
		ui->treeImages->setVisible(false);
		ui->listImages->setVisible(true);
	}
}

// +-----------------------------------------------------------
void ft::MainWindow::toggleImageListView()
{
	if(ui->treeImages->isVisible())
		setImageListView("icons");
	else
		setImageListView("details");
}

void ft::MainWindow::toggleImageListSort()
{
    ChildWindow *pChild = (ChildWindow*) ui->tabWidget->currentWidget();
    if (!pChild) return;

    QString sType = pChild->getImageListSortType();

	if(sType == "sort_az")
		setImageListSort("sort_za");
	else if (sType == "sort_za")
		setImageListSort("sort_unsorted");
	else if (sType == "sort_unsorted")
        setImageListSort("sort_az");
}

// +-----------------------------------------------------------
void ft::MainWindow::onChildUIUpdated(const QString sImageName, const int iZoomLevel)
{
	// Image file name
	ui->textFileName->setText(sImageName);
	ui->textFileName->moveCursor(QTextCursor::End);
	ui->textFileName->ensureCursorVisible();
			
	// Zoom level
	ui->zoomSlider->blockSignals(true);
	ui->zoomSlider->setValue(iZoomLevel);
	ui->zoomSlider->blockSignals(false);

	updateUI();
}

// +-----------------------------------------------------------
void ft::MainWindow::updateUI()
{
	// Setup the control variables
	ChildWindow *pChild = (ChildWindow*) ui->tabWidget->currentWidget();

	bool bLandmarksPropertiesOpened = pChild != NULL;
	bool bFileOpened = pChild != NULL;
	bool bFileChanged = bFileOpened ? pChild->isWindowModified() : false;
	bool bItemsSelected = bFileOpened && (pChild->selectionModel()->currentIndex().isValid() || pChild->selectionModel()->selectedIndexes().size() > 0);
	bool bFileNotNew = bFileOpened && !pChild->property("new").toBool();

	m_pLandmarkGroupsButton->clear();
    this->ui->menuLandmarksGroups->clear();

	QList<FaceFeatureNode*> lFeats;
	QList<FaceFeatureEdge*> lConns;

	if(bFileOpened){
		lFeats = pChild->getSelectedFeatures();
		lConns = pChild->getSelectedConnections();
	}

	bool bFeaturesSelected      = lFeats.size() > 0;
	bool bConnectionsSelected   = lConns.size() > 0;
	bool bFeaturesConnectable   = lFeats.size() == 2 && lConns.size() == 0;

	// Update the data and selection models
	if(bFileOpened)
	{
        ui->SearchBox->clear();
        ui->SearchBox->setText( pChild->getSearchBoxText());
        ui->listImages->setModel(pChild->dataProxyModel());
        ui->listImages->setSelectionModel(pChild->selectionProxyModel());
        ui->treeImages->setModel(pChild->dataProxyModel());
        ui->treeImages->setSelectionModel(pChild->selectionProxyModel());

        setImageListView(pChild->getImageListViewType());
        setImageListSort(pChild->getImageListSortType());


        pChild->dataModel()->genGroupLandmarksActions(pChild);
        pChild->dataModel()->addGroupLandmarksActions(m_pLandmarkGroupsButton);
        pChild->dataModel()->addGroupLandmarksActions(ui->menuLandmarksGroups);
	}
	else
	{
		ui->listImages->setModel(nullptr);
		ui->treeImages->setModel(nullptr);
	}

	// Update the UI availability
//	ui->actionLandmarksProperties(bLandmarksPropertiesOpened)
	ui->actionSave->setEnabled(bFileChanged);
	ui->actionSaveAs->setEnabled(bFileNotNew);
	ui->actionAddImage->setEnabled(bFileOpened);
	ui->actionRemoveImage->setEnabled(bItemsSelected);
	ui->actionAddFeature->setEnabled(bFileOpened);
	ui->actionRemoveFeature->setEnabled(bFeaturesSelected);
	ui->actionConnectFeatures->setEnabled(bFeaturesConnectable);
	ui->actionDisconnectFeatures->setEnabled(bConnectionsSelected);
	ui->actionFitLandmarks->setEnabled(bItemsSelected);
	ui->actionExportPointsFile->setEnabled(bItemsSelected);
	m_pViewButton->setEnabled(bFileOpened);
	m_pSortButton->setEnabled(bFileOpened);
	ui->zoomSlider->setEnabled(bFileOpened);
	ui->rotationSlider->setEnabled(bFileOpened);

	// Update the tab title and tooltip
	if(bFileOpened)
	{
		QString sTitle = QFileInfo(pChild->windowFilePath()).baseName() + (pChild->isWindowModified() ? "*" : "");
		ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), sTitle);
		if(bFileNotNew) // Complete file path only if the file has been saved before
			ui->tabWidget->setTabToolTip(ui->tabWidget->currentIndex(), pChild->windowFilePath());
	}

	// Display of face features
	if(bFileOpened)
	{
		pChild->setDisplayFaceFeatures(ui->actionShowFeatures->isChecked());
		pChild->setDisplayConnections(ui->actionShowFeatures->isChecked() && ui->actionShowConnections->isChecked());
		pChild->setDisplayFeatureIDs(ui->actionShowFeatures->isChecked() && ui->actionShowFeatureIDs->isChecked());
	}


}

// +-----------------------------------------------------------
void ft::MainWindow::onZoomSliderValueChanged(int iValue)
{
	ChildWindow *pChild = (ChildWindow*) ui->tabWidget->currentWidget();
	if(pChild)
		pChild->setZoomLevel(iValue);
}

// +-----------------------------------------------------------
void ft::MainWindow::onZoomLevelChanged(int iValue)
{
	ui->zoomSlider->blockSignals(true);
	ui->zoomSlider->setValue(iValue);
	ui->zoomSlider->blockSignals(false);
}

// +-----------------------------------------------------------
void ft::MainWindow::onUpdateUI(){
	updateUI();
}

// +-----------------------------------------------------------
void ft::MainWindow::keyPressEvent(QKeyEvent *pEvent)
{
	ChildWindow *pChild = (ChildWindow*) ui->tabWidget->currentWidget();
	if(!pChild)
	{
		QMainWindow::keyPressEvent(pEvent);
		return;
	}

    switch(pEvent->key())
	{
		case Qt::Key_Plus:
			pChild->zoomIn();
			pEvent->accept();
			break;

		case Qt::Key_Minus:
			pChild->zoomOut();
			pEvent->accept();
			break;

		default:
			QMainWindow::keyPressEvent(pEvent);
    }
}

// +-----------------------------------------------------------
ft::ChildWindow* ft::MainWindow::createChildWindow(QString sFileName, bool bModified)
{
	ChildWindow *pChild = new ChildWindow(this);

	// Define the window attributes
	if(!sFileName.length())
	{
		sFileName = QString(tr("%1new face annotation dataset.fad")).arg(m_sLastPathUsed);
		bModified = true;
	}

	pChild->setWindowIcon(QIcon(":/icons/face-dataset"));
	pChild->setWindowFilePath(sFileName);
	pChild->setWindowModified(bModified);

	// Connect to its signals
	connect(pChild, SIGNAL(onUIUpdated(const QString, const int)), this, SLOT(onChildUIUpdated(const QString, const int)));
	connect(pChild, SIGNAL(onDataModified()), this, SLOT(onUpdateUI()));
	connect(pChild, SIGNAL(onFeaturesSelectionChanged()), this, SLOT(onUpdateUI()));

	// Create the context menu for the features editor, using the same actions from the main window
	QMenu *pContextMenu = new QMenu(pChild);
	pContextMenu->addAction(ui->actionAddFeature);
	pContextMenu->addAction(ui->actionRemoveFeature);
	pContextMenu->addAction(ui->actionConnectFeatures);
	pContextMenu->addAction(ui->actionDisconnectFeatures);
	pChild->setContextMenu(pContextMenu);

	// Add the window to the tab widget
	int iIndex = ui->tabWidget->addTab(pChild, pChild->windowIcon(), "");
	ui->tabWidget->setCurrentIndex(iIndex);

	return pChild;
}

// +-----------------------------------------------------------
void ft::MainWindow::destroyChildWindow(ChildWindow *pChild)
{
	int iTabIndex = ui->tabWidget->indexOf(pChild);
	ui->tabWidget->removeTab(iTabIndex);

	disconnect(pChild, SIGNAL(onUIUpdated(const QString, const int)), this, SLOT(onChildUIUpdated(const QString, const int)));
	disconnect(pChild, SIGNAL(onDataModified()), this, SLOT(onUpdateUI()));
	disconnect(pChild, SIGNAL(onFeaturesSelectionChanged()), this, SLOT(onUpdateUI()));

	delete pChild;
}

void ft::MainWindow::on_SearchBox_textEdited(const QString &textToSearch) {

    ChildWindow *pChild = (ChildWindow*) ui->tabWidget->currentWidget();
    if(!pChild )   return;

    pChild->setFilterString(textToSearch);
    pChild->setSearchBoxText(textToSearch);
    ui->SearchBox->setText(textToSearch);
    pChild->setSearchBoxText(textToSearch);
}

QList<int> ft::MainWindow::getIndicesOfSelectedImages(ft::ChildWindow *pChild) {

    QModelIndexList     lsSelected = pChild->selectionProxyModel()->selectedRows();
    QList<int>          lIndexes;

    if(lsSelected.size() > 0){
        for(int i = 0; i < lsSelected.size(); ++i) {
            lIndexes.append(lsSelected[i].row());
        }
    }
    return lIndexes;
}


void ft::MainWindow::setLandmarksGroups(const QString &sType) {

    ChildWindow *pChild = (ChildWindow*) ui->tabWidget->currentWidget();
    if(!pChild )   return;
    pChild->setLanmarksGroupsViz(sType);
}


bool ft::MainWindow::eventFilter(QObject *watched, QEvent *event){

    if (watched == ui->menuBar)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent* mouse_event = dynamic_cast<QMouseEvent*>(event);
            if (mouse_event->button() == Qt::LeftButton)
            {
                dragPosition = mouse_event->globalPos() - ui->menuBar->mapToGlobal(QPoint(0,0));
                return false;
            }
        }
        else if (event->type() == QEvent::MouseMove)
        {
            QMouseEvent* mouse_event = dynamic_cast<QMouseEvent*>(event);
            if (mouse_event->buttons() & Qt::LeftButton)
            {
                move( mouse_event->globalPos() - dragPosition);
                return false;
            }
        }
    }
    return false;
}