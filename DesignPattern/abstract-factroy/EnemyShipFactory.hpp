//
//  EnemyShipFactory.hpp
//  DesignPattern
//
//  Created by 章立 on 16/12/12.
//  Copyright © 2016年 章立. All rights reserved.
//

#ifndef EnemyShipFactory_hpp
#define EnemyShipFactory_hpp


#include <memory>


using std::unique_ptr;

class ESWeapon;
class ESEngine;

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
	// Overwrite. Defines the weapon object to associate the ship
	virtual unique_ptr<ESWeapon> addESGun();
	
	// Overwrite. Define the engin object to associate with the ship.
	virtual unique_ptr<ESEngine> addESEngine();
};


class UFOBossEnemyShipFactory : public EnemyShipFactory {
public:
	virtual unique_ptr<ESWeapon> addESGun();
	
	virtual unique_ptr<ESEngine> addESEngine();
};


#endif /* EnemyShipFactory_hpp */
