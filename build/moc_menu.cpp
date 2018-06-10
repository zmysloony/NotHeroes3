/****************************************************************************
** Meta object code from reading C++ file 'menu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../projekt4-master/menu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'menu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_loadButton_t {
    QByteArrayData data[7];
    char stringdata0[59];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_loadButton_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_loadButton_t qt_meta_stringdata_loadButton = {
    {
QT_MOC_LITERAL(0, 0, 10), // "loadButton"
QT_MOC_LITERAL(1, 11, 12), // "SIGcreateMap"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 7), // "SIGnote"
QT_MOC_LITERAL(4, 33, 11), // "std::string"
QT_MOC_LITERAL(5, 45, 4), // "text"
QT_MOC_LITERAL(6, 50, 8) // "loadSave"

    },
    "loadButton\0SIGcreateMap\0\0SIGnote\0"
    "std::string\0text\0loadSave"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_loadButton[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    1,   30,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   33,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void loadButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        loadButton *_t = static_cast<loadButton *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SIGcreateMap(); break;
        case 1: _t->SIGnote((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 2: _t->loadSave(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (loadButton::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&loadButton::SIGcreateMap)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (loadButton::*)(std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&loadButton::SIGnote)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject loadButton::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_loadButton.data,
      qt_meta_data_loadButton,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *loadButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *loadButton::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_loadButton.stringdata0))
        return static_cast<void*>(this);
    return QPushButton::qt_metacast(_clname);
}

int loadButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void loadButton::SIGcreateMap()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void loadButton::SIGnote(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_saveButton_t {
    QByteArrayData data[9];
    char stringdata0[74];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_saveButton_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_saveButton_t qt_meta_stringdata_saveButton = {
    {
QT_MOC_LITERAL(0, 0, 10), // "saveButton"
QT_MOC_LITERAL(1, 11, 7), // "SIGnote"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 11), // "std::string"
QT_MOC_LITERAL(4, 32, 4), // "text"
QT_MOC_LITERAL(5, 37, 11), // "SIGgameSave"
QT_MOC_LITERAL(6, 49, 8), // "filename"
QT_MOC_LITERAL(7, 58, 10), // "enableSave"
QT_MOC_LITERAL(8, 69, 4) // "save"

    },
    "saveButton\0SIGnote\0\0std::string\0text\0"
    "SIGgameSave\0filename\0enableSave\0save"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_saveButton[] = {

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
       5,    1,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   40,    2, 0x0a /* Public */,
       8,    0,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void saveButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        saveButton *_t = static_cast<saveButton *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SIGnote((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 1: _t->SIGgameSave((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 2: _t->enableSave(); break;
        case 3: _t->save(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (saveButton::*)(std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&saveButton::SIGnote)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (saveButton::*)(std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&saveButton::SIGgameSave)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject saveButton::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_saveButton.data,
      qt_meta_data_saveButton,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *saveButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *saveButton::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_saveButton.stringdata0))
        return static_cast<void*>(this);
    return QPushButton::qt_metacast(_clname);
}

int saveButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
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
void saveButton::SIGnote(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void saveButton::SIGgameSave(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_am_t {
    QByteArrayData data[5];
    char stringdata0[15];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_am_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_am_t qt_meta_stringdata_am = {
    {
QT_MOC_LITERAL(0, 0, 2), // "am"
QT_MOC_LITERAL(1, 3, 6), // "update"
QT_MOC_LITERAL(2, 10, 0), // ""
QT_MOC_LITERAL(3, 11, 1), // "m"
QT_MOC_LITERAL(4, 13, 1) // "a"

    },
    "am\0update\0\0m\0a"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_am[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,

       0        // eod
};

void am::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        am *_t = static_cast<am *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->update((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject am::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_am.data,
      qt_meta_data_am,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *am::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *am::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_am.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int am::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_comms_t {
    QByteArrayData data[8];
    char stringdata0[62];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_comms_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_comms_t qt_meta_stringdata_comms = {
    {
QT_MOC_LITERAL(0, 0, 5), // "comms"
QT_MOC_LITERAL(1, 6, 10), // "recieveMsg"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 11), // "std::string"
QT_MOC_LITERAL(4, 30, 7), // "addText"
QT_MOC_LITERAL(5, 38, 5), // "flush"
QT_MOC_LITERAL(6, 44, 10), // "winRecieve"
QT_MOC_LITERAL(7, 55, 6) // "winner"

    },
    "comms\0recieveMsg\0\0std::string\0addText\0"
    "flush\0winRecieve\0winner"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_comms[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       5,    0,   32,    2, 0x0a /* Public */,
       6,    1,   33,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,

       0        // eod
};

void comms::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        comms *_t = static_cast<comms *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->recieveMsg((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 1: _t->flush(); break;
        case 2: _t->winRecieve((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject comms::staticMetaObject = {
    { &QTextEdit::staticMetaObject, qt_meta_stringdata_comms.data,
      qt_meta_data_comms,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *comms::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *comms::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_comms.stringdata0))
        return static_cast<void*>(this);
    return QTextEdit::qt_metacast(_clname);
}

int comms::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
struct qt_meta_stringdata_gameMap_t {
    QByteArrayData data[21];
    char stringdata0[182];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_gameMap_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_gameMap_t qt_meta_stringdata_gameMap = {
    {
QT_MOC_LITERAL(0, 0, 7), // "gameMap"
QT_MOC_LITERAL(1, 8, 15), // "playerTurnStart"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 8), // "playerId"
QT_MOC_LITERAL(4, 34, 7), // "SIGnote"
QT_MOC_LITERAL(5, 42, 11), // "std::string"
QT_MOC_LITERAL(6, 54, 4), // "text"
QT_MOC_LITERAL(7, 59, 16), // "SIGcreatedNewMap"
QT_MOC_LITERAL(8, 76, 6), // "SIGwin"
QT_MOC_LITERAL(9, 83, 6), // "winner"
QT_MOC_LITERAL(10, 90, 11), // "SIGupdateAM"
QT_MOC_LITERAL(11, 102, 1), // "a"
QT_MOC_LITERAL(12, 104, 1), // "t"
QT_MOC_LITERAL(13, 106, 15), // "SIGnoteRecieved"
QT_MOC_LITERAL(14, 122, 12), // "clickHandler"
QT_MOC_LITERAL(15, 135, 8), // "buttonID"
QT_MOC_LITERAL(16, 144, 7), // "newTurn"
QT_MOC_LITERAL(17, 152, 4), // "over"
QT_MOC_LITERAL(18, 157, 6), // "create"
QT_MOC_LITERAL(19, 164, 8), // "gameSave"
QT_MOC_LITERAL(20, 173, 8) // "filename"

    },
    "gameMap\0playerTurnStart\0\0playerId\0"
    "SIGnote\0std::string\0text\0SIGcreatedNewMap\0"
    "SIGwin\0winner\0SIGupdateAM\0a\0t\0"
    "SIGnoteRecieved\0clickHandler\0buttonID\0"
    "newTurn\0over\0create\0gameSave\0filename"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_gameMap[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    1,   72,    2, 0x06 /* Public */,
       7,    0,   75,    2, 0x06 /* Public */,
       8,    1,   76,    2, 0x06 /* Public */,
      10,    2,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    1,   84,    2, 0x0a /* Public */,
      14,    1,   87,    2, 0x0a /* Public */,
      16,    2,   90,    2, 0x0a /* Public */,
      16,    1,   95,    2, 0x2a /* Public | MethodCloned */,
      18,    0,   98,    2, 0x0a /* Public */,
      19,    1,   99,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   12,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    3,   17,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,   20,

       0        // eod
};

void gameMap::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        gameMap *_t = static_cast<gameMap *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->playerTurnStart((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->SIGnote((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 2: _t->SIGcreatedNewMap(); break;
        case 3: _t->SIGwin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->SIGupdateAM((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->SIGnoteRecieved((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 6: _t->clickHandler((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->newTurn((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 8: _t->newTurn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->create(); break;
        case 10: _t->gameSave((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (gameMap::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&gameMap::playerTurnStart)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (gameMap::*)(std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&gameMap::SIGnote)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (gameMap::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&gameMap::SIGcreatedNewMap)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (gameMap::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&gameMap::SIGwin)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (gameMap::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&gameMap::SIGupdateAM)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject gameMap::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_gameMap.data,
      qt_meta_data_gameMap,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *gameMap::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *gameMap::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_gameMap.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int gameMap::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void gameMap::playerTurnStart(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void gameMap::SIGnote(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void gameMap::SIGcreatedNewMap()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void gameMap::SIGwin(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void gameMap::SIGupdateAM(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
struct qt_meta_stringdata_fieldButton_t {
    QByteArrayData data[8];
    char stringdata0[68];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_fieldButton_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_fieldButton_t qt_meta_stringdata_fieldButton = {
    {
QT_MOC_LITERAL(0, 0, 11), // "fieldButton"
QT_MOC_LITERAL(1, 12, 7), // "SIGnote"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 11), // "std::string"
QT_MOC_LITERAL(4, 33, 4), // "text"
QT_MOC_LITERAL(5, 38, 10), // "SIGclicked"
QT_MOC_LITERAL(6, 49, 8), // "buttonID"
QT_MOC_LITERAL(7, 58, 9) // "sendClick"

    },
    "fieldButton\0SIGnote\0\0std::string\0text\0"
    "SIGclicked\0buttonID\0sendClick"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_fieldButton[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       5,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    6,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void fieldButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        fieldButton *_t = static_cast<fieldButton *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SIGnote((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 1: _t->SIGclicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->sendClick(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (fieldButton::*)(std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&fieldButton::SIGnote)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (fieldButton::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&fieldButton::SIGclicked)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject fieldButton::staticMetaObject = {
    { &QToolButton::staticMetaObject, qt_meta_stringdata_fieldButton.data,
      qt_meta_data_fieldButton,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *fieldButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *fieldButton::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_fieldButton.stringdata0))
        return static_cast<void*>(this);
    return QToolButton::qt_metacast(_clname);
}

int fieldButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QToolButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void fieldButton::SIGnote(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void fieldButton::SIGclicked(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_unitInfo_t {
    QByteArrayData data[1];
    char stringdata0[9];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_unitInfo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_unitInfo_t qt_meta_stringdata_unitInfo = {
    {
QT_MOC_LITERAL(0, 0, 8) // "unitInfo"

    },
    "unitInfo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_unitInfo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void unitInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject unitInfo::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_unitInfo.data,
      qt_meta_data_unitInfo,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *unitInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *unitInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_unitInfo.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int unitInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
