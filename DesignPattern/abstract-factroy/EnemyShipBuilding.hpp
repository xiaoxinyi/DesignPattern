//
//  EnemyShipBuilding.hpp
//  DesignPattern
//
//  Created by 章立 on 16/12/12.
//  Copyright © 2016年 章立. All rights reserved.
//

#ifndef EnemyShipBuilding_hpp
#define EnemyShipBuilding_hpp

#include <memory>
#include <string>

using std::string;
using std::unique_ptr;

class EnemyShip;


// =======================================================
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




// =======================================================
// UFOEnemyShipBuilding
// =======================================================

class UFOEnemyShipBuilding : public EnemyShipBuilding {
protected:
	unique_ptr<EnemyShip> makeEnemyShip(string type_of_ship);
};



#endif /* EnemyShipBuilding_hpp */
