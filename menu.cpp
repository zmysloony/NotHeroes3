#include <iostream>
#include <fstream>
#include <QString>
#include <QPushButton>
#include <QToolButton>
#include <QScrollBar>
#include <vector>
#include <regex>
#include "menu.h"


bool fileExists(std::string fileName){
    std::ifstream infile(fileName);
    bool val = static_cast<bool>(infile);
    infile.close();
    return val;
}


loadButton::loadButton(QWidget *parent) : QPushButton(parent) {
    if(!fileExists("save0.txt")) {
        setText("save0.txt missing");
        setStyleSheet("QPushButton { color: red;}");
    } else {
        setText("Load from save0.txt");
    }
    setGeometry(0,0,150,26);
}
void loadButton::loadSave() {
    if(!fileExists("save0.txt")) {
        setText("save0.txt missing");
        setStyleSheet("QPushButton { color: red;}");
        return;
    }
    setText("Load from save0.txt");
    setStyleSheet("QPushButton { color: black;}");
    try {
        emit SIGcreateMap();
    } catch (std::runtime_error error) {
        std::string sendText = error.what();
        sendText += '\n';
        emit SIGnote(sendText);
    } catch (std::invalid_argument error) {
        emit SIGnote("Corrupt savefile!\n");
    }

    return;
}
void saveButton::save() {
    if(fileExists(newName.toStdString())) {
        std::string notification = "File ";
        notification += newName.toStdString() += " already exists!\n";
        availableSavename();
        emit SIGnote(notification);
        return;
    }
    emit SIGgameSave(newName.toStdString());
    availableSavename();
    return;
}
void saveButton::availableSavename() {
    int i = 0;
    std::string name = "save0.txt";
    while(fileExists(name)) {
        i++;
        name = "save";
        name += std::to_string(i);
        name += ".txt";
    }
    newName = "save";
    newName.append(QString::number(i));
    newName.append(".txt");
    QString nameQ = "Save as ";
    nameQ.append(newName);
    setText(nameQ);
}
saveButton::saveButton(QWidget *parent) : QPushButton(parent) {
    availableSavename();
    setEnabled(false);
    setGeometry(175,0,150,26);
}

void saveButton::enableSave() {
    setEnabled(true);
}
fieldButton::fieldButton(QWidget *parent) : QToolButton(parent) {
    unit = nullptr;
    setStyleSheet("QLineEdit { background-color: yellow }");
    QObject::connect(this, &fieldButton::clicked, this, &fieldButton::sendClick);
    QObject::connect(this, &fieldButton::SIGclicked, dynamic_cast<gameMap*>(parentWidget()), &gameMap::clickHandler);
    QObject::connect(this, &fieldButton::SIGnote, dynamic_cast<gameMap*>(parentWidget()), &gameMap::SIGnoteRecieved);
}
void fieldButton::sendClick() {
    emit SIGclicked(id);
}
void fieldButton::checkHP() {
    if(unit->amount!=0) return;
    delete unit;
    unit = nullptr;
    return;
}
bool fieldButton::canAttack(fieldButton *target) {
    int size = (dynamic_cast<gameMap*>(parentWidget()))->size;
    if (countDistance(unit->pos, target->id, size)>(unit->range)) return 0;
    if (unit->type==T_Mage && countDistance(unit->pos, target->id, size)==1) return 0;
    return 1;
}
bool fieldButton::canMove(fieldButton *target) {
    int size = (dynamic_cast<gameMap*>(parentWidget()))->size;
    if (countDistance(unit->pos, target->id, size)>(unit->speed)) return 0;
    return 1;
}
void fieldButton::displayUnit() {
    if(unit==nullptr) {
        setIcon(QIcon());
        setToolTip("empty");
        setStyleSheet("");
        return;
    }
    QString tooltip = QString::number(unit->amount);
    tooltip.append(" ");
    tooltip.append(unit->name);
    if(unit->amount>1) tooltip.append("s");
    tooltip.append("\nHP:");
    tooltip.append(QString::number((unit->maxHP)*(unit->amount-1)+unit->lastUnitHP));
    tooltip.append("/");
    tooltip.append(QString::number((unit->maxHP)*(unit->amount)));
    if(unit->owner==1){
        setStyleSheet("QToolTip { color: #ffffff; background-color: #ff4d4d; border: 1px solid white;}");
    } else {
        setStyleSheet("QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white;}");
    }

    setToolTip(tooltip);
    int tilesize = 525/(dynamic_cast<gameMap*>(parentWidget())->size);
    int pngid = (static_cast<int>(unit->type))+4*(unit->owner-1);
    QIcon ButtonIcon((dynamic_cast<gameMap*>(parentWidget())->unitsPNG[pngid]).scaled(tilesize, tilesize, Qt::KeepAspectRatio, Qt::FastTransformation));
    setIcon(ButtonIcon);
    setIconSize(QSize(tilesize, tilesize));

}

