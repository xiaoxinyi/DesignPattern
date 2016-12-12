// Copyright zhangli

#include <cstring>
#include <iostream>
#include <memory>
#include <string>



using std::unique_ptr;
using std::make_shared;
using std::shared_ptr;
using std::cout;
using std::endl;
using std::string;
using std::unique_ptr;
using std::string;

// =======================================================
// ESEngine
// =======================================================


class ESEngine {
 public:
  virtual string toString() = 0;
  virtual ~ESEngine() {}
};


// =======================================================
// ESWeapon
// =======================================================

class ESWeapon {
 public:
  virtual string toString() = 0;
  virtual ~ESWeapon() {}
};

class ESUFOGun : public ESWeapon{
 public:
  string toString() { return string("20 damage"); }
};

class ESUFOEngine : public ESEngine {
 public:
  string toString() { return string("1000 mph"); }
};

class ESUFOBossGun : public ESWeapon {
 public:
  string toString() { return string("40 damage"); }
};

class ESUFOBossEngine : public ESEngine {
 public:
  string toString() { return string("2000 mph"); }
};


// =======================================================
// EnemyShip
// =======================================================


class EnemyShip {
 public:
  virtual void makeShip() = 0;
  void displayEnemyShip();
  void followHeroShip();
  void enemyShipShoots();
  virtual string toString();
 public:
  unique_ptr<ESEngine> engine;
  unique_ptr<ESWeapon> weapon;

  string getName() const { return name_; }
  void setName(const string& value) { name_ = value; }


  virtual ~EnemyShip() {}
 protected:
  string name_;
};

void EnemyShip::displayEnemyShip() {
  cout << name_ << " is on the screen" << endl;
}

void EnemyShip::enemyShipShoots() {
  cout << name_ << " attacks and does " << weapon->toString() << endl;
}

void EnemyShip::followHeroShip() {
  cout << name_ << " is following the hero at " << engine->toString() << endl;
}

string EnemyShip::toString() {
  string infoOnShip = "the " + name_ + " has a top speed of ";
  infoOnShip += engine->toString();
  infoOnShip += " and an attack power of " + weapon->toString();
  return infoOnShip;
}


// =======================================================
// EnemyShipFactory
// =======================================================


// With an Abstract Factory Pattern you won't
// just build ships, but also all of the components
// for the ships

// Here is where you define the parts that are required
// if an object wants to be an enemy ship
class EnemyShipFactory {
 public:
  virtual unique_ptr<ESWeapon> addESGun() = 0;
  virtual unique_ptr<ESEngine> addESEngine() = 0;
  virtual ~EnemyShipFactory() {}
};

// This factory uses the EnemyShipFactory interface
// to create very specific UFO Enemy Ship

// This is where we define all of the parts the ship
// will use by defining the methods implemented
// being ESWeapon and ESEngine

// The return object specifies a specific weapon & engine.
class UFOEnemyShipFactory : public EnemyShipFactory {
 public:
  // Defines the weapon object to associate the ship
  unique_ptr<ESWeapon> addESGun() {
    return unique_ptr<ESWeapon>(new ESUFOGun());
  }

  // Define the engin object to associate with the ship.
  unique_ptr<ESEngine> addESEngine() {
    return unique_ptr<ESEngine>(new ESUFOEngine());
  }
};

class UFOBossEnemyShipFactory : public EnemyShipFactory {
 public:
  unique_ptr<ESWeapon> addESGun() {
    return unique_ptr<ESWeapon>(new ESUFOBossGun());
  }

  unique_ptr<ESEngine> addESEngine() {
    return unique_ptr<ESEngine>(new ESUFOBossEngine());
  }
};



// =======================================================
// UFOEnemyShip
// =======================================================

class UFOEnemyShip : public EnemyShip {
 public:
  explicit UFOEnemyShip(shared_ptr<EnemyShipFactory> shipFactory);
  virtual void makeShip();
 public:
  shared_ptr<EnemyShipFactory> shipFactory;
};

