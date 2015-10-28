//
//  Monsters.h
//  zixuanxiangmu
//
//  Created by student on 15/9/9.
//
//

#ifndef __zixuanxiangmu__Monsters__
#define __zixuanxiangmu__Monsters__
//发哥的
#include <iostream>
#include "cocos2d.h"

typedef enum
{
    Item_gebulin1 = 0,
    Item_gebulin2 ,
    Item_gebulin3
}Item_type;

class Monsters:public cocos2d::Sprite
{
public:
    int score;
    bool isflag;
    Monsters(Item_type);
    
    void setMonsterPosition(int t,cocos2d::Vec2 p1,cocos2d::Vec2 p2);
    void change();

};

#endif /* defined(__zixuanxiangmu__Monsters__) */
