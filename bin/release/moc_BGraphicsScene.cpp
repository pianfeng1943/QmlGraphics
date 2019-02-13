/****************************************************************************
** Meta object code from reading C++ file 'BGraphicsScene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../BGraphics/BGraphicsScene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BGraphicsScene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BGraphicsScene_t {
    QByteArrayData data[12];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BGraphicsScene_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BGraphicsScene_t qt_meta_stringdata_BGraphicsScene = {
    {
QT_MOC_LITERAL(0, 0, 14), // "BGraphicsScene"
QT_MOC_LITERAL(1, 15, 13), // "setNormalMode"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 10), // "setPenMode"
QT_MOC_LITERAL(4, 41, 5), // "width"
QT_MOC_LITERAL(5, 47, 5), // "color"
QT_MOC_LITERAL(6, 53, 12), // "setLightMode"
QT_MOC_LITERAL(7, 66, 12), // "setShapeMode"
QT_MOC_LITERAL(8, 79, 4), // "type"
QT_MOC_LITERAL(9, 84, 11), // "setTextMode"
QT_MOC_LITERAL(10, 96, 4), // "font"
QT_MOC_LITERAL(11, 101, 13) // "setEraserMode"

    },
    "BGraphicsScene\0setNormalMode\0\0setPenMode\0"
    "width\0color\0setLightMode\0setShapeMode\0"
    "type\0setTextMode\0font\0setEraserMode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BGraphicsScene[] = {

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

 // methods: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x02 /* Public */,
       3,    2,   45,    2, 0x02 /* Public */,
       6,    0,   50,    2, 0x02 /* Public */,
       7,    3,   51,    2, 0x02 /* Public */,
       9,    2,   58,    2, 0x02 /* Public */,
      11,    0,   63,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QColor,    4,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QColor,    8,    4,    5,
    QMetaType::Void, QMetaType::QFont, QMetaType::QColor,   10,    5,
    QMetaType::Void,

       0        // eod
};

void BGraphicsScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BGraphicsScene *_t = static_cast<BGraphicsScene *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setNormalMode(); break;
        case 1: _t->setPenMode((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QColor(*)>(_a[2]))); break;
        case 2: _t->setLightMode(); break;
        case 3: _t->setShapeMode((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QColor(*)>(_a[3]))); break;
        case 4: _t->setTextMode((*reinterpret_cast< const QFont(*)>(_a[1])),(*reinterpret_cast< const QColor(*)>(_a[2]))); break;
        case 5: _t->setEraserMode(); break;
        default: ;
        }
    }
}

const QMetaObject BGraphicsScene::staticMetaObject = {
    { &QQuickItem::staticMetaObject, qt_meta_stringdata_BGraphicsScene.data,
      qt_meta_data_BGraphicsScene,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BGraphicsScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BGraphicsScene::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BGraphicsScene.stringdata0))
        return static_cast<void*>(this);
    return QQuickItem::qt_metacast(_clname);
}

int BGraphicsScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
