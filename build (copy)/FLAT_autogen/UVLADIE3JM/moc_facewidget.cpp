/****************************************************************************
** Meta object code from reading C++ file 'facewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/facewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'facewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ft__FaceWidget_t {
    QByteArrayData data[9];
    char stringdata0[158];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ft__FaceWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ft__FaceWidget_t qt_meta_stringdata_ft__FaceWidget = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ft::FaceWidget"
QT_MOC_LITERAL(1, 15, 20), // "onScaleFactorChanged"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 12), // "dScaleFactor"
QT_MOC_LITERAL(4, 50, 21), // "onRotateFactorChanged"
QT_MOC_LITERAL(5, 72, 13), // "dRotateFactor"
QT_MOC_LITERAL(6, 86, 21), // "onFaceFeaturesChanged"
QT_MOC_LITERAL(7, 108, 30), // "onFaceFeaturesSelectionChanged"
QT_MOC_LITERAL(8, 139, 18) // "onSelectionChanged"

    },
    "ft::FaceWidget\0onScaleFactorChanged\0"
    "\0dScaleFactor\0onRotateFactorChanged\0"
    "dRotateFactor\0onFaceFeaturesChanged\0"
    "onFaceFeaturesSelectionChanged\0"
    "onSelectionChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ft__FaceWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,
       6,    0,   45,    2, 0x06 /* Public */,
       7,    0,   46,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   47,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void ft::FaceWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FaceWidget *_t = static_cast<FaceWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onScaleFactorChanged((*reinterpret_cast< const double(*)>(_a[1]))); break;
        case 1: _t->onRotateFactorChanged((*reinterpret_cast< const double(*)>(_a[1]))); break;
        case 2: _t->onFaceFeaturesChanged(); break;
        case 3: _t->onFaceFeaturesSelectionChanged(); break;
        case 4: _t->onSelectionChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (FaceWidget::*_t)(const double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FaceWidget::onScaleFactorChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (FaceWidget::*_t)(const double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FaceWidget::onRotateFactorChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (FaceWidget::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FaceWidget::onFaceFeaturesChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (FaceWidget::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FaceWidget::onFaceFeaturesSelectionChanged)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject ft::FaceWidget::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_ft__FaceWidget.data,
      qt_meta_data_ft__FaceWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ft::FaceWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ft::FaceWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ft__FaceWidget.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int ft::FaceWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ft::FaceWidget::onScaleFactorChanged(const double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ft::FaceWidget::onRotateFactorChanged(const double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ft::FaceWidget::onFaceFeaturesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ft::FaceWidget::onFaceFeaturesSelectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
