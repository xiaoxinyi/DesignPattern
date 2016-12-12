//
//  Main.cpp
//  DesignPattern
//
//  Created by 章立 on 16/12/12.
//  Copyright © 2016年 章立. All rights reserved.
//

#include "EnemyShipBuilding.hpp"
#include "EnemyShip.hpp"

#include <iostream>

using std::cout;
using std::endl;


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
