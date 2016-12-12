//
//  ESWeapon.hpp
//  DesignPattern
//
//  Created by 章立 on 16/12/12.
//  Copyright © 2016年 章立. All rights reserved.
//

#ifndef ESWeapon_hpp_
#define ESWeapon_hpp_

#include <string>

using std::string;

// =======================================================
// ESWeapon
// =======================================================

class ESWeapon {
public:
	virtual string toString() = 0;
	virtual ~ESWeapon() {}
};


// =======================================================
// ESUFOGun
// =======================================================

class ESUFOGun : public ESWeapon{
public:
	// Overwrite
	virtual string toString();
};


// =======================================================
// ESUFOBossGun
// =======================================================

class ESUFOBossGun : public ESWeapon {
public:
	// Overwrite
	virtual string toString();
};

#endif /* ESWeapon_hpp_ */
