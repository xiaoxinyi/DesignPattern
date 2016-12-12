//
//  EnemyShipFactory.cpp
//  DesignPattern
//
//  Created by 章立 on 16/12/12.
//  Copyright © 2016年 章立. All rights reserved.
//

#include "EnemyShipFactory.hpp"

#include "ESWeapon.hpp"
#include "ESEngine.hpp"


// =======================================================
// UFOEnemyShipFactory
// =======================================================

unique_ptr<ESWeapon> UFOEnemyShipFactory::addESGun() {
	return unique_ptr<ESWeapon>(new ESUFOGun());
}

unique_ptr<ESEngine> UFOEnemyShipFactory::addESEngine() {
	return unique_ptr<ESEngine>(new ESUFOEngine());
}


// =======================================================
// UFOBossEnemyShipFactory
// =======================================================

unique_ptr<ESWeapon> UFOBossEnemyShipFactory::addESGun() {
	return unique_ptr<ESWeapon>(new ESUFOBossGun());
}

unique_ptr<ESEngine> UFOBossEnemyShipFactory::addESEngine() {
	return unique_ptr<ESEngine>(new ESUFOBossEngine());
}
