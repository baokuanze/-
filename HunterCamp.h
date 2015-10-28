//
//  HunterCamp.h
//  stupidZombies
//
//  Created by student on 15/9/7.
//
//

#ifndef __stupidZombies__HunterCamp__
#define __stupidZombies__HunterCamp__

#include <stdio.h>

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "Xmller.h"
using namespace cocos2d::ui;
using namespace cocostudio;
using namespace timeline;
using namespace cocos2d;
class HunterCamp:public Layer {
    
public:
    
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(HunterCamp);
    
    
public:
    void loadingScene();
    
public:
    
    //数据存储
    Xmller xmller;//创建解析对象
    std::string str;
    
private:
    
    Size visibleSize;
    
    
};

#endif /* defined(__stupidZombies__HunterCamp__) */
