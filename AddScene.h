//
//  AddScene.h
//  stupidZombies
//
//  Created by student on 15/9/11.
//
//

#ifndef __stupidZombies__AddScene__
#define __stupidZombies__AddScene__

#include <stdio.h>
#include "cocos2d.h"
#include "Box2D/Box2d.h"
#include "cocostudio/CocoStudio.h"
using namespace cocos2d ;
class GameLayer;
class AddScene :public Node {

public:
 
    static AddScene* selectScene(int i);
    virtual bool init(int i);
public:
    void addGangti1();
    void addGangti2();
    void addGangti3();
    void addGangti4();
    void addGangti5();
    
private:
    Node* node;
    
    
    
public:
    CC_SYNTHESIZE(int, WALL_MASK, WALLMASK);// 类型 变量名 函数名
    
    
    
};
#endif /* defined(__stupidZombies__AddScene__) */
