//
//  EnemyShip.hpp
//  DesignPattern
//
//  Created by 章立 on 16/12/12.
//  Copyright © 2016年 章立. All rights reserved.
//

#ifndef EnemyShip_hpp_
#define EnemyShip_hpp_

#include <memory>
#include <string>

using std::string;
using std::unique_ptr;
using std::shared_ptr;

class ESEngine;
class ESWeapon;
class EnemyShipFactory;

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
	
	
	virtual ~EnemyShip();
	// Note: virtual ~EnemyShip(); must be implemented in .cpp.
	// If not incomplete type, because when unique_ptr destroy
	// its object which it is pointed to must know its exact memeory
	// space.
protected:
	string name_;
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



#endif /* EnemyShip_hpp_ */
