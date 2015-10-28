//
//  PauseLayer.h
//  stupidZombies
//
//  Created by student on 15/9/13.
//
//

#ifndef __stupidZombies__PauseLayer__
#define __stupidZombies__PauseLayer__

#include <stdio.h>
#include "cocos2d.h"
#include "ui/CocosGUI.h"
using namespace cocos2d ;
using namespace cocos2d::ui;

class Delegate{     //抽象基类
public:
    
    virtual void continueGame()=0;
    virtual void restartGame()=0;
    
};


class PauseLayer:public LayerColor {
    
public:
    
    static PauseLayer* createLayer();
    
    virtual bool init();
    
public:
    
    //类型，变量，函数名
    CC_SYNTHESIZE(Delegate*, delegate, Delegate);
    
private:
    
    
    Size visibleSize;
    

};
#endif /* defined(__stupidZombies__PauseLayer__) */
