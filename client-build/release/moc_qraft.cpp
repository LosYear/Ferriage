/****************************************************************************
** Meta object code from reading C++ file 'qraft.h'
**
** Created: Sat 7. Apr 00:12:55 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../client/qraft.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qraft.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QRaft[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
      17,    6,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QRaft[] = {
    "QRaft\0\0clicked()\0slotClicked()\0"
};

void QRaft::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QRaft *_t = static_cast<QRaft *>(_o);
        switch (_id) {
        case 0: _t->clicked(); break;
        case 1: _t->slotClicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData QRaft::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QRaft::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_QRaft,
      qt_meta_data_QRaft, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QRaft::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QRaft::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QRaft::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QRaft))
        return static_cast<void*>(const_cast< QRaft*>(this));
    return QLabel::qt_metacast(_clname);
}

int QRaft::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QRaft::clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
