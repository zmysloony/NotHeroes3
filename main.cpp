#include <QApplication>
#include <QPushButton>
#include <QObject>
#include <QLabel>
#include <iostream>
#include <fstream>
#include <regex>
#include <time.h>
#include "menu.h"


int main(int argc, char **argv) {
 srand(static_cast<unsigned int>(time(nullptr)));
 QApplication app (argc, argv);
 QWidget mainWindow;
 gameMap _gameMap (&mainWindow);
 mainWindow.setFixedSize(900,600);
 loadButton _loadButton(&mainWindow);
 saveButton _saveButton (&mainWindow);
 am _am(&mainWindow);
 comms _comms(&mainWindow);


 QObject::connect(&_gameMap, &gameMap::SIGcreatedNewMap, &_saveButton, &saveButton::enableSave);
 QObject::connect(&_gameMap, &gameMap::SIGcreatedNewMap, &_comms, &comms::flush);
 QObject::connect(&_loadButton, &loadButton::clicked, &_loadButton, &loadButton::loadSave);
 QObject::connect(&_loadButton, &loadButton::SIGcreateMap, &_gameMap, &gameMap::create);
 QObject::connect(&_loadButton, &loadButton::SIGnote, &_comms, &comms::recieveMsg);
 QObject::connect(&_saveButton, &saveButton::clicked, &_saveButton, &saveButton::save);
 QObject::connect(&_saveButton, &saveButton::SIGgameSave, &_gameMap, &gameMap::gameSave);
 QObject::connect(&_gameMap, &gameMap::SIGnote, &_comms, &comms::recieveMsg);
 QObject::connect(&_gameMap, &gameMap::SIGwin, &_comms, &comms::winRecieve);
 QObject::connect(&_gameMap, &gameMap::SIGupdateAM, &_am, &am::update);

 QWidget infoTable(&mainWindow);
 infoTable.setGeometry(530,10,350,180);
 unitInfo warriorInfo(T_Warrior, &infoTable);
 warriorInfo.setGeometry(0,10,90,120);
 unitInfo hussarInfo(T_Hussar, &infoTable);
 hussarInfo.setGeometry(90,10,90,120);
 unitInfo archerInfo(T_Archer, &infoTable);
 archerInfo.setGeometry(180,10,90,120);
 unitInfo mageInfo(T_Mage, &infoTable);
 mageInfo.setGeometry(270,10,90,120);
 infoTable.show();

 mainWindow.show();
 return app.exec();
}
