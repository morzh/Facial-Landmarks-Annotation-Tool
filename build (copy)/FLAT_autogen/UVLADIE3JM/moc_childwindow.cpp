/****************************************************************************
** Meta object code from reading C++ file 'childwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/childwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'childwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ft__ChildWindow_t {
    QByteArrayData data[17];
    char stringdata0[255];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ft__ChildWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ft__ChildWindow_t qt_meta_stringdata_ft__ChildWindow = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ft::ChildWindow"
QT_MOC_LITERAL(1, 16, 14), // "onDataModified"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 26), // "onFeaturesSelectionChanged"
QT_MOC_LITERAL(4, 59, 11), // "onUIUpdated"
QT_MOC_LITERAL(5, 71, 10), // "sImageName"
QT_MOC_LITERAL(6, 82, 10), // "iZoomLevel"
QT_MOC_LITERAL(7, 93, 20), // "onScaleFactorChanged"
QT_MOC_LITERAL(8, 114, 12), // "dScaleFactor"
QT_MOC_LITERAL(9, 127, 21), // "onRotateFactorChanged"
QT_MOC_LITERAL(10, 149, 30), // "onFaceFeaturesSelectionChanged"
QT_MOC_LITERAL(11, 180, 13), // "onDataChanged"
QT_MOC_LITERAL(12, 194, 9), // "bModified"
QT_MOC_LITERAL(13, 204, 14), // "onModelChanged"
QT_MOC_LITERAL(14, 219, 16), // "onCurrentChanged"
QT_MOC_LITERAL(15, 236, 8), // "oCurrent"
QT_MOC_LITERAL(16, 245, 9) // "oPrevious"

    },
    "ft::ChildWindow\0onDataModified\0\0"
    "onFeaturesSelectionChanged\0onUIUpdated\0"
    "sImageName\0iZoomLevel\0onScaleFactorChanged\0"
    "dScaleFactor\0onRotateFactorChanged\0"
    "onFaceFeaturesSelectionChanged\0"
    "onDataChanged\0bModified\0onModelChanged\0"
    "onCurrentChanged\0oCurrent\0oPrevious"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ft__ChildWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    0,   70,    2, 0x06 /* Public */,
       4,    2,   71,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   76,    2, 0x09 /* Protected */,
       9,    1,   79,    2, 0x09 /* Protected */,
      10,    0,   82,    2, 0x09 /* Protected */,
      11,    1,   83,    2, 0x09 /* Protected */,
      11,    0,   86,    2, 0x29 /* Protected | MethodCloned */,
      13,    1,   87,    2, 0x09 /* Protected */,
      13,    0,   90,    2, 0x29 /* Protected | MethodCloned */,
      14,    2,   91,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    5,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,   15,   16,

       0        // eod
};

void ft::ChildWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ChildWindow *_t = static_cast<ChildWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onDataModified(); break;
        case 1: _t->onFeaturesSelectionChanged(); break;
        case 2: _t->onUIUpdated((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 3: _t->onScaleFactorChanged((*reinterpret_cast< const double(*)>(_a[1]))); break;
        case 4: _t->onRotateFactorChanged((*reinterpret_cast< const double(*)>(_a[1]))); break;
        case 5: _t->onFaceFeaturesSelectionChanged(); break;
        case 6: _t->onDataChanged((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 7: _t->onDataChanged(); break;
        case 8: _t->onModelChanged((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 9: _t->onModelChanged(); break;
        case 10: _t->onCurrentChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ChildWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChildWindow::onDataModified)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ChildWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChildWindow::onFeaturesSelectionChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ChildWindow::*_t)(const QString , const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChildWindow::onUIUpdated)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject ft::ChildWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ft__ChildWindow.data,
      qt_meta_data_ft__ChildWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ft::ChildWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ft::ChildWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ft__ChildWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ft::ChildWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void ft::ChildWindow::onDataModified()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ft::ChildWindow::onFeaturesSelectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ft::ChildWindow::onUIUpdated(const QString _t1, const int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
