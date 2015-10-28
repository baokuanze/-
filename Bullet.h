//
//  Bullet.h
//  stupidZombies
//
//  Created by student on 15/9/8.
//
//

#ifndef __stupidZombies__Bullet__
#define __stupidZombies__Bullet__

#include <stdio.h>
#include "cocos2d.h"
using namespace cocos2d;
class Bullet: public Sprite {
    
public:
    
    virtual bool init();
    //血量

    CREATE_FUNC(Bullet);
    
    
    CC_SYNTHESIZE(int, hp, Hp);     //类型，变量，函数名
    
public:
    
private:
    
    
    
    
};

#endif /* defined(__stupidZombies__Bullet__) */
