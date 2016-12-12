//
//  EnemyShip.cpp
//  DesignPattern
//
//  Created by 章立 on 16/12/12.
//  Copyright © 2016年 章立. All rights reserved.
//

#include "EnemyShip.hpp"

#include "ESWeapon.hpp"
#include "ESEngine.hpp"
#include "EnemyShipFactory.hpp"

#include <iostream>


using std::cout;
using std::endl;


// =======================================================
// EnemyShip
// =======================================================

EnemyShip::~EnemyShip() {}

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
// UFOEnemyShip
// =======================================================

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

UFOBossEnemyShip::UFOBossEnemyShip(shared_ptr<EnemyShipFactory> shipFactory) {
	this->shipFactory = shipFactory;
}

void UFOBossEnemyShip::makeShip() {
	cout << "Making enemy ship " << getName() << endl;
	
	weapon = shipFactory->addESGun();
	engine = shipFactory->addESEngine();
}

