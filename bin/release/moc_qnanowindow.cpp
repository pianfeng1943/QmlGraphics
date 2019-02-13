/****************************************************************************
** Meta object code from reading C++ file 'qnanowindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../BGraphics/libqnanopainter/qnanowindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qnanowindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QNanoWindow_t {
    QByteArrayData data[8];
    char stringdata0[78];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QNanoWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QNanoWindow_t qt_meta_stringdata_QNanoWindow = {
    {
QT_MOC_LITERAL(0, 0, 11), // "QNanoWindow"
QT_MOC_LITERAL(1, 12, 11), // "touchSignal"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 12), // "QTouchEvent*"
QT_MOC_LITERAL(4, 38, 5), // "event"
QT_MOC_LITERAL(5, 44, 11), // "paintSignal"
QT_MOC_LITERAL(6, 56, 13), // "QNanoPainter*"
QT_MOC_LITERAL(7, 70, 7) // "painter"

    },
    "QNanoWindow\0touchSignal\0\0QTouchEvent*\0"
    "event\0paintSignal\0QNanoPainter*\0painter"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QNanoWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,
       5,    1,   27,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

void QNanoWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QNanoWindow *_t = static_cast<QNanoWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->touchSignal((*reinterpret_cast< QTouchEvent*(*)>(_a[1]))); break;
        case 1: _t->paintSignal((*reinterpret_cast< QNanoPainter*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (QNanoWindow::*_t)(QTouchEvent * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QNanoWindow::touchSignal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QNanoWindow::*_t)(QNanoPainter * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QNanoWindow::paintSignal)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject QNanoWindow::staticMetaObject = {
    { &QOpenGLWindow::staticMetaObject, qt_meta_stringdata_QNanoWindow.data,
      qt_meta_data_QNanoWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QNanoWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QNanoWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QNanoWindow.stringdata0))
        return static_cast<void*>(this);
    return QOpenGLWindow::qt_metacast(_clname);
}

int QNanoWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QOpenGLWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QNanoWindow::touchSignal(QTouchEvent * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QNanoWindow::paintSignal(QNanoPainter * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
