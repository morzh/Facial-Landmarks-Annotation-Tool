/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionAbout;
    QAction *actionOpen;
    QAction *actionNew;
    QAction *actionSave;
    QAction *actionSaveAs;
    QAction *actionProject;
    QAction *actionAddImage;
    QAction *actionRemoveImage;
    QAction *actionShowImagesList;
    QAction *actionShowImageProperties;
    QAction *actionShowFeatures;
    QAction *actionShowConnections;
    QAction *actionShowFeatureIDs;
    QAction *actionAddFeature;
    QAction *actionRemoveFeature;
    QAction *actionConnectFeatures;
    QAction *actionDisconnectFeatures;
    QAction *actionFitLandmarks;
    QAction *actionConfigure;
    QAction *actionExportPointsFile;
    QAction *actionShowFaceOvalLow;
    QAction *actionShowFaceOvalUpper;
    QAction *actionBrowRight;
    QAction *actionBrowLeft;
    QAction *actionEyeRight;
    QAction *actionEyeLeft;
    QAction *actionNoseRidge;
    QAction *actionNoseShape;
    QAction *actionMouthOuter;
    QAction *actionMouthInner;
    QAction *actionLandmarksProperties;
    QAction *actionMakeLandmarksEvenlySpaced;
    QAction *actionSpaceEvenly;
    QAction *actionUnod;
    QAction *actionUndo;
    QAction *actionRedo;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QMenu *menuShow;
    QMenu *menuWindows;
    QMenu *menu_Image_Elements;
    QMenu *menuLandmarks_Groups;
    QMenu *menuEdit;
    QMenu *menu_Images;
    QMenu *menu_Facial_Landmarks;
    QMenu *menuTools;
    QMenu *menu_CSIRO_Face_Analysis_SDK;
    QToolBar *fileToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockProperties;
    QWidget *Content;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *labelPath;
    QTextEdit *textFileName;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_Zoom;
    QVBoxLayout *verticalLayout_2;
    QSlider *zoomSlider;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label1000;
    QSpacerItem *horizontalSpacer;
    QLabel *label100;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label10;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QVBoxLayout *verticalLayout_5;
    QSlider *rotationSlider;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QDockWidget *dockImages;
    QWidget *Content_2;
    QGridLayout *gridLayout;
    QToolBar *imagesToolbar;
    QListView *listImages;
    QTreeView *treeImages;
    QLineEdit *SearchBox;
    QToolBar *editToolBar;
    QToolBar *viewToolBar;
    QToolBar *toolsToolBar;
    QToolBar *helpTollBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1121, 886);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/resources/icons/information.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/resources/icons/open-bw2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/resources/icons/new-bw2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon2);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/resources/icons/save-bw.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon3);
        actionSaveAs = new QAction(MainWindow);
        actionSaveAs->setObjectName(QStringLiteral("actionSaveAs"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/resources/icons/saveas.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSaveAs->setIcon(icon4);
        actionProject = new QAction(MainWindow);
        actionProject->setObjectName(QStringLiteral("actionProject"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icons/resources/icons/help-bw.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionProject->setIcon(icon5);
        actionAddImage = new QAction(MainWindow);
        actionAddImage->setObjectName(QStringLiteral("actionAddImage"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/icons/resources/icons/plus-bw.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddImage->setIcon(icon6);
        actionRemoveImage = new QAction(MainWindow);
        actionRemoveImage->setObjectName(QStringLiteral("actionRemoveImage"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/icons/resources/icons/minus-bw.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRemoveImage->setIcon(icon7);
        actionShowImagesList = new QAction(MainWindow);
        actionShowImagesList->setObjectName(QStringLiteral("actionShowImagesList"));
        actionShowImagesList->setCheckable(true);
        actionShowImagesList->setChecked(true);
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/icons/resources/icons/image-list.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionShowImagesList->setIcon(icon8);
        actionShowImageProperties = new QAction(MainWindow);
        actionShowImageProperties->setObjectName(QStringLiteral("actionShowImageProperties"));
        actionShowImageProperties->setCheckable(true);
        actionShowImageProperties->setChecked(true);
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/icons/resources/icons/image-properties-bw.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionShowImageProperties->setIcon(icon9);
        actionShowFeatures = new QAction(MainWindow);
        actionShowFeatures->setObjectName(QStringLiteral("actionShowFeatures"));
        actionShowFeatures->setCheckable(true);
        actionShowFeatures->setChecked(true);
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/icons/resources/icons/features-bw.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionShowFeatures->setIcon(icon10);
        actionShowConnections = new QAction(MainWindow);
        actionShowConnections->setObjectName(QStringLiteral("actionShowConnections"));
        actionShowConnections->setCheckable(true);
        actionShowConnections->setChecked(true);
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/icons/resources/icons/links-bw.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionShowConnections->setIcon(icon11);
        actionShowFeatureIDs = new QAction(MainWindow);
        actionShowFeatureIDs->setObjectName(QStringLiteral("actionShowFeatureIDs"));
        actionShowFeatureIDs->setCheckable(true);
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/icons/resources/icons/feature-ids-bw.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionShowFeatureIDs->setIcon(icon12);
        actionAddFeature = new QAction(MainWindow);
        actionAddFeature->setObjectName(QStringLiteral("actionAddFeature"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/icons/resources/icons/add-feature-bw.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddFeature->setIcon(icon13);
        actionRemoveFeature = new QAction(MainWindow);
        actionRemoveFeature->setObjectName(QStringLiteral("actionRemoveFeature"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/icons/resources/icons/remove-feature-bw.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRemoveFeature->setIcon(icon14);
        actionConnectFeatures = new QAction(MainWindow);
        actionConnectFeatures->setObjectName(QStringLiteral("actionConnectFeatures"));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/icons/resources/icons/connect-bw.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnectFeatures->setIcon(icon15);
        actionDisconnectFeatures = new QAction(MainWindow);
        actionDisconnectFeatures->setObjectName(QStringLiteral("actionDisconnectFeatures"));
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/icons/resources/icons/disconnect-bw.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDisconnectFeatures->setIcon(icon16);
        actionFitLandmarks = new QAction(MainWindow);
        actionFitLandmarks->setObjectName(QStringLiteral("actionFitLandmarks"));
        QIcon icon17;
        icon17.addFile(QStringLiteral(":/icons/fat"), QSize(), QIcon::Normal, QIcon::Off);
        actionFitLandmarks->setIcon(icon17);
        actionConfigure = new QAction(MainWindow);
        actionConfigure->setObjectName(QStringLiteral("actionConfigure"));
        actionExportPointsFile = new QAction(MainWindow);
        actionExportPointsFile->setObjectName(QStringLiteral("actionExportPointsFile"));
        actionExportPointsFile->setIcon(icon9);
        actionShowFaceOvalLow = new QAction(MainWindow);
        actionShowFaceOvalLow->setObjectName(QStringLiteral("actionShowFaceOvalLow"));
        actionShowFaceOvalLow->setCheckable(true);
        actionShowFaceOvalLow->setChecked(true);
        actionShowFaceOvalUpper = new QAction(MainWindow);
        actionShowFaceOvalUpper->setObjectName(QStringLiteral("actionShowFaceOvalUpper"));
        actionShowFaceOvalUpper->setCheckable(true);
        actionShowFaceOvalUpper->setChecked(true);
        actionBrowRight = new QAction(MainWindow);
        actionBrowRight->setObjectName(QStringLiteral("actionBrowRight"));
        actionBrowRight->setCheckable(true);
        actionBrowRight->setChecked(true);
        actionBrowLeft = new QAction(MainWindow);
        actionBrowLeft->setObjectName(QStringLiteral("actionBrowLeft"));
        actionBrowLeft->setCheckable(true);
        actionBrowLeft->setChecked(true);
        actionEyeRight = new QAction(MainWindow);
        actionEyeRight->setObjectName(QStringLiteral("actionEyeRight"));
        actionEyeRight->setCheckable(true);
        actionEyeRight->setChecked(true);
        actionEyeLeft = new QAction(MainWindow);
        actionEyeLeft->setObjectName(QStringLiteral("actionEyeLeft"));
        actionEyeLeft->setCheckable(true);
        actionEyeLeft->setChecked(true);
        actionNoseRidge = new QAction(MainWindow);
        actionNoseRidge->setObjectName(QStringLiteral("actionNoseRidge"));
        actionNoseRidge->setCheckable(true);
        actionNoseRidge->setChecked(true);
        actionNoseShape = new QAction(MainWindow);
        actionNoseShape->setObjectName(QStringLiteral("actionNoseShape"));
        actionNoseShape->setCheckable(true);
        actionNoseShape->setChecked(true);
        actionMouthOuter = new QAction(MainWindow);
        actionMouthOuter->setObjectName(QStringLiteral("actionMouthOuter"));
        actionMouthOuter->setCheckable(true);
        actionMouthOuter->setChecked(true);
        actionMouthInner = new QAction(MainWindow);
        actionMouthInner->setObjectName(QStringLiteral("actionMouthInner"));
        actionMouthInner->setCheckable(true);
        actionMouthInner->setChecked(true);
        actionLandmarksProperties = new QAction(MainWindow);
        actionLandmarksProperties->setObjectName(QStringLiteral("actionLandmarksProperties"));
        actionMakeLandmarksEvenlySpaced = new QAction(MainWindow);
        actionMakeLandmarksEvenlySpaced->setObjectName(QStringLiteral("actionMakeLandmarksEvenlySpaced"));
        QIcon icon18;
        icon18.addFile(QStringLiteral(":/icons/resources/icons/evenlyspaced-bw.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMakeLandmarksEvenlySpaced->setIcon(icon18);
        actionSpaceEvenly = new QAction(MainWindow);
        actionSpaceEvenly->setObjectName(QStringLiteral("actionSpaceEvenly"));
        actionSpaceEvenly->setIcon(icon18);
        actionUnod = new QAction(MainWindow);
        actionUnod->setObjectName(QStringLiteral("actionUnod"));
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setIconSize(QSize(24, 24));
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setDocumentMode(true);
        tabWidget->setTabsClosable(true);
        tabWidget->setMovable(true);
        tabWidget->setTabBarAutoHide(false);

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1121, 19));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuFile->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuHelp->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
        menuShow = new QMenu(menuBar);
        menuShow->setObjectName(QStringLiteral("menuShow"));
        menuShow->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
        menuWindows = new QMenu(menuShow);
        menuWindows->setObjectName(QStringLiteral("menuWindows"));
        menu_Image_Elements = new QMenu(menuShow);
        menu_Image_Elements->setObjectName(QStringLiteral("menu_Image_Elements"));
        menu_Image_Elements->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
        menuLandmarks_Groups = new QMenu(menuShow);
        menuLandmarks_Groups->setObjectName(QStringLiteral("menuLandmarks_Groups"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuEdit->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
        menu_Images = new QMenu(menuEdit);
        menu_Images->setObjectName(QStringLiteral("menu_Images"));
        menu_Images->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
        menu_Facial_Landmarks = new QMenu(menuEdit);
        menu_Facial_Landmarks->setObjectName(QStringLiteral("menu_Facial_Landmarks"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuTools->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
        menu_CSIRO_Face_Analysis_SDK = new QMenu(menuTools);
        menu_CSIRO_Face_Analysis_SDK->setObjectName(QStringLiteral("menu_CSIRO_Face_Analysis_SDK"));
        MainWindow->setMenuBar(menuBar);
        fileToolBar = new QToolBar(MainWindow);
        fileToolBar->setObjectName(QStringLiteral("fileToolBar"));
        fileToolBar->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
        fileToolBar->setIconSize(QSize(32, 32));
        MainWindow->addToolBar(Qt::TopToolBarArea, fileToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        dockProperties = new QDockWidget(MainWindow);
        dockProperties->setObjectName(QStringLiteral("dockProperties"));
        dockProperties->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
        Content = new QWidget();
        Content->setObjectName(QStringLiteral("Content"));
        verticalLayout_7 = new QVBoxLayout(Content);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        labelPath = new QLabel(Content);
        labelPath->setObjectName(QStringLiteral("labelPath"));
        QFont font;
        font.setPointSize(12);
        labelPath->setFont(font);

        horizontalLayout->addWidget(labelPath);

        textFileName = new QTextEdit(Content);
        textFileName->setObjectName(QStringLiteral("textFileName"));
        textFileName->setMaximumSize(QSize(16777215, 25));
        textFileName->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textFileName->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textFileName->setUndoRedoEnabled(false);
        textFileName->setLineWrapMode(QTextEdit::NoWrap);
        textFileName->setReadOnly(true);
        textFileName->setAcceptRichText(false);
        textFileName->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        textFileName->setPlaceholderText(QStringLiteral(""));

        horizontalLayout->addWidget(textFileName);


        verticalLayout_3->addLayout(horizontalLayout);


        verticalLayout_7->addLayout(verticalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_Zoom = new QLabel(Content);
        label_Zoom->setObjectName(QStringLiteral("label_Zoom"));
        label_Zoom->setFont(font);

        horizontalLayout_4->addWidget(label_Zoom);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        zoomSlider = new QSlider(Content);
        zoomSlider->setObjectName(QStringLiteral("zoomSlider"));
        zoomSlider->setEnabled(false);
        zoomSlider->setFont(font);
        zoomSlider->setMinimum(1);
        zoomSlider->setMaximum(21);
        zoomSlider->setSingleStep(1);
        zoomSlider->setPageStep(1);
        zoomSlider->setValue(11);
        zoomSlider->setSliderPosition(11);
        zoomSlider->setOrientation(Qt::Horizontal);
        zoomSlider->setTickPosition(QSlider::TicksBelow);
        zoomSlider->setTickInterval(0);

        verticalLayout_2->addWidget(zoomSlider);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetMinimumSize);
        label1000 = new QLabel(Content);
        label1000->setObjectName(QStringLiteral("label1000"));
        label1000->setMinimumSize(QSize(45, 0));
        label1000->setMaximumSize(QSize(45, 16777215));

        horizontalLayout_3->addWidget(label1000);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        label100 = new QLabel(Content);
        label100->setObjectName(QStringLiteral("label100"));
        label100->setMinimumSize(QSize(45, 0));
        label100->setMaximumSize(QSize(45, 16777215));
        label100->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label100);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        label10 = new QLabel(Content);
        label10->setObjectName(QStringLiteral("label10"));
        label10->setMinimumSize(QSize(45, 0));
        label10->setMaximumSize(QSize(45, 16777215));
        label10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label10);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout_2);


        verticalLayout_7->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label = new QLabel(Content);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        horizontalLayout_5->addWidget(label);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        rotationSlider = new QSlider(Content);
        rotationSlider->setObjectName(QStringLiteral("rotationSlider"));
        rotationSlider->setEnabled(false);
        rotationSlider->setAutoFillBackground(true);
        rotationSlider->setMinimum(-180);
        rotationSlider->setMaximum(180);
        rotationSlider->setOrientation(Qt::Horizontal);
        rotationSlider->setInvertedAppearance(false);

        verticalLayout_5->addWidget(rotationSlider);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_3 = new QLabel(Content);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_6->addWidget(label_3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        label_4 = new QLabel(Content);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_6->addWidget(label_4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        label_2 = new QLabel(Content);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_6->addWidget(label_2);


        verticalLayout_5->addLayout(horizontalLayout_6);


        horizontalLayout_5->addLayout(verticalLayout_5);


        verticalLayout_7->addLayout(horizontalLayout_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer);

        dockProperties->setWidget(Content);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockProperties);
        dockImages = new QDockWidget(MainWindow);
        dockImages->setObjectName(QStringLiteral("dockImages"));
        dockImages->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
        Content_2 = new QWidget();
        Content_2->setObjectName(QStringLiteral("Content_2"));
        gridLayout = new QGridLayout(Content_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(3);
        gridLayout->setVerticalSpacing(6);
        gridLayout->setContentsMargins(3, 3, 3, 3);
        imagesToolbar = new QToolBar(Content_2);
        imagesToolbar->setObjectName(QStringLiteral("imagesToolbar"));
        imagesToolbar->setIconSize(QSize(24, 24));
        imagesToolbar->setFloatable(false);

        gridLayout->addWidget(imagesToolbar, 1, 0, 1, 1);

        listImages = new QListView(Content_2);
        listImages->setObjectName(QStringLiteral("listImages"));
        listImages->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listImages->setSelectionMode(QAbstractItemView::ExtendedSelection);
        listImages->setSelectionBehavior(QAbstractItemView::SelectRows);
        listImages->setViewMode(QListView::IconMode);
        listImages->setSelectionRectVisible(false);

        gridLayout->addWidget(listImages, 2, 0, 1, 1);

        treeImages = new QTreeView(Content_2);
        treeImages->setObjectName(QStringLiteral("treeImages"));
        treeImages->setEditTriggers(QAbstractItemView::AllEditTriggers);
        treeImages->setSelectionMode(QAbstractItemView::ExtendedSelection);
        treeImages->header()->setDefaultSectionSize(150);

        gridLayout->addWidget(treeImages, 3, 0, 1, 1);

        SearchBox = new QLineEdit(Content_2);
        SearchBox->setObjectName(QStringLiteral("SearchBox"));
        SearchBox->setFrame(true);
        SearchBox->setClearButtonEnabled(true);

        gridLayout->addWidget(SearchBox, 4, 0, 1, 1);

        dockImages->setWidget(Content_2);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockImages);
        editToolBar = new QToolBar(MainWindow);
        editToolBar->setObjectName(QStringLiteral("editToolBar"));
        editToolBar->setIconSize(QSize(32, 32));
        MainWindow->addToolBar(Qt::TopToolBarArea, editToolBar);
        viewToolBar = new QToolBar(MainWindow);
        viewToolBar->setObjectName(QStringLiteral("viewToolBar"));
        viewToolBar->setIconSize(QSize(32, 32));
        MainWindow->addToolBar(Qt::TopToolBarArea, viewToolBar);
        toolsToolBar = new QToolBar(MainWindow);
        toolsToolBar->setObjectName(QStringLiteral("toolsToolBar"));
        toolsToolBar->setIconSize(QSize(32, 32));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolsToolBar);
        helpTollBar = new QToolBar(MainWindow);
        helpTollBar->setObjectName(QStringLiteral("helpTollBar"));
        helpTollBar->setIconSize(QSize(32, 32));
        MainWindow->addToolBar(Qt::TopToolBarArea, helpTollBar);
#ifndef QT_NO_SHORTCUT
        labelPath->setBuddy(textFileName);
        label_Zoom->setBuddy(zoomSlider);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(textFileName, listImages);
        QWidget::setTabOrder(listImages, treeImages);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuShow->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addSeparator();
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSaveAs);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionProject);
        menuHelp->addSeparator();
        menuHelp->addAction(actionAbout);
        menuShow->addAction(menuWindows->menuAction());
        menuShow->addSeparator();
        menuShow->addAction(menu_Image_Elements->menuAction());
        menuShow->addAction(menuLandmarks_Groups->menuAction());
        menuWindows->addAction(actionShowImageProperties);
        menuWindows->addAction(actionShowImagesList);
        menu_Image_Elements->addAction(actionShowFeatures);
        menu_Image_Elements->addAction(actionShowConnections);
        menu_Image_Elements->addAction(actionShowFeatureIDs);
        menuLandmarks_Groups->addAction(actionShowFaceOvalLow);
        menuLandmarks_Groups->addAction(actionShowFaceOvalUpper);
        menuLandmarks_Groups->addSeparator();
        menuLandmarks_Groups->addAction(actionBrowRight);
        menuLandmarks_Groups->addAction(actionBrowLeft);
        menuLandmarks_Groups->addSeparator();
        menuLandmarks_Groups->addAction(actionEyeRight);
        menuLandmarks_Groups->addAction(actionEyeLeft);
        menuLandmarks_Groups->addSeparator();
        menuLandmarks_Groups->addAction(actionNoseRidge);
        menuLandmarks_Groups->addAction(actionNoseShape);
        menuLandmarks_Groups->addSeparator();
        menuLandmarks_Groups->addAction(actionMouthOuter);
        menuLandmarks_Groups->addAction(actionMouthInner);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addAction(menu_Images->menuAction());
        menuEdit->addSeparator();
        menuEdit->addAction(menu_Facial_Landmarks->menuAction());
        menuEdit->addAction(actionLandmarksProperties);
        menu_Images->addAction(actionAddImage);
        menu_Images->addAction(actionRemoveImage);
        menu_Facial_Landmarks->addAction(actionAddFeature);
        menu_Facial_Landmarks->addAction(actionRemoveFeature);
        menu_Facial_Landmarks->addSeparator();
        menu_Facial_Landmarks->addAction(actionConnectFeatures);
        menu_Facial_Landmarks->addAction(actionDisconnectFeatures);
        menu_Facial_Landmarks->addAction(actionSpaceEvenly);
        menuTools->addAction(menu_CSIRO_Face_Analysis_SDK->menuAction());
        menu_CSIRO_Face_Analysis_SDK->addAction(actionFitLandmarks);
        menu_CSIRO_Face_Analysis_SDK->addAction(actionExportPointsFile);
        menu_CSIRO_Face_Analysis_SDK->addSeparator();
        menu_CSIRO_Face_Analysis_SDK->addAction(actionConfigure);
        fileToolBar->addAction(actionNew);
        fileToolBar->addSeparator();
        fileToolBar->addAction(actionOpen);
        fileToolBar->addAction(actionSave);
        imagesToolbar->addAction(actionAddImage);
        imagesToolbar->addAction(actionRemoveImage);
        editToolBar->addAction(actionAddFeature);
        editToolBar->addAction(actionRemoveFeature);
        editToolBar->addSeparator();
        editToolBar->addAction(actionConnectFeatures);
        editToolBar->addAction(actionDisconnectFeatures);
        viewToolBar->addAction(actionShowFeatures);
        viewToolBar->addAction(actionShowConnections);
        viewToolBar->addAction(actionShowFeatureIDs);
        toolsToolBar->addAction(actionSpaceEvenly);
        toolsToolBar->addAction(actionFitLandmarks);
        toolsToolBar->addAction(actionExportPointsFile);
        helpTollBar->addAction(actionProject);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "FLAT - Facial Landmarks Annotation Tool", Q_NULLPTR));
        actionExit->setText(QApplication::translate("MainWindow", "&Exit", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionExit->setToolTip(QApplication::translate("MainWindow", "Terminates the program", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionAbout->setText(QApplication::translate("MainWindow", "&About...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionAbout->setToolTip(QApplication::translate("MainWindow", "Displays information on this program", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionOpen->setText(QApplication::translate("MainWindow", "&Open...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("MainWindow", "Loads an existing face annotation dataset from a file", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionNew->setText(QApplication::translate("MainWindow", "&New", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionNew->setToolTip(QApplication::translate("MainWindow", "Creates a new face annotation dataset", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionSave->setText(QApplication::translate("MainWindow", "&Save", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("MainWindow", "Saves the changes in the face annotation dataset", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionSaveAs->setText(QApplication::translate("MainWindow", "Save &as...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionSaveAs->setToolTip(QApplication::translate("MainWindow", "Saves the changes in the face annotation dataset to a different file", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionProject->setText(QApplication::translate("MainWindow", "&Project Docs", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionProject->setToolTip(QApplication::translate("MainWindow", "Displays the project's documentation page on Github", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionProject->setShortcut(QApplication::translate("MainWindow", "F1", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionAddImage->setText(QApplication::translate("MainWindow", "Add...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionAddImage->setToolTip(QApplication::translate("MainWindow", "Adds new images to the face annotation dataset", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionAddImage->setShortcut(QApplication::translate("MainWindow", "Ctrl+Ins", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionRemoveImage->setText(QApplication::translate("MainWindow", "Remove", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionRemoveImage->setToolTip(QApplication::translate("MainWindow", "Removes the selected images from the face annotation dataset", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionRemoveImage->setShortcut(QApplication::translate("MainWindow", "Ctrl+Del", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionShowImagesList->setText(QApplication::translate("MainWindow", "&List of Images", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionShowImagesList->setToolTip(QApplication::translate("MainWindow", "Displays or hides the window with the list of images in the face annotation dataset", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionShowImagesList->setShortcut(QApplication::translate("MainWindow", "F2", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionShowImageProperties->setText(QApplication::translate("MainWindow", "&Image Properties", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionShowImageProperties->setToolTip(QApplication::translate("MainWindow", "Displays/hides the window with the propriedades of the selected image", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionShowImageProperties->setShortcut(QApplication::translate("MainWindow", "F3", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionShowFeatures->setText(QApplication::translate("MainWindow", "&Landmarks", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionShowFeatures->setToolTip(QApplication::translate("MainWindow", "Displays/hides the facial landmarks", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionShowFeatures->setShortcut(QApplication::translate("MainWindow", "F4", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionShowConnections->setText(QApplication::translate("MainWindow", "&Links", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionShowConnections->setToolTip(QApplication::translate("MainWindow", "Displays/hides the links between facial landmarks", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionShowConnections->setShortcut(QApplication::translate("MainWindow", "F5", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionShowFeatureIDs->setText(QApplication::translate("MainWindow", "&Labels", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionShowFeatureIDs->setToolTip(QApplication::translate("MainWindow", "Shows/hides the labels of the facial landmarks", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionShowFeatureIDs->setShortcut(QApplication::translate("MainWindow", "F6", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionAddFeature->setText(QApplication::translate("MainWindow", "&Add", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionAddFeature->setToolTip(QApplication::translate("MainWindow", "Add a new facial landmark to the face annotation dataset", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionAddFeature->setShortcut(QApplication::translate("MainWindow", "Shift+A", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionRemoveFeature->setText(QApplication::translate("MainWindow", "&Remove", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionRemoveFeature->setToolTip(QApplication::translate("MainWindow", "Removes the selected facial landmarks (and their links) from the face annotation dataset", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionRemoveFeature->setShortcut(QApplication::translate("MainWindow", "Shift+R", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionConnectFeatures->setText(QApplication::translate("MainWindow", "&Link", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionConnectFeatures->setToolTip(QApplication::translate("MainWindow", "Links two selected facial landmarks", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionConnectFeatures->setShortcut(QApplication::translate("MainWindow", "Shift+L", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionDisconnectFeatures->setText(QApplication::translate("MainWindow", "&Unlink", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionDisconnectFeatures->setToolTip(QApplication::translate("MainWindow", "Unlinks the selected facial landmarks", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionDisconnectFeatures->setShortcut(QApplication::translate("MainWindow", "Shift+U", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionFitLandmarks->setText(QApplication::translate("MainWindow", "&Fit Landmarks", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionFitLandmarks->setToolTip(QApplication::translate("MainWindow", "Attempts to automaticaly fit the face model (with 66 landmarks) to the currently selected face image using the face-fit utility from the CSIRO Face Analysis SDK", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionFitLandmarks->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionConfigure->setText(QApplication::translate("MainWindow", "&Configure...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionConfigure->setToolTip(QApplication::translate("MainWindow", "Configure the face-fit utility from the CSIRO Face Analysis SDK", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionExportPointsFile->setText(QApplication::translate("MainWindow", "&Export points file...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionExportPointsFile->setToolTip(QApplication::translate("MainWindow", "Exports the annotation in current selected image to a CSIRO Face Analysis SDK points file", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionShowFaceOvalLow->setText(QApplication::translate("MainWindow", "Face Oval Lower", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionShowFaceOvalLow->setToolTip(QApplication::translate("MainWindow", "Show Face Oval Lower", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionShowFaceOvalUpper->setText(QApplication::translate("MainWindow", "Face Obal Upper", Q_NULLPTR));
        actionBrowRight->setText(QApplication::translate("MainWindow", "Brow Right", Q_NULLPTR));
        actionBrowLeft->setText(QApplication::translate("MainWindow", "Brow Left", Q_NULLPTR));
        actionEyeRight->setText(QApplication::translate("MainWindow", "Eye Right", Q_NULLPTR));
        actionEyeLeft->setText(QApplication::translate("MainWindow", "Eye Left", Q_NULLPTR));
        actionNoseRidge->setText(QApplication::translate("MainWindow", "Nose Ridge", Q_NULLPTR));
        actionNoseShape->setText(QApplication::translate("MainWindow", "Nose Shape", Q_NULLPTR));
        actionMouthOuter->setText(QApplication::translate("MainWindow", "Mouth Outer", Q_NULLPTR));
        actionMouthInner->setText(QApplication::translate("MainWindow", "Mouth Inner", Q_NULLPTR));
        actionLandmarksProperties->setText(QApplication::translate("MainWindow", "&Landmarks Properties", Q_NULLPTR));
        actionMakeLandmarksEvenlySpaced->setText(QApplication::translate("MainWindow", "Make Landmarks Evenly Spaced", Q_NULLPTR));
        actionSpaceEvenly->setText(QApplication::translate("MainWindow", "Space Evenly", Q_NULLPTR));
        actionUnod->setText(QApplication::translate("MainWindow", "Unod", Q_NULLPTR));
        actionUndo->setText(QApplication::translate("MainWindow", "Undo", Q_NULLPTR));
        actionRedo->setText(QApplication::translate("MainWindow", "Redo", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "&File", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "&Help", Q_NULLPTR));
        menuShow->setTitle(QApplication::translate("MainWindow", "&Show", Q_NULLPTR));
        menuWindows->setTitle(QApplication::translate("MainWindow", "&Windows", Q_NULLPTR));
        menu_Image_Elements->setTitle(QApplication::translate("MainWindow", "&Image Elements", Q_NULLPTR));
        menuLandmarks_Groups->setTitle(QApplication::translate("MainWindow", "Landmarks Groups", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("MainWindow", "&Edit", Q_NULLPTR));
        menu_Images->setTitle(QApplication::translate("MainWindow", "&Images", Q_NULLPTR));
        menu_Facial_Landmarks->setTitle(QApplication::translate("MainWindow", "&Facial Landmarks", Q_NULLPTR));
        menuTools->setTitle(QApplication::translate("MainWindow", "&Tools", Q_NULLPTR));
        menu_CSIRO_Face_Analysis_SDK->setTitle(QApplication::translate("MainWindow", "&CSIRO Face Analysis SDK", Q_NULLPTR));
        fileToolBar->setWindowTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        dockProperties->setWindowTitle(QApplication::translate("MainWindow", "Image Properties", Q_NULLPTR));
        labelPath->setText(QApplication::translate("MainWindow", "Path:", Q_NULLPTR));
        label_Zoom->setText(QApplication::translate("MainWindow", "Zoom:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        zoomSlider->setToolTip(QApplication::translate("MainWindow", "Altera o zoom nas imagens (+/- ou Ctrl+Roda do Mouse)", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label1000->setText(QApplication::translate("MainWindow", "10%", Q_NULLPTR));
        label100->setText(QApplication::translate("MainWindow", "100%", Q_NULLPTR));
        label10->setText(QApplication::translate("MainWindow", "1000%", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Rotate", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        rotationSlider->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        label_3->setText(QApplication::translate("MainWindow", "-180\302\260", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "0\302\260", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "+180\302\260", Q_NULLPTR));
        dockImages->setWindowTitle(QApplication::translate("MainWindow", "Image List", Q_NULLPTR));
        imagesToolbar->setWindowTitle(QString());
        editToolBar->setWindowTitle(QApplication::translate("MainWindow", "Edit", Q_NULLPTR));
        viewToolBar->setWindowTitle(QApplication::translate("MainWindow", "View", Q_NULLPTR));
        toolsToolBar->setWindowTitle(QApplication::translate("MainWindow", "Tools", Q_NULLPTR));
        helpTollBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
