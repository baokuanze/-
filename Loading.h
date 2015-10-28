
//
//  Loading.h
//  stupidZombies
//
//  Created by student on 15/9/7.
//
//

#ifndef __stupidZombies__Loading__
#define __stupidZombies__Loading__

#include <stdio.h>
#include "cocos2d.h"
using namespace cocos2d;

class Loading:public Layer {
    
public:
    
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(Loading);
    
public:
    Size visibleSize;
    void loadingScene();
    
};
#endif /* defined(__stupidZombies__Loading__) */
