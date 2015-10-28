//
//  LoseLayer.h
//  stupidZombies
//
//  Created by student on 15/9/13.
//
//

#ifndef __stupidZombies__LoseLayer__
#define __stupidZombies__LoseLayer__

#include <stdio.h>

//返回主页面
//重新开始此关卡
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "MainLayer.h"
using namespace cocos2d ;
using namespace cocos2d::ui;

class LoseDelegate{     //抽象基类
public:
    virtual void loseRestart()=0;
};

class LoseLayer:public LayerColor {
    
public:
    
    static LoseLayer* createLayer();
    
    virtual bool init();
 
public:
    //类型，变量，函数名
    CC_SYNTHESIZE(LoseDelegate*, losedelegate, LoseDelegate);
    
private:
    
    Size visibleSize;

};





#endif /* defined(__stupidZombies__LoseLayer__) */
