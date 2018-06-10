#include <menu.h>
#define BLOCK "\t***Blocked!***\n"
crd numToCrd(int field, int size) {
    crd result;
    result.x = field%size;
    result.y = field/size;
    return result;
}

int countDistance(int fieldA, int fieldB, int size) {
    crd fcrdA = numToCrd(fieldA, size);
    crd fcrdB = numToCrd(fieldB, size);
    int x = fcrdA.x - fcrdB.x;
    int y = fcrdA.y - fcrdB.y;
    return static_cast<int>(floor(sqrt(x*x+y*y)));
}

baseUnit* unitFromString(std::string unitData,int owner, int mapSize) {
    size_t limit = unitData.find(",");
    std::string token = unitData.substr(0, limit);
    int tempUnitCount = std::stoi(token);
    if(tempUnitCount<=0) throw std::runtime_error("Corrupt savefile (unitCount lower than 0)!");
    unitData.erase(0, limit+1);

    limit = unitData.find(",");
    token = unitData.substr(0,limit);
    int tempLastUnitHP = std::stoi(token);
    unitData.erase(0, limit+1);

    limit = unitData.find(",");
    token = unitData.substr(0,limit);
    int type = static_cast<int> (token[0]);
    unitData.erase(0, limit+1);

    limit = unitData.find("]");
    token = unitData.substr(0,limit);
    int pos = std::stoi(token);
    if(pos>=(mapSize*mapSize)) throw std::runtime_error("Corrupt savefile (unit position out of bounds)!");
    unitData.erase(0, limit+1);

    baseUnit* newUnit=nullptr;

    switch(type){
    case 65: //Archer
        if(tempLastUnitHP>10 || tempLastUnitHP<=0) throw std::runtime_error("Corrupt savefile (lastUnitHP <= 0 or too high)!");
        newUnit = new archer(tempUnitCount, tempLastUnitHP, pos, owner);
        return newUnit;
    case 87: //Warrior
        if(tempLastUnitHP>18 || tempLastUnitHP<=0) throw std::runtime_error("Corrupt savefile (lastUnitHP <= 0 or too high)!");
        newUnit = new warrior(tempUnitCount, tempLastUnitHP, pos, owner);
        return newUnit;
    case 72: //Hussar
        if(tempLastUnitHP>25 || tempLastUnitHP<=0) throw std::runtime_error("Corrupt savefile (lastUnitHP <= 0 or too high)!");
        newUnit = new hussar(tempUnitCount, tempLastUnitHP, pos, owner);
        return newUnit;
    case 77: //Mage
        if(tempLastUnitHP>9 || tempLastUnitHP<=0) throw std::runtime_error("Corrupt savefile (lastUnitHP <= 0 or too high)!");
        newUnit = new mage(tempUnitCount, tempLastUnitHP, pos, owner);
        return newUnit;
    default:
        throw "Corrupt savefile (incorrect unit type)!";
    }


}

std::string baseUnit::attNotification(int damage, int position) {
    std::string result;
    gameMap* map = dynamic_cast<gameMap*>(button->parentWidget());
    if(owner==1) result = "RED "; else result = "BLUE ";
    result += name.toStdString();
    if(amount!=1) result += "s";
    result += " attacked ";
    if(map->fields[static_cast<unsigned long>(position)]->unit->owner==1) result += "RED "; else result += "BLUE ";
    result += (map->fields[static_cast<unsigned long>(position)]->unit->name).toStdString();
    if(map->fields[static_cast<unsigned long>(position)]->unit->amount!=1) result += "s";
    result += " for ";
    result += std::to_string(damage);
    result += " damage.\n";
    return result;
}

std::string baseUnit::attack(int position) {

    double r = rand()%41-20;            //20% rng
    int damageDealt = static_cast<int>(dmgM*amount*((100+r)/100));
    gameMap* map = dynamic_cast<gameMap*>(button->parentWidget());
    baseUnit* target = map->fields[static_cast<unsigned long>(position)]->unit;
    int hpBefore = (target->amount-1)*target->maxHP+target->lastUnitHP;
    std::string text = attNotification(damageDealt, position);
    target->takeDmg(damageDealt);
    if(hpBefore==((target->amount-1)*target->maxHP+target->lastUnitHP)) {
        text += BLOCK;
    }
    map->attackTurn = 0;
    map->fields[static_cast<unsigned long>(position)]->checkHP();
    map->fields[static_cast<unsigned long>(position)]->displayUnit();
    return text;
}
void baseUnit::takeDmg(int n) {
    int actualHP = maxHP*(amount-1)+lastUnitHP-n;
    if(actualHP<=0) {
        amount = 0;
        return;
    }
    amount = actualHP/maxHP+1;
    lastUnitHP = actualHP%maxHP;
}
void baseUnit::move(int position) {
    gameMap* map = dynamic_cast<gameMap*>(button->parentWidget());
    map->fields[static_cast<unsigned long>(position)]->unit = this;
    map->fields[static_cast<unsigned long>(position)]->displayUnit();
    map->fields[static_cast<unsigned long>(pos)]->unit = nullptr;
    map->fields[static_cast<unsigned long>(pos)]->displayUnit();
    pos = position;
    map->moveTurn = 0;
}


//          ARCHER