am::am(QWidget *parent) : QLabel(parent) {
    setGeometry(370,3,250,40);
    setAlignment(Qt::AlignLeft);
}
void am::update(int m, int a) {
    QString text = "Attacks left: ";
    text.append(QString::number(a));
    text.append("\nMoves left: ");
    text.append(QString::number(m));
    setText(text);
}


comms::comms(QWidget *parent) : QTextEdit(parent) {
    setGeometry(530,150,350,400);
    setReadOnly(true);
    setAlignment(Qt::AlignLeft);
}

void comms::recieveMsg(std::string addText) {
    insertPlainText(QString::fromStdString(addText));
    QScrollBar* sb = verticalScrollBar();
    sb->setValue(sb->maximum());
}

void comms::winRecieve(int winner) {
    if(winner==0)
        setText("RED PLAYER HAS WON THE GAME!");
    setText("BLUE PLAYER HAS WON THE GAME!");
}

void comms::flush() {
    setText("");
}



void gameMap::create() {
    for(int i=0; i<size*size; i++) {
        //(*(fields.begin()+i))->close();

       delete (fields[static_cast<unsigned long>(i)]);
    }
    fields.clear();
    std::ifstream infile("save0.txt");
    std::string tempStr;
    std::getline(infile, tempStr);
    int sizeT = std::stoi(tempStr);
    std::getline(infile, tempStr);
    int moveTurnT = std::stoi(tempStr);
    std::getline(infile, tempStr);
    int attackTurnT = std::stoi(tempStr);
    size = sizeT;
    moveTurn = moveTurnT;
    attackTurn = attackTurnT;
    if(size>25) throw std::runtime_error("Can't load - map size bigger than 25");
    //  creating empty battlefield
    int tilesize = 525/size;
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            fieldButton* newButton = new fieldButton(this);
            fields.push_back(newButton);
            (*(fields.begin()+(i*size+j)))->setGeometry(tilesize*j,tilesize*i,tilesize,tilesize);
            int id = i*size+j;
            (*(fields.begin()+(i*size+j)))->id = id;
            (*(fields.begin()+(i*size+j)))->setToolTip(QString::number(id));
            (*(fields.begin()+(i*size+j)))->show();
        }
    }

    //creating units
    for(int i=1; i<=2; i++) {
        std::getline(infile, tempStr);
        std::regex regexBrackets("\\[([0-9]+,[0-9]+,[a-zA-Z]+,[0-9]+\\])");
        std::sregex_iterator next(tempStr.begin(), tempStr.end(), regexBrackets);
        std::sregex_iterator end;
        while (next != end) {
            std::smatch match = *next;
            baseUnit* newUnit = unitFromString(match[1], i, size);
            fieldButton* thisButton = *(fields.begin()+newUnit->pos);
            thisButton->unit = newUnit;
            thisButton->unit->button = thisButton;
            //  display unit on buttons
            thisButton->displayUnit();

            next++;
        }
    }

    infile.close();
    if(attackTurn+moveTurn==0) {
        newTurn(2);
    } else {
        newTurn(1,true);
    }

    emit SIGcreatedNewMap();
    return;
}
void gameMap::gameSave(std::string filename) {
    std::string toSave[2]={""};
    baseUnit * unit;
    for(int i=0; i<size*size; i++) {
        if(fields[static_cast<unsigned long>(i)]->unit==nullptr) continue;
        unit = fields[static_cast<unsigned long>(i)]->unit;
        toSave[(unit->owner)-1] += "[";
        toSave[(unit->owner)-1] += std::to_string(unit->amount);
        toSave[(unit->owner)-1] += ",";
        toSave[(unit->owner)-1] += std::to_string(unit->lastUnitHP);
        toSave[(unit->owner)-1] +=",";
        toSave[(unit->owner)-1] += (unit->name.toStdString())[0];
        toSave[(unit->owner)-1] +=",";
        toSave[(unit->owner)-1] +=std::to_string(unit->pos);
        toSave[(unit->owner)-1] +="]";
    }
    std::ofstream outputFstream(filename);
    outputFstream << size << std::endl << moveTurn << std::endl << attackTurn << std::endl << toSave[0] << std::endl << toSave[1];
    outputFstream.close();
    emit SIGnote("Saved as "+filename+".\n");
    return;
}
gameMap::gameMap(QWidget *parent) : QWidget(parent) {
    unitsPNG[0] = QPixmap("res/archer.png");
    unitsPNG[1] = QPixmap("res/warrior.png");
    unitsPNG[2] = QPixmap("res/hussar.png");
    unitsPNG[3] = QPixmap("res/mage.png");
    unitsPNG[4] = QPixmap("res/archerF.png");
    unitsPNG[5] = QPixmap("res/warriorF.png");
    unitsPNG[6] = QPixmap("res/hussarF.png");
    unitsPNG[7] = QPixmap("res/mageF.png");



    size = 0;
    setGeometry(0,40,525,525);
}
void gameMap::SIGnoteRecieved(std::string text) {
    emit SIGnote(text);
}
void gameMap::newTurn(int playerId, bool over) {
    bool resethussars = 1;
    if(playerId==player) resethussars=0;
    player = playerId;
    if(over==false) {
        attackTurn = 1;
        moveTurn = 1;
    }
    stateCode = 0;
    activeUnit = -1;
    bool isWon[2] = {true};
    for(int i=0; i<size*size; i++) {
        if(fields[static_cast<unsigned long>(i)]->unit==nullptr) {
            fields[static_cast<unsigned long>(i)]->displayUnit();
            fields[static_cast<unsigned long>(i)]->setEnabled(false);
            continue;

        }
        isWon[fields[static_cast<unsigned long>(i)]->unit->owner-1] = false;
        if(fields[static_cast<unsigned long>(i)]->unit->owner!=player) {
            fields[static_cast<unsigned long>(i)]->displayUnit();
            fields[static_cast<unsigned long>(i)]->setEnabled(false);
            continue;

        }
        if(resethussars && fields[static_cast<unsigned long>(i)]->unit->type==T_Hussar) {
                (dynamic_cast<hussar*>(fields[static_cast<unsigned long>(i)]->unit))->travelled = 0;
        }

        fields[static_cast<unsigned long>(i)]->setStyleSheet("QToolButton:{}");
        fields[static_cast<unsigned long>(i)]->setEnabled(true);
        fields[static_cast<unsigned long>(i)]->displayUnit();
    }
    if(isWon[0]==true) {
        emit SIGwin(0);
        buttonActivate(false);
        return;
    }
    if(isWon[1]==true) {
        emit SIGwin(1);
        buttonActivate(false);
    }
    emit SIGupdateAM(moveTurn, attackTurn);
}
void gameMap::buttonActivate(bool yes, int buttonID) {
    if(buttonID==-1) {
        for(int i=0; i<size*size; i++) {
            fields[static_cast<unsigned long>(i)]->setEnabled(yes);
        }
        return;
    }
    fields[static_cast<unsigned long>(buttonID)]->setEnabled(yes);
}
void gameMap::clickHandler(int buttonID) {
    switch(stateCode) {
    case 0: //display an action selection menu

        buttonActivate(false);
        for(int i=0; i<size*size; i++) {
            if(attackTurn && fields[static_cast<unsigned long>(i)]->unit!=nullptr && fields[static_cast<unsigned long>(i)]->unit->owner!=player && fields[static_cast<unsigned long>(buttonID)]->canAttack(fields[static_cast<unsigned long>(i)])) {
                buttonActivate(true, i);
                if(player==1) {
                    fields[static_cast<unsigned long>(i)]->setStyleSheet("QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white;} QToolButton { background-color: #ffd175 }");
                } else {
                    fields[static_cast<unsigned long>(i)]->setStyleSheet("QToolTip { color: #ffffff; background-color: #ff4d4d; border: 1px solid white;} QToolButton { background-color: #ffd175 }");
                }
            }
            if(moveTurn && fields[static_cast<unsigned long>(i)]->unit==nullptr && fields[static_cast<unsigned long>(buttonID)]->canMove(fields[static_cast<unsigned long>(i)])) {
                buttonActivate(true, i);
                fields[static_cast<unsigned long>(i)]->setStyleSheet("QToolTip { color: #ffffff; background-color: #a0ff96; border: 1px solid white;} QToolButton { background-color: #a0ff96 }");
            }
        }

        activeUnit = buttonID;
        fields[static_cast<unsigned long>(activeUnit)]->setEnabled(true);
        if(player==1) {
            fields[static_cast<unsigned long>(activeUnit)]->setStyleSheet("QToolTip { color: #ffffff; background-color: #ff4d4d; border: 1px solid white;} QToolButton { background-color: #bcf9ff }");
        } else {
            fields[static_cast<unsigned long>(activeUnit)]->setStyleSheet("QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white;} QToolButton { background-color: #bcf9ff }");
        }

        stateCode = 1;
        break;
    case 1:
        if(buttonID==activeUnit) {  //cancel the selection
            newTurn(player, true);
            return;
        }
        if(fields[static_cast<unsigned long>(buttonID)]->unit!=nullptr) {
            emit SIGnote(fields[static_cast<unsigned long>(activeUnit)]->unit->attack(buttonID));
            if(!attackTurn && !moveTurn) {
                newTurn(player%2+1);
            }   else    {
                newTurn(player, true);
            }
        } else {
            fields[static_cast<unsigned long>(activeUnit)]->unit->move(buttonID);
            bool noActions = true;
            for(int j=0; j<size*size; j++) {
                if(fields[static_cast<unsigned long>(j)]->unit==nullptr) continue;
                for(int i=0; i<size*size; i++) {
                    if(attackTurn && fields[static_cast<unsigned long>(i)]->unit!=nullptr && fields[static_cast<unsigned long>(i)]->unit->owner!=player && fields[static_cast<unsigned long>(j)]->canAttack(fields[static_cast<unsigned long>(i)])) {
                        noActions = false;
                        break;
                    }
                    if(moveTurn && fields[static_cast<unsigned long>(i)]->unit==nullptr && fields[static_cast<unsigned long>(j)]->canMove(fields[static_cast<unsigned long>(i)])) {
                        noActions = false;
                        break;
                    }
                }
            }
            if(noActions) {
                newTurn(player%2+1);
            }   else    {
                newTurn(player, true);
            }
        }
        break;

    }
}

