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

#ifndef FACEWIDGET_H
#define FACEWIDGET_H

#include <algorithm>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QMouseEvent>
#include <QMenu>
#include <QAction>

#include "facefeaturenode.h"
#include "facefeatureedge.h"

namespace Ui {
    class MainWindow;
}

namespace ft
{
    /**
     * Implements the widget used to display face images and to edit facial features by dragging its points.
     */
    class FaceWidget : public QGraphicsView
    {
        Q_OBJECT
	public:
		static const double ZOOM_IN_STEP;/** Scale value for the zoom in step. */
		static const double ZOOM_OUT_STEP;/** Scale value for the zoom out step. */

		static const double ROTATE_LEFT_STEP;/** Rotate value for the rotate left step. */
		static const double ROTATE_RIGHT_STEP;/** Rotate value for the rotate right step. */

		static const double ZOOM_IN_FEATURES_STEP;/** Scale value for features radius. */
		static const double ZOOM_OUT_FEATURES_STEP;/** Scale value for features radius. */

		static const double BRIGHTNESS_DOWN_STEP;
		static const double BRIGHTNESS_UP_STEP;

		/** * Class constructor.  * @param pParent Instance of the parent widget. 	 */
		FaceWidget(QWidget *pParent = 0);
		virtual ~FaceWidget();

		/**
		 * Updates the pixmap displayed at the central area.
		 * @param oPixmap Reference for a QPixmap with the new pixmap to display.
		 */
		void    setPixmap       ( const QPixmap &oPixmap );
		double  getScaleFactor  ( ) const; /// Gets the currently applied scale factor on the image displayed.  @return Double with the currently applied scale factor.
		void    setScaleFactor  ( const double dScaleFactor );/// Sets the scale factor of the image displayed.  @param dScaleFactor Double with the new scale factor to be applied. It must be  in the interval [0.10, 13.0].
	    void    zoomIn          ( );/// Performs one step of zoom in.
		void    zoomOut         ( );/// Performs one step of zoom out.
		void    brightnessUp    ( );
		void    brightnessDown  ( );

        double  getRotateFactor() const;
        void    setRotateFactor(const double dRotateFactor);
		void    rotateLeft();
		void    rotateRight();

		/**
		 * Queries the list of existing face feature nodes. Optionally, guarantee that the
		 * correct number of face features are available in the editor.
		 * @param iNumFeats Integer with the expected number of face features in the editor.
		 * If -1 is provided (the default), the method simply returns the current set of 
		 * face features without performing any checking. If the value is different than -1,
		 * the method will create or remove face features to guarantee that given number of
		 * features.
		 * @param Const reference to the QList of existing nodes.
		 */
		const QList<FaceFeatureNode*>& getFaceFeatures(int iNumFeats = -1);

		/**
		 * Queries the selected face feature nodes.
		 * @return QList with the pointers to the selected face feature nodes.
		 */
		QList<FaceFeatureNode*> getSelectedFeatures() const;

		/**
		 * Queries the selected face feature edges.
		 * @return QList with the pointers to the selected face feature edges.
		 */
		QList<FaceFeatureEdge*> getSelectedConnections() const;

		/**
		 * Adds a new face feature node in the given position.
		 * @param oPos A QPoint with the coordinates for the new node. If not provided, (0, 0) is assumed.
		 * @param bGlobal Bool indicating if the coordinate of the position is referenced to the global
		 * coordinate system or to the scene coordinate system. The default is false (indicating that is related
		 * to the scene coordinate system).
		 * @return Pointer to the instance of the newly added face feature node.
		 */
		FaceFeatureNode* addFaceFeature(const QPoint &oPos = QPoint(), bool bGlobal = false);

		/**
		 * Removes an existing face feature node.
		 * @param pNode Pointer to the instance of the face feature node to remove.
		 */
		void removeFaceFeature(FaceFeatureNode* pNode);

		/**
		 * Adds a new face feature edge connecting two existing nodes.
		 * @param pSource Pointer to the instance of the first face feature node.
		 * @param pTarget Pointer to the instance of the second face feature node.
		 * @return Pointer to the instance of the newly added face feature edge connecting the two nodes.
		 */
		FaceFeatureEdge* connectFaceFeatures(FaceFeatureNode* pSource, FaceFeatureNode* pTarget);

		/**
		* Adds a new face feature edge connecting two existing nodes, based on their IDs.
		* @param iSource Integer with the ID of the first face feature node.
		* @param iTarget Integer with the ID of the second face feature node.
		* @return Pointer to the instance of the newly added face feature edge connecting the two nodes.
		*/
		FaceFeatureEdge* connectFaceFeatures(int iSource, int iTarget);

		/**
		 * Removes the face feature edge connecting two existing nodes.
		 * @param pSource Pointer to the instance of the first face feature node.
		 * @param pTarget Pointer to the instance of the second face feature node.
		 */
		void disconnectFaceFeatures(FaceFeatureNode* pSource, FaceFeatureNode* pTarget);

		/**
		 * Removes an existing face feature edge.
		 * @param pEdge Pointer to the instance of the face feature edge to remove.
		 */
		void removeConnection(FaceFeatureEdge* pEdge);

		/**
		 * Captures the indication that a face feature node has been moved by the user.
		 * @param pNode Instance of the Face Feature Node that has been moved.
		 */
		void faceFeatureMoved(FaceFeatureNode *pNode);

