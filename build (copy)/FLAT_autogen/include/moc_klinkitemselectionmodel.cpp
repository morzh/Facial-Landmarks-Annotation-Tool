/****************************************************************************
** Meta object code from reading C++ file 'klinkitemselectionmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/kitemmodels/klinkitemselectionmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'klinkitemselectionmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_KLinkItemSelectionModel_t {
    QByteArrayData data[12];
    char stringdata0[209];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KLinkItemSelectionModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KLinkItemSelectionModel_t qt_meta_stringdata_KLinkItemSelectionModel = {
    {
QT_MOC_LITERAL(0, 0, 23), // "KLinkItemSelectionModel"
QT_MOC_LITERAL(1, 24, 31), // "linkedItemSelectionModelChanged"
QT_MOC_LITERAL(2, 56, 0), // ""
QT_MOC_LITERAL(3, 57, 22), // "sourceSelectionChanged"
QT_MOC_LITERAL(4, 80, 14), // "QItemSelection"
QT_MOC_LITERAL(5, 95, 8), // "selected"
QT_MOC_LITERAL(6, 104, 10), // "deselected"
QT_MOC_LITERAL(7, 115, 20), // "sourceCurrentChanged"
QT_MOC_LITERAL(8, 136, 7), // "current"
QT_MOC_LITERAL(9, 144, 18), // "slotCurrentChanged"
QT_MOC_LITERAL(10, 163, 24), // "linkedItemSelectionModel"
QT_MOC_LITERAL(11, 188, 20) // "QItemSelectionModel*"

    },
    "KLinkItemSelectionModel\0"
    "linkedItemSelectionModelChanged\0\0"
    "sourceSelectionChanged\0QItemSelection\0"
    "selected\0deselected\0sourceCurrentChanged\0"
    "current\0slotCurrentChanged\0"
    "linkedItemSelectionModel\0QItemSelectionModel*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KLinkItemSelectionModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       1,   46, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    2,   35,    2, 0x08 /* Private */,
       7,    1,   40,    2, 0x08 /* Private */,
       9,    1,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4,    5,    6,
    QMetaType::Void, QMetaType::QModelIndex,    8,
    QMetaType::Void, QMetaType::QModelIndex,    8,

 // properties: name, type, flags
      10, 0x80000000 | 11, 0x0049510b,

 // properties: notify_signal_id
       0,

       0        // eod
};

void KLinkItemSelectionModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        KLinkItemSelectionModel *_t = static_cast<KLinkItemSelectionModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->linkedItemSelectionModelChanged(); break;
        case 1: _t->d_func()->sourceSelectionChanged((*reinterpret_cast< const QItemSelection(*)>(_a[1])),(*reinterpret_cast< const QItemSelection(*)>(_a[2]))); break;
        case 2: _t->d_func()->sourceCurrentChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->d_func()->slotCurrentChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QItemSelection >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (KLinkItemSelectionModel::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KLinkItemSelectionModel::linkedItemSelectionModelChanged)) {
                *result = 0;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QItemSelectionModel* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        KLinkItemSelectionModel *_t = static_cast<KLinkItemSelectionModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QItemSelectionModel**>(_v) = _t->linkedItemSelectionModel(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        KLinkItemSelectionModel *_t = static_cast<KLinkItemSelectionModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setLinkedItemSelectionModel(*reinterpret_cast< QItemSelectionModel**>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject KLinkItemSelectionModel::staticMetaObject = {
    { &QItemSelectionModel::staticMetaObject, qt_meta_stringdata_KLinkItemSelectionModel.data,
      qt_meta_data_KLinkItemSelectionModel,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *KLinkItemSelectionModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KLinkItemSelectionModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KLinkItemSelectionModel.stringdata0))
        return static_cast<void*>(this);
    return QItemSelectionModel::qt_metacast(_clname);
}

int KLinkItemSelectionModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QItemSelectionModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void KLinkItemSelectionModel::linkedItemSelectionModelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
