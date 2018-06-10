#ifndef MENU_H
#define MENU_H
#include <QWidget>
#include <QToolButton>
#include <QObject>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>
#include <vector>
#include <math.h>
enum unitTypes
{
   T_Archer,
   T_Warrior,
   T_Hussar,
   T_Mage
};

struct crd {    //x,y coordinates
    int x;
    int y;
};
crd numToCrd(int field, int size);
int countDistance(int fieldA, int fieldB, int size);

class fieldButton;

class baseUnit {
public:
    unitTypes type;
    QString name;
    int owner;
    int amount;
    int lastUnitHP;
    int maxHP;
    int pos;
    //static stats
    int dmgR;
    int dmgM;
    int range;
    int speed;

    fieldButton* button;
    std::string attNotification(int damage, int position);
    virtual void takeDmg(int n);
    virtual std::string attack(int position);
    virtual void move(int position);
    virtual ~baseUnit() = default;
};

baseUnit *unitFromString(std::string unitData, int owner, int mapSize);

class archer: public baseUnit {
public:
    archer(int newAmount, int newLastUnitHP, int newPos, int newOwner);
    std::string attack(int position);

};
class warrior: public baseUnit {
public:
    int blockChance;
    warrior(int newAmount, int newLastUnitHP, int newPo, int newOwner);
    void takeDmg(int n);
};
class hussar: public baseUnit {
public:
    int dmgPerTile;
    int travelled;
    hussar(int newAmount, int newLastUnitHP, int newPos, int newOwner);
    std::string attack(int position);
    void move(int position);
};
class mage: public baseUnit {
public:
    mage(int newAmount, int newLastUnitHP, int newPos, int newOwner);
    std::string attack(int position);
};


class loadButton: public QPushButton {
    Q_OBJECT

public:
        loadButton(QWidget *parent = nullptr);
signals:
    void SIGcreateMap();
    void SIGnote(std::string text);
public slots:
    void loadSave();
};

class saveButton: public QPushButton {
    Q_OBJECT
public:
        QString newName;
        saveButton(QWidget *parent = nullptr);
        void availableSavename();
signals:
        void SIGnote(std::string text);
        void SIGgameSave(std::string filename);
public slots:
        void enableSave();
        void save();
};

class am: public QLabel {
    Q_OBJECT
public:
    am(QWidget *parent = nullptr);
public slots:
    void update(int m, int a);
};

class comms: public QTextEdit {
    Q_OBJECT
public:
    comms(QWidget *parent = nullptr);
public slots:
    void recieveMsg(std::string addText);
    void flush();
    void winRecieve(int winner);
};

class gameMap: public QWidget {
    Q_OBJECT
public:
    QPixmap unitsPNG[8];

    bool moveTurn;
    bool attackTurn;
    int player;
    int activeUnit;
    int stateCode;
    int size;

    std::vector<fieldButton*> fields;
    gameMap(QWidget *parent = nullptr);
    void buttonActivate(bool yes, int buttonID=-1);
signals:
    void playerTurnStart(int playerId);
    void SIGnote(std::string text);
    void SIGcreatedNewMap();
    void SIGwin(int winner);
    void SIGupdateAM(int a, int t);
public slots:
    void SIGnoteRecieved(std::string text);
    void clickHandler(int buttonID);
    void newTurn(int playerId, bool over = false);
    void create();
    void gameSave(std::string filename);
};

class fieldButton: public QToolButton {
    Q_OBJECT
public:
    int id;
    baseUnit* unit;
    fieldButton(QWidget *parent = nullptr);
    void displayUnit();
    bool canAttack(fieldButton* target);
    bool canMove(fieldButton* target);
    void checkHP();
signals:
    void SIGnote(std::string text);
    void SIGclicked(int buttonID);
public slots:
    void sendClick();
};

class unitInfo: public QWidget {
    Q_OBJECT
public:
    unitInfo(unitTypes typeU, QWidget *parent = nullptr);
    QLabel* icon;
    QLabel* text;
    baseUnit* unit;
};
#endif // MENU_H
