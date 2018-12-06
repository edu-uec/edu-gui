/****************************************************************************
** Meta object code from reading C++ file 'orderprogram.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../edu_display/orderprogram.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'orderprogram.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OrderProgram_t {
    QByteArrayData data[8];
    char stringdata0[80];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OrderProgram_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OrderProgram_t qt_meta_stringdata_OrderProgram = {
    {
QT_MOC_LITERAL(0, 0, 12), // "OrderProgram"
QT_MOC_LITERAL(1, 13, 15), // "pushOrderSignal"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 4), // "text"
QT_MOC_LITERAL(4, 35, 17), // "deleteOrderSignal"
QT_MOC_LITERAL(5, 53, 12), // "getOrderName"
QT_MOC_LITERAL(6, 66, 5), // "index"
QT_MOC_LITERAL(7, 72, 7) // "doOrder"

    },
    "OrderProgram\0pushOrderSignal\0\0text\0"
    "deleteOrderSignal\0getOrderName\0index\0"
    "doOrder"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OrderProgram[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    0,   37,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       5,    1,   38,    2, 0x02 /* Public */,
       7,    1,   41,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QVariant,    3,
    QMetaType::Void,

 // methods: parameters
    QMetaType::QString, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,

       0        // eod
};

void OrderProgram::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OrderProgram *_t = static_cast<OrderProgram *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pushOrderSignal((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 1: _t->deleteOrderSignal(); break;
        case 2: { QString _r = _t->getOrderName((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->doOrder((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (OrderProgram::*)(QVariant );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OrderProgram::pushOrderSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (OrderProgram::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OrderProgram::deleteOrderSignal)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject OrderProgram::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_OrderProgram.data,
      qt_meta_data_OrderProgram,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *OrderProgram::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OrderProgram::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OrderProgram.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int OrderProgram::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void OrderProgram::pushOrderSignal(QVariant _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void OrderProgram::deleteOrderSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