UFOEnemyShip::UFOEnemyShip(shared_ptr<EnemyShipFactory> shipFactory) {
  this->shipFactory = shipFactory;
}

void UFOEnemyShip::makeShip() {
  cout << "Making enemy ship " + getName() << endl;

  weapon = shipFactory->addESGun();
  engine = shipFactory->addESEngine();
}


// =======================================================
// UFOBossEnemyShip
// =======================================================

class UFOBossEnemyShip : public EnemyShip {
 public:
  explicit UFOBossEnemyShip(shared_ptr<EnemyShipFactory> shipFactory);
  void makeShip();
 public:
  shared_ptr<EnemyShipFactory> shipFactory;
};

UFOBossEnemyShip::UFOBossEnemyShip(shared_ptr<EnemyShipFactory> shipFactory) {
  this->shipFactory = shipFactory;
}

void UFOBossEnemyShip::makeShip() {
  cout << "Making enemy ship " << getName() << endl;

  weapon = shipFactory->addESGun();
  engine = shipFactory->addESEngine();
}


// =======˘================================================
// EnemyShipBuilding
// =======================================================

class EnemyShipBuilding {
 protected:
  // This acts as an ordering mechanism for creating
  // EnemyShips that have a weapon, engine & name
  // & nothing else.

  // The specific parts used for engine & weapon depend
  // upon the string that is passed to this method.
  virtual unique_ptr<EnemyShip> makeEnemyShip(string type_of_ship) = 0;
 public:
  // When called a new EnemyShip is made. The specific parts
  // are based on the string entered. After the ship is made
  // we execute multiple methods in the EnemyShip Object.
  unique_ptr<EnemyShip> orderTheShip(string type_of_ship);

  virtual ~EnemyShipBuilding() {}
};

  unique_ptr<EnemyShip> EnemyShipBuilding::orderTheShip
  (string type_of_ship) {
    unique_ptr<EnemyShip> the_enemy_ship = makeEnemyShip(type_of_ship);

    the_enemy_ship->makeShip();
    the_enemy_ship->displayEnemyShip();
    the_enemy_ship->followHeroShip();
    the_enemy_ship->enemyShipShoots();

    return the_enemy_ship;
  }



// =======================================================
// UFOEnemyShipBuilding
// =======================================================

class UFOEnemyShipBuilding : public EnemyShipBuilding {
 protected:
  unique_ptr<EnemyShip> makeEnemyShip(string type_of_ship);
};

unique_ptr<EnemyShip> UFOEnemyShipBuilding::makeEnemyShip
(string type_of_ship) {
  unique_ptr<EnemyShip> the_enemy_ship = nullptr;
  if (std::strncmp("UFO BOSS", type_of_ship.c_str(), 8) == 0) {
    shared_ptr<EnemyShipFactory> shipFactory =
        std::shared_ptr<EnemyShipFactory>(new UFOBossEnemyShipFactory());

    the_enemy_ship =
        unique_ptr<EnemyShip>(new UFOBossEnemyShip(shipFactory));
    the_enemy_ship->setName("UFO Boss Ship");
  } else if (std::strncmp("UFO", type_of_ship.c_str(), 3) == 0) {
    shared_ptr<EnemyShipFactory> shipFactory =
        std::shared_ptr<EnemyShipFactory>(new UFOEnemyShipFactory());
    the_enemy_ship =  unique_ptr<EnemyShip>(new UFOEnemyShip(shipFactory));
    the_enemy_ship->setName(string("UFO Grunt Ship"));
  }
  return the_enemy_ship;
}


int main() {
  unique_ptr<EnemyShipBuilding> ship_building =
      unique_ptr<UFOEnemyShipBuilding>(new UFOEnemyShipBuilding());

  unique_ptr<EnemyShip> the_grunt =
      ship_building->orderTheShip(string("UFO"));
  cout << the_grunt->toString() << endl;

  unique_ptr<EnemyShip> the_boss =
      ship_building->orderTheShip(string("UFO BOSS"));
  cout << the_boss->toString() << endl;
  return 0;
}
