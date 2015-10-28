//
//  MainLayer.h
//  stupidZombies
//
//  Created by student on 15/9/7.
//
//

#ifndef __stupidZombies__MainLayer__
#define __stupidZombies__MainLayer__

#include <stdio.h>
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
using namespace cocos2d::ui;
using namespace cocostudio;
using namespace timeline;
using namespace cocos2d;
class MainLayer:public Layer {

public:
    
    
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(MainLayer);
    
public:
    void loadingScene();
    
private:
    
    Size visibleSize;
    
    
    
};
#endif /* defined(__stupidZombies__MainLayer__) */
