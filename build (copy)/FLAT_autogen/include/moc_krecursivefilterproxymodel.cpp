/****************************************************************************
** Meta object code from reading C++ file 'krecursivefilterproxymodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/kitemmodels/krecursivefilterproxymodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'krecursivefilterproxymodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_KRecursiveFilterProxyModel_t {
    QByteArrayData data[14];
    char stringdata0[217];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KRecursiveFilterProxyModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KRecursiveFilterProxyModel_t qt_meta_stringdata_KRecursiveFilterProxyModel = {
    {
QT_MOC_LITERAL(0, 0, 26), // "KRecursiveFilterProxyModel"
QT_MOC_LITERAL(1, 27, 17), // "sourceDataChanged"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 15), // "source_top_left"
QT_MOC_LITERAL(4, 62, 19), // "source_bottom_right"
QT_MOC_LITERAL(5, 82, 12), // "QVector<int>"
QT_MOC_LITERAL(6, 95, 5), // "roles"
QT_MOC_LITERAL(7, 101, 27), // "sourceRowsAboutToBeInserted"
QT_MOC_LITERAL(8, 129, 13), // "source_parent"
QT_MOC_LITERAL(9, 143, 5), // "start"
QT_MOC_LITERAL(10, 149, 3), // "end"
QT_MOC_LITERAL(11, 153, 18), // "sourceRowsInserted"
QT_MOC_LITERAL(12, 172, 26), // "sourceRowsAboutToBeRemoved"
QT_MOC_LITERAL(13, 199, 17) // "sourceRowsRemoved"

    },
    "KRecursiveFilterProxyModel\0sourceDataChanged\0"
    "\0source_top_left\0source_bottom_right\0"
    "QVector<int>\0roles\0sourceRowsAboutToBeInserted\0"
    "source_parent\0start\0end\0sourceRowsInserted\0"
    "sourceRowsAboutToBeRemoved\0sourceRowsRemoved"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KRecursiveFilterProxyModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   44,    2, 0x08 /* Private */,
       1,    2,   51,    2, 0x28 /* Private | MethodCloned */,
       7,    3,   56,    2, 0x08 /* Private */,
      11,    3,   63,    2, 0x08 /* Private */,
      12,    3,   70,    2, 0x08 /* Private */,
      13,    3,   77,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex, 0x80000000 | 5,    3,    4,    6,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,    3,    4,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::Int, QMetaType::Int,    8,    9,   10,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::Int, QMetaType::Int,    8,    9,   10,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::Int, QMetaType::Int,    8,    9,   10,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::Int, QMetaType::Int,    8,    9,   10,

       0        // eod
};

void KRecursiveFilterProxyModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        KRecursiveFilterProxyModel *_t = static_cast<KRecursiveFilterProxyModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->d_func()->sourceDataChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2])),(*reinterpret_cast< const QVector<int>(*)>(_a[3]))); break;
        case 1: _t->d_func()->sourceDataChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 2: _t->d_func()->sourceRowsAboutToBeInserted((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->d_func()->sourceRowsInserted((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: _t->d_func()->sourceRowsAboutToBeRemoved((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 5: _t->d_func()->sourceRowsRemoved((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        }
    }
}

const QMetaObject KRecursiveFilterProxyModel::staticMetaObject = {
    { &QSortFilterProxyModel::staticMetaObject, qt_meta_stringdata_KRecursiveFilterProxyModel.data,
      qt_meta_data_KRecursiveFilterProxyModel,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *KRecursiveFilterProxyModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KRecursiveFilterProxyModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KRecursiveFilterProxyModel.stringdata0))
        return static_cast<void*>(this);
    return QSortFilterProxyModel::qt_metacast(_clname);
}

int KRecursiveFilterProxyModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSortFilterProxyModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
