//
//  monster3.h
//  stupidZombies
//
//  Created by student on 15/9/11.
//
//

#ifndef __stupidZombies__monster3__
#define __stupidZombies__monster3__

#include <stdio.h>

#include"cocos2d.h"
using namespace cocos2d;

typedef enum
{
    Boss_1 = 0,
    Boss_2 ,
    Boss_3 ,
    Boss_4 ,
    Boss_5
}Boss_type;

class Monster: public Sprite{
    
public:
    
    virtual bool init(Boss_type);
   static Monster* create(Boss_type);
    
public:
    void runMonster1Action();
    void runMonster2Action();
    void runMonster3Action();
    void runMonster4Action();
    void runMonster5Action();
    
};
#endif /* defined(__stupidZombies__monster3__) */