		/**
		 * Indicates if the face feature nodes are on display.
		 * @return Boolean indicating if the face feature nodes are being displayed or not.
		 */
		bool displayFaceFeatures() const;

		/**
		 * Updates the indication on if the face feature nodes shall be displayed or not.
		 * @param bValue Boolean with the new value (true means show, false means hide).
		 */
		void setDisplayFaceFeatures(const bool bValue);

		/**
		 * Indicates if the face feature edges are on display.
		 * @return Boolean indicating if the face feature edges are being displayed or not.
		 */
		bool displayConnections() const;

		/**
		 * Updates the indication on if the face feature edges shall be displayed or not.
		 * @param bValue Boolean with the new value (true means show, false means hide).
		 */
		void setDisplayConnections(const bool bValue);

		/**
		 * Indicates if the identifiers of the face feature nodes are on display.
		 * @return Boolean indicating if the identifiers of the face feature nodes are being displayed or not.
		 */
		bool displayFeatureIDs() const;

		/**
		 * Updates the indication on if the identifiers of the face feature nodes shall be displayed or not.
		 * @param bValue Boolean with the new value (true means show, false means hide).
		 */
		void setDisplayFeatureIDs(const bool bValue);

		/**
		 * Sets the menu to be displayed upon events of context menu on the face features editor.
		 * The actions used in the menu must be controlled by the caller.
		 * @param pMenu Instance of the QMenu to be used for the context of the editor.
		 */
		void setContextMenu(QMenu *pMenu);

	public:

		/** Constant with the number of face features. */
		const static int NUM_FACE_FEATURES;

	signals:

		/**
		 * Signal to indicate that the scale of the display image has changed from direct user interaction
		 * with the widget (that is, a call to setScaleFactor does not emit this signal).
		 * @param dScaleFactor Double with the new scale factor.
		 */
		void onScaleFactorChanged (const double dScaleFactor);
		void onRotateFactorChanged(const double dRotateFactor);

		/**
		 * Signal to indicate that the face features changed somehow: a face feature node was added, removed or moved
		 * or a connection between two face feature nodes was created or removed.
		 */
		void onFaceFeaturesChanged();

		/**
		 * Signal to indicate that face features were selected or unselected in the editor.
		 * The selection can be queried through getSelectedFeatures() and getSelectedConnections().
		 */
		void onFaceFeaturesSelectionChanged();

	protected:

	#ifndef QT_NO_WHEELEVENT
		/**
		 * Captures and handles the mouse wheel events to automate user interactions.
		 * @param pEvent Pointer to a QWheelEvent with the mouse event.
		 */
		void wheelEvent(QWheelEvent *pEvent) Q_DECL_OVERRIDE;
	#endif

		/**
		 * Captures the press of the mouse button to notify changes in the face feature editor.
		 * @param pEvent Instance of the QMouseEvent with the event data.
		 */
		void mousePressEvent(QMouseEvent* pEvent);

		/**
		 * Captures the release of the mouse button to notify changes in the face feature editor.
		 * @param pEvent Instance of the QMouseEvent with the event data.
		 */
		void mouseReleaseEvent(QMouseEvent *pEvent);

		/**  Scales the widget view to emulate a zoom behaviour by the given factor. * @param dFactorBy Double with the scale to be added/removed. 		 */
		void scaleViewBy(double dFactorBy);
        void rotateViewBy(const double step);
        void addToFeaturesRadius(int add2Radius);
        // changes radius  of each fature  in pixels
		void createFaceFeatures(); ///Creates the face feature nodes and edges to be used by the face features editor.

		/**
		 * Captures the context menu event.
		 * @param pEvent Instance of a QContextMenuEvent with the event data.
		 */
		void contextMenuEvent(QContextMenuEvent *pEvent) Q_DECL_OVERRIDE;

	protected slots:
		void onSelectionChanged(); /// Captures the signal of selection changed in the graphics scene.

	private:

        template<class T>
        constexpr const T& clamp( const T& v, const T& lo, const T& hi );

		bool m_bFeaturesMoved; /// Indication about the feature nodes being moved.
		bool m_bSelectionChanged; /// Indication about the selection of feature nodes being changed.
		QGraphicsScene *m_pScene; /// The scene used to render the widget contents.
		QGraphicsPixmapItem *m_pPixmapItem; /// Pixmap item used to display the face image
		double m_dRotateFactor; ///  The current applied rotate factor.
        double m_dScaleFactor; ///  The current applied scale factor.
        double m_dFeaturesRadiusAdd;
		QList<FaceFeatureNode*> m_lFaceFeatures; /// List of nodes used to edit the coordinates of facial features
		QList<FaceFeatureEdge*> m_lConnections; /// List of edges connecting two feature nodes.
		bool m_bDisplayFaceFeatures; ///  Indicates if the face feature nodes should be displayed or not
		bool m_bDisplayConnections; /// Indicates if the face feature edges should be displayed or not
		bool m_bDisplayFeatureIDs;  /// Indicates if the IDs of the face feature nodes should be displayed or not
		QMenu *m_pContextMenu; ///  Context menu for the face feature editor.


        void scaleBrightnessBy(const double step);
    };
};


#endif //FACEWIDGET_H