archer::archer(int newAmount, int newLastUnitHP, int newPos, int newOwner) {
    owner = newOwner;
    type = T_Archer;
    amount = newAmount;
    lastUnitHP = newLastUnitHP;
    pos = newPos;
    maxHP = 10;
    range = 10;
    dmgM = 2;
    dmgR = 5;
    speed = 2;
    name = "Archer";
}
std::string archer::attack(int position) {
    int dmg;
    if(countDistance(pos,position,(dynamic_cast<gameMap*>(button->parentWidget()))->size)==1) {
        dmg = dmgM;
    } else {
        dmg = dmgR;
    }
    double r = rand()%41-20;            //20% rng
    int damageDealt = static_cast<int>(dmg*amount*((100+r)/100));
    gameMap* map = dynamic_cast<gameMap*>(button->parentWidget());
    baseUnit* target = map->fields[static_cast<unsigned long>(position)]->unit;
    int hpBefore = (target->amount-1)*target->maxHP+target->lastUnitHP;
    std::string text = attNotification(damageDealt, position);
    target->takeDmg(damageDealt);
    if(hpBefore==((target->amount-1)*target->maxHP+target->lastUnitHP)) {
        text += BLOCK;
    }
    map->attackTurn = 0;
    map->fields[static_cast<unsigned long>(position)]->checkHP();
    map->fields[static_cast<unsigned long>(position)]->displayUnit();
    return text;
}


//          WARRIOR

warrior::warrior(int newAmount, int newLastUnitHP, int newPos, int newOwner) {
    owner = newOwner;
    type = T_Warrior;
    amount = newAmount;
    lastUnitHP = newLastUnitHP;
    pos = newPos;
    maxHP = 18;
    range = 1;
    dmgM = 11;
    dmgR = 0;
    speed = 3;
    blockChance = 30;
    name = "Warrior";
}

void warrior::takeDmg(int n) {

    if(rand()%101<=(blockChance+1)) {    //block
        return;
    }
    int actualHP = maxHP*(amount-1)+lastUnitHP-n;
    if(actualHP<=0) {
        amount = 0;
        return;
    }
    amount = actualHP/maxHP+1;
    lastUnitHP = actualHP%maxHP;
}

//          HUSSAR

hussar::hussar(int newAmount, int newLastUnitHP, int newPos, int newOwner) {
    owner = newOwner;
    type = T_Hussar;
    amount = newAmount;
    lastUnitHP = newLastUnitHP;
    pos = newPos;
    maxHP = 25;
    range = 1;
    dmgM = 7;
    dmgR = 0;
    speed = 4;
    dmgPerTile = 4;
    travelled = 0;
    name = "Hussar";
}
std::string hussar::attack(int position) {

    double r = rand()%41-20;            //20% rng
    int damageDealt = (dmgM+dmgPerTile*travelled)*amount*static_cast<int>((100+r)/100) ;
    gameMap* map = dynamic_cast<gameMap*>(button->parentWidget());
    baseUnit* target = map->fields[static_cast<unsigned long>(position)]->unit;
    int hpBefore = (target->amount-1)*target->maxHP+target->lastUnitHP;
    std::string text = attNotification(damageDealt, position);
    target->takeDmg(damageDealt);
    if(hpBefore==((target->amount-1)*target->maxHP+target->lastUnitHP)) {
        text += BLOCK;
    }
    map->attackTurn = 0;
    map->fields[static_cast<unsigned long>(position)]->checkHP();
    map->fields[static_cast<unsigned long>(position)]->displayUnit();
    return text;
}

void hussar::move(int position) {
    gameMap* map = dynamic_cast<gameMap*>(button->parentWidget());
    travelled = countDistance(pos, position, map->size);
    map->fields[static_cast<unsigned long>(position)]->unit = this;
    map->fields[static_cast<unsigned long>(position)]->displayUnit();
    map->fields[static_cast<unsigned long>(pos)]->unit = nullptr;
    map->fields[static_cast<unsigned long>(pos)]->displayUnit();
    pos = position;
    map->moveTurn = 0;
}

//          MAGE

mage::mage(int newAmount, int newLastUnitHP, int newPos, int newOwner) {
    owner = newOwner;
    type = T_Mage;
    amount = newAmount;
    lastUnitHP = newLastUnitHP;
    pos = newPos;
    maxHP = 9;
    range = 20;
    dmgM = 0;
    dmgR = 6;
    speed = 2;
    name = "Mage";
}
std::string mage::attack(int position) {
    gameMap* map = dynamic_cast<gameMap*>(button->parentWidget());

    double r = rand()%41-20;            //20% rng
    int damageDealt = static_cast<int>(dmgR*amount*((100+r)/100)) ;
    baseUnit* target;
    std::string text = "";
    for (int i=0; i<(map->size)*(map->size); i++) {
        if (map->fields[static_cast<unsigned long>(i)]->unit==nullptr || countDistance(position, i, map->size)>1) continue;
        target = map->fields[static_cast<unsigned long>(i)]->unit;
        int hpBefore = (target->amount-1)*target->maxHP+target->lastUnitHP;
        text += attNotification(damageDealt, i);
        target->takeDmg(damageDealt);
        if(hpBefore==((target->amount-1)*target->maxHP+target->lastUnitHP)) {
            text += BLOCK;
        }
        map->attackTurn = 0;
        map->fields[static_cast<unsigned long>(i)]->checkHP();
        map->fields[static_cast<unsigned long>(i)]->displayUnit();
    }
    return text;
}

