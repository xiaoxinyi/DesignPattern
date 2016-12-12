//
//  EnemyShipBuilding.cpp
//  DesignPattern
//
//  Created by 章立 on 16/12/12.
//  Copyright © 2016年 章立. All rights reserved.
//

#include "EnemyShipBuilding.hpp"
#include "EnemyShip.hpp"
#include "EnemyShipFactory.hpp"

// =======================================================
// EnemyShipBuilding
// =======================================================

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
