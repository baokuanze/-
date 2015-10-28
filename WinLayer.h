//
//  WinLayer.h
//  stupidZombies
//
//  Created by student on 15/9/13.
//
//

#ifndef __stupidZombies__WinLayer__
#define __stupidZombies__WinLayer__

#include <stdio.h>

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "MainLayer.h"
using namespace cocos2d ;
using namespace cocos2d::ui;

class WinLayerDelegate{     //抽象基类
public:
    virtual void nextLevel()=0;
    virtual void winRestart()=0;
};


class WinLayer:public LayerColor {
    
public:
    
    static WinLayer* createLayer();
    
    virtual bool init();
    
public:
    
    //类型，变量，函数名
    CC_SYNTHESIZE(WinLayerDelegate*, windelegate, WinDelegate);
    
private:
    
    Size visibleSize;
    
    
    
};

#endif /* defined(__stupidZombies__WinLayer__) */
