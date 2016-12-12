//
//  ESEngine.hpp
//  DesignPattern
//
//  Created by 章立 on 16/12/12.
//  Copyright © 2016年 章立. All rights reserved.
//

#ifndef ESEngine_hpp_
#define ESEngine_hpp_

#include <string>

using std::string;

// =======================================================
// ESEngine
// =======================================================


class ESEngine {
public:
	virtual string toString() = 0;
	virtual ~ESEngine() {}
};

class ESUFOEngine : public ESEngine {
public:
	// Overwrite
	virtual string toString();
};

class ESUFOBossEngine : public ESEngine {
public:
	// Overwrite
	virtual string toString();
};


#endif /* ESEngine_hpp_ */