unitInfo::unitInfo(unitTypes typeU, QWidget *parent): QWidget(parent) {
    std::string damage, additional;

    text = new QLabel(this);
    icon = new QLabel(this);

    if(typeU==T_Warrior) {
        unit = new warrior(1,1,0,0);
        icon->setPixmap(QPixmap("res/warrior.png"));
        damage = std::to_string(unit->dmgM);
        additional = "*";
        additional += std::to_string(dynamic_cast<warrior*>(unit)->blockChance);
        additional += "% to block an attack*";
    }
    if(typeU==T_Archer) {
        unit = new archer(1,1,0,0);
        icon->setPixmap(QPixmap("res/archer.png"));
        damage = std::to_string(unit->dmgR);
        damage += "/";
        damage += std::to_string(unit->dmgM);
    }
    if(typeU==T_Mage) {
        unit = new mage(1,1,0,0);
        icon->setPixmap(QPixmap("res/mage.png"));
        damage = std::to_string(unit->dmgR);
        damage += "/";
        damage += std::to_string(unit->dmgM);
        additional = "*attacks in a 3x3 area*";
    }
    if(typeU==T_Hussar) {
        unit = new hussar(1,1,0,0);
        icon->setPixmap(QPixmap("res/hussar.png"));
        damage = std::to_string(unit->dmgM);
        additional = "*+";
        additional += std::to_string(dynamic_cast<hussar*>(unit)->dmgPerTile);
        additional += " dmg per travelled tile*";
    }
    QString string = unit->name;
    text->setStyleSheet("font: 7pt;");
    string.append(":\n  HP: ");
    string.append(QString::number(unit->maxHP));
    string.append("\n  damage: ");
    string.append(QString::fromStdString(damage));
    string.append("\n  range: ");
    string.append(QString::number(unit->range));
    string.append("\n  speed: ");
    string.append(QString::number(unit->speed));
    string.append("\n");
    string.append(QString::fromStdString(additional));
    text->setText(string);
    setGeometry(0,0,90,120);
    icon->setGeometry(0,0,28,28);
    text->setAlignment(Qt::AlignLeft);
    text->setWordWrap(true);
    text->setGeometry(0,30,60,92);
    icon->setScaledContents(true);
}
