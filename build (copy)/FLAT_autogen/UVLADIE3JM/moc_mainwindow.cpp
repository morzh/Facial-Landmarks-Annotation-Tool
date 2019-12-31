/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ft__MainWindow_t {
    QByteArrayData data[61];
    char stringdata0[1392];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ft__MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ft__MainWindow_t qt_meta_stringdata_ft__MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ft::MainWindow"
QT_MOC_LITERAL(1, 15, 17), // "showStatusMessage"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 4), // "sMsg"
QT_MOC_LITERAL(4, 39, 8), // "iTimeout"
QT_MOC_LITERAL(5, 48, 22), // "on_actionNew_triggered"
QT_MOC_LITERAL(6, 71, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(7, 95, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(8, 119, 25), // "on_actionSaveAs_triggered"
QT_MOC_LITERAL(9, 145, 23), // "on_actionExit_triggered"
QT_MOC_LITERAL(10, 169, 28), // "on_actionConfigure_triggered"
QT_MOC_LITERAL(11, 198, 31), // "on_actionFitLandmarks_triggered"
QT_MOC_LITERAL(12, 230, 35), // "on_actionExportPointsFile_tri..."
QT_MOC_LITERAL(13, 266, 26), // "on_actionProject_triggered"
QT_MOC_LITERAL(14, 293, 24), // "on_actionAbout_triggered"
QT_MOC_LITERAL(15, 318, 20), // "on_tabCloseRequested"
QT_MOC_LITERAL(16, 339, 9), // "iTabIndex"
QT_MOC_LITERAL(17, 349, 13), // "on_tabChanged"
QT_MOC_LITERAL(18, 363, 27), // "on_actionAddImage_triggered"
QT_MOC_LITERAL(19, 391, 30), // "on_actionRemoveImage_triggered"
QT_MOC_LITERAL(20, 422, 33), // "on_actionShowImagesList_trigg..."
QT_MOC_LITERAL(21, 456, 8), // "bChecked"
QT_MOC_LITERAL(22, 465, 38), // "on_actionShowImageProperties_..."
QT_MOC_LITERAL(23, 504, 31), // "on_actionShowFeatures_triggered"
QT_MOC_LITERAL(24, 536, 34), // "on_actionShowConnections_trig..."
QT_MOC_LITERAL(25, 571, 33), // "on_actionShowFeatureIDs_trigg..."
QT_MOC_LITERAL(26, 605, 29), // "on_actionAddFeature_triggered"
QT_MOC_LITERAL(27, 635, 32), // "on_actionRemoveFeature_triggered"
QT_MOC_LITERAL(28, 668, 34), // "on_actionConnectFeatures_trig..."
QT_MOC_LITERAL(29, 703, 37), // "on_actionDisconnectFeatures_t..."
QT_MOC_LITERAL(30, 741, 38), // "on_actionLandmarksProperties_..."
QT_MOC_LITERAL(31, 780, 34), // "on_actionShowFaceOvalLow_trig..."
QT_MOC_LITERAL(32, 815, 36), // "on_actionShowFaceOvalUpper_tr..."
QT_MOC_LITERAL(33, 852, 28), // "on_actionBrowRight_triggered"
QT_MOC_LITERAL(34, 881, 27), // "on_actionBrowLeft_triggered"
QT_MOC_LITERAL(35, 909, 27), // "on_actionEyeRight_triggered"
QT_MOC_LITERAL(36, 937, 26), // "on_actionEyeLeft_triggered"
QT_MOC_LITERAL(37, 964, 28), // "on_actionNoseShape_triggered"
QT_MOC_LITERAL(38, 993, 28), // "on_actionNoseRidge_triggered"
QT_MOC_LITERAL(39, 1022, 29), // "on_actionMouthOuter_triggered"
QT_MOC_LITERAL(40, 1052, 29), // "on_actionMouthInner_triggered"
QT_MOC_LITERAL(41, 1082, 30), // "on_actionSpaceEvenly_triggered"
QT_MOC_LITERAL(42, 1113, 16), // "setImageListView"
QT_MOC_LITERAL(43, 1130, 5), // "sType"
QT_MOC_LITERAL(44, 1136, 19), // "toggleImageListView"
QT_MOC_LITERAL(45, 1156, 16), // "onChildUIUpdated"
QT_MOC_LITERAL(46, 1173, 10), // "sImageName"
QT_MOC_LITERAL(47, 1184, 10), // "iZoomLevel"
QT_MOC_LITERAL(48, 1195, 24), // "onZoomSliderValueChanged"
QT_MOC_LITERAL(49, 1220, 6), // "iValue"
QT_MOC_LITERAL(50, 1227, 18), // "onZoomLevelChanged"
QT_MOC_LITERAL(51, 1246, 10), // "onUpdateUI"
QT_MOC_LITERAL(52, 1257, 10), // "onFitError"
QT_MOC_LITERAL(53, 1268, 22), // "QProcess::ProcessError"
QT_MOC_LITERAL(54, 1291, 6), // "eError"
QT_MOC_LITERAL(55, 1298, 13), // "onFitFinished"
QT_MOC_LITERAL(56, 1312, 9), // "iExitCode"
QT_MOC_LITERAL(57, 1322, 20), // "QProcess::ExitStatus"
QT_MOC_LITERAL(58, 1343, 11), // "eExitStatus"
QT_MOC_LITERAL(59, 1355, 23), // "on_SearchBox_textEdited"
QT_MOC_LITERAL(60, 1379, 12) // "textToSearch"

    },
    "ft::MainWindow\0showStatusMessage\0\0"
    "sMsg\0iTimeout\0on_actionNew_triggered\0"
    "on_actionOpen_triggered\0on_actionSave_triggered\0"
    "on_actionSaveAs_triggered\0"
    "on_actionExit_triggered\0"
    "on_actionConfigure_triggered\0"
    "on_actionFitLandmarks_triggered\0"
    "on_actionExportPointsFile_triggered\0"
    "on_actionProject_triggered\0"
    "on_actionAbout_triggered\0on_tabCloseRequested\0"
    "iTabIndex\0on_tabChanged\0"
    "on_actionAddImage_triggered\0"
    "on_actionRemoveImage_triggered\0"
    "on_actionShowImagesList_triggered\0"
    "bChecked\0on_actionShowImageProperties_triggered\0"
    "on_actionShowFeatures_triggered\0"
    "on_actionShowConnections_triggered\0"
    "on_actionShowFeatureIDs_triggered\0"
    "on_actionAddFeature_triggered\0"
    "on_actionRemoveFeature_triggered\0"
    "on_actionConnectFeatures_triggered\0"
    "on_actionDisconnectFeatures_triggered\0"
    "on_actionLandmarksProperties_triggered\0"
    "on_actionShowFaceOvalLow_triggered\0"
    "on_actionShowFaceOvalUpper_triggered\0"
    "on_actionBrowRight_triggered\0"
    "on_actionBrowLeft_triggered\0"
    "on_actionEyeRight_triggered\0"
    "on_actionEyeLeft_triggered\0"
    "on_actionNoseShape_triggered\0"
    "on_actionNoseRidge_triggered\0"
    "on_actionMouthOuter_triggered\0"
    "on_actionMouthInner_triggered\0"
    "on_actionSpaceEvenly_triggered\0"
    "setImageListView\0sType\0toggleImageListView\0"
    "onChildUIUpdated\0sImageName\0iZoomLevel\0"
    "onZoomSliderValueChanged\0iValue\0"
    "onZoomLevelChanged\0onUpdateUI\0onFitError\0"
    "QProcess::ProcessError\0eError\0"
    "onFitFinished\0iExitCode\0QProcess::ExitStatus\0"
    "eExitStatus\0on_SearchBox_textEdited\0"
    "textToSearch"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ft__MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      46,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,  244,    2, 0x0a /* Public */,
       1,    1,  249,    2, 0x2a /* Public | MethodCloned */,
       5,    0,  252,    2, 0x08 /* Private */,
       6,    0,  253,    2, 0x08 /* Private */,
       7,    0,  254,    2, 0x08 /* Private */,
       8,    0,  255,    2, 0x08 /* Private */,
       9,    0,  256,    2, 0x08 /* Private */,
      10,    0,  257,    2, 0x08 /* Private */,
      11,    0,  258,    2, 0x08 /* Private */,
      12,    0,  259,    2, 0x08 /* Private */,
      13,    0,  260,    2, 0x08 /* Private */,
      14,    0,  261,    2, 0x08 /* Private */,
      15,    1,  262,    2, 0x08 /* Private */,
      17,    1,  265,    2, 0x08 /* Private */,
      18,    0,  268,    2, 0x08 /* Private */,
      19,    0,  269,    2, 0x08 /* Private */,
      20,    1,  270,    2, 0x08 /* Private */,
      22,    1,  273,    2, 0x08 /* Private */,
      23,    1,  276,    2, 0x08 /* Private */,
      24,    1,  279,    2, 0x08 /* Private */,
      25,    1,  282,    2, 0x08 /* Private */,
      26,    0,  285,    2, 0x08 /* Private */,
      27,    0,  286,    2, 0x08 /* Private */,
      28,    0,  287,    2, 0x08 /* Private */,
      29,    0,  288,    2, 0x08 /* Private */,
      30,    0,  289,    2, 0x08 /* Private */,
      31,    1,  290,    2, 0x08 /* Private */,
      32,    1,  293,    2, 0x08 /* Private */,
      33,    1,  296,    2, 0x08 /* Private */,
      34,    1,  299,    2, 0x08 /* Private */,
      35,    1,  302,    2, 0x08 /* Private */,
      36,    1,  305,    2, 0x08 /* Private */,
      37,    1,  308,    2, 0x08 /* Private */,
      38,    1,  311,    2, 0x08 /* Private */,
      39,    1,  314,    2, 0x08 /* Private */,
      40,    1,  317,    2, 0x08 /* Private */,
      41,    0,  320,    2, 0x08 /* Private */,
      42,    1,  321,    2, 0x08 /* Private */,
      44,    0,  324,    2, 0x08 /* Private */,
      45,    2,  325,    2, 0x08 /* Private */,
      48,    1,  330,    2, 0x08 /* Private */,
      50,    1,  333,    2, 0x08 /* Private */,
      51,    0,  336,    2, 0x08 /* Private */,
      52,    1,  337,    2, 0x08 /* Private */,
      55,    2,  340,    2, 0x08 /* Private */,
      59,    1,  345,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   43,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   46,   47,
    QMetaType::Void, QMetaType::Int,   49,
    QMetaType::Void, QMetaType::Int,   49,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 53,   54,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 57,   56,   58,
    QMetaType::Void, QMetaType::QString,   60,

       0        // eod
};

void ft::MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showStatusMessage((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 1: _t->showStatusMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_actionNew_triggered(); break;
        case 3: _t->on_actionOpen_triggered(); break;
        case 4: _t->on_actionSave_triggered(); break;
        case 5: _t->on_actionSaveAs_triggered(); break;
        case 6: _t->on_actionExit_triggered(); break;
        case 7: _t->on_actionConfigure_triggered(); break;
        case 8: _t->on_actionFitLandmarks_triggered(); break;
        case 9: _t->on_actionExportPointsFile_triggered(); break;
        case 10: _t->on_actionProject_triggered(); break;
        case 11: _t->on_actionAbout_triggered(); break;
        case 12: _t->on_tabCloseRequested((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->on_tabChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->on_actionAddImage_triggered(); break;
        case 15: _t->on_actionRemoveImage_triggered(); break;
        case 16: _t->on_actionShowImagesList_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->on_actionShowImageProperties_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->on_actionShowFeatures_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: _t->on_actionShowConnections_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 20: _t->on_actionShowFeatureIDs_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: _t->on_actionAddFeature_triggered(); break;
        case 22: _t->on_actionRemoveFeature_triggered(); break;
        case 23: _t->on_actionConnectFeatures_triggered(); break;
        case 24: _t->on_actionDisconnectFeatures_triggered(); break;
        case 25: _t->on_actionLandmarksProperties_triggered(); break;
        case 26: _t->on_actionShowFaceOvalLow_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 27: _t->on_actionShowFaceOvalUpper_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 28: _t->on_actionBrowRight_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 29: _t->on_actionBrowLeft_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 30: _t->on_actionEyeRight_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 31: _t->on_actionEyeLeft_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 32: _t->on_actionNoseShape_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 33: _t->on_actionNoseRidge_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 34: _t->on_actionMouthOuter_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 35: _t->on_actionMouthInner_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 36: _t->on_actionSpaceEvenly_triggered(); break;
        case 37: _t->setImageListView((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 38: _t->toggleImageListView(); break;
        case 39: _t->onChildUIUpdated((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 40: _t->onZoomSliderValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 41: _t->onZoomLevelChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 42: _t->onUpdateUI(); break;
        case 43: _t->onFitError((*reinterpret_cast< QProcess::ProcessError(*)>(_a[1]))); break;
        case 44: _t->onFitFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 45: _t->on_SearchBox_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ft::MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ft__MainWindow.data,
      qt_meta_data_ft__MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ft::MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ft::MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ft__MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int ft::MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 46)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 46;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 46)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 46;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
