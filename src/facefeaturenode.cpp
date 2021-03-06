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

#include "facefeaturenode.h"
#include "facewidget.h"
#include "facefeatureedge.h"
#include "application.h"

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QtWidgets/QGraphicsDropShadowEffect>

// Radius of the drawn node, in pixels
const int ft::FaceFeatureNode::RADIUS = 3;

// +-----------------------------------------------------------
ft::FaceFeatureNode::FaceFeatureNode(int iID, FaceWidget *pFaceWidget)
{
	m_pFaceWidget = pFaceWidget;

    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
	setFlag(ItemIsSelectable);
    setCacheMode(DeviceCoordinateCache);

	setSelected(false);
	setAcceptHoverEvents(true);

	m_iID = iID;
}

// +-----------------------------------------------------------
void ft::FaceFeatureNode::addEdge(FaceFeatureEdge *pEdge)
{
	m_lEdges.append(pEdge);
    pEdge->adjust();
}

// +-----------------------------------------------------------
void ft::FaceFeatureNode::removeEdge(FaceFeatureEdge *pEdge)
{
	m_lEdges.removeOne(pEdge);
}

// +-----------------------------------------------------------
QList<ft::FaceFeatureEdge *> ft::FaceFeatureNode::edges() const
{
    return m_lEdges;
}

// +-----------------------------------------------------------
ft::FaceFeatureEdge *ft::FaceFeatureNode::getEdgeTo(const FaceFeatureNode *pNode) const
{
	foreach(FaceFeatureEdge *pEdge, m_lEdges)
	{
		if((pEdge->sourceNode() == this && pEdge->targetNode() == pNode) ||
		   (pEdge->sourceNode() == pNode && pEdge->targetNode() == this))
		{
			return pEdge;
		}
	}
	return NULL;
}

// +----------------------------number-------------------------------
QRectF ft::FaceFeatureNode::boundingRect() const
{
    int R = getRadius();
	if(m_pFaceWidget->displayFeatureIDs())
	{
		QString sID = QString::number(m_iID);
		int iHeight = m_pFaceWidget->fontMetrics().height();
		int iWidth = m_pFaceWidget->fontMetrics().width(sID);
		return QRectF(-(iWidth + R), -(iHeight + R), 2 * R + iWidth, 2 * R + iHeight);
	}
	else
    {
        return QRectF(-R, -R, 2 * R, 2 * R);
    }
}

QRectF ft::FaceFeatureNode::boundingRect(bool displayFeaturesIds) const
{
    int R = getRadius();
    if (displayFeaturesIds)
    {
        QString sID = QString::number(m_iID);
        int iHeight = m_pFaceWidget->fontMetrics().height();
        int iWidth = m_pFaceWidget->fontMetrics().width(sID);
        return QRectF(-(iWidth + R), -(iHeight + R), 2 * R + iWidth, 2 * R + iHeight);
    } else {

        return QRectF(-R, -R, 2 * R, 2 * R);
    }

}
// +-----------------------------------------------------------
void ft::FaceFeatureNode::paint(QPainter *pPainter, const QStyleOptionGraphicsItem *pOption, QWidget *pWidget)
{
    if (!isVisible)       return;

    Q_UNUSED(pOption);
    Q_UNUSED(pWidget);

    QBrush oBrush;
    oBrush.setStyle(Qt::SolidPattern);

    if(m_pFaceWidget->displayFeatureIDs())
    {
        QPainterPath path;
//        QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
//
//        effect->setBlurRadius(8);

        path.addRoundedRect(boundingRect(true), 5, 5);
        pPainter->setBrush(oBrush);
        pPainter->fillPath(path, QColor(255,255,255,155));

        QString sID = QString::number(m_iID);
        oBrush.setColor(QColor(Qt::black));
        pPainter->drawText(boundingRect(true), sID);
    }

    if(isSelected()){
        pPainter->setPen(QPen(Qt::black, 1));
        oBrush.setColor(QColor(Qt::red));
    }
    else{
        pPainter->setPen(QPen(Qt::black, 1));
        oBrush.setColor(QColor(Qt::yellow));
    }

    pPainter->setBrush(oBrush);
    pPainter->setRenderHint(QPainter::Antialiasing);
    pPainter->drawEllipse(boundingRect(false));
}

// +-----------------------------------------------------------
QVariant ft::FaceFeatureNode::itemChange(GraphicsItemChange eChange, const QVariant &oValue)
{
	QString sText;
    switch(eChange)
	{
		case ItemPositionHasChanged:
			foreach(FaceFeatureEdge *pEdge, m_lEdges)
				pEdge->adjust();

			sText = QApplication::translate("FaceFeatureNode", "Node: %1 Position: (%2, %3)").arg(m_iID).arg(QString::number(pos().x(), 'f', 2)).arg(QString::number(pos().y(), 'f', 2));
			FtApplication::instance()->showStatusMessage(sText, 0);

			if(!data(0).toBool()) // This flag is used in ChildWindow::refreshFeaturesInWidget
				m_pFaceWidget->faceFeatureMoved(this);
			break;
	
		default:
			break;
    };

    return QGraphicsItem::itemChange(eChange, oValue);
}

// +-----------------------------------------------------------
void ft::FaceFeatureNode::hoverEnterEvent(QGraphicsSceneHoverEvent *pEvent)
{
	QString sText = QApplication::translate("FaceFeatureNode", "Node: %1 Position: (%2, %3)").arg(m_iID).arg(QString::number(pos().x(), 'f', 2)).arg(QString::number(pos().y(), 'f', 2));
	FtApplication::instance()->showStatusMessage(sText, 0);
	QGraphicsItem::hoverEnterEvent(pEvent);
}

// +-----------------------------------------------------------
void ft::FaceFeatureNode::hoverLeaveEvent(QGraphicsSceneHoverEvent *pEvent)
{
	FtApplication::instance()->showStatusMessage("");
	QGraphicsItem::hoverLeaveEvent(pEvent);
}

// +-----------------------------------------------------------
int ft::FaceFeatureNode::getID() const
{
	return m_iID;
}

// +-----------------------------------------------------------
void ft::FaceFeatureNode::setID(int iID)
{
	m_iID = iID;
}

int ft::FaceFeatureNode::getRadius() const{

    return radius;

}

void ft::FaceFeatureNode::setRadius(int r) {

    radius = r;

}
