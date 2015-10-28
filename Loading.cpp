//
//  Loading.cpp
//  stupidZombies
//
//  Created by student on 15/9/7.
//
//

#include "Loading.h"


Scene* Loading::createScene()
{
    auto scene = Scene::create();
    auto layer = Loading::create();
    scene->addChild(layer);
    return scene;
}

bool Loading::init()
{
    
    
    if (!Layer::init())
    {
        return false;
    }
    
     visibleSize = Director::getInstance()->getVisibleSize();
    
    
    loadingScene();
    
    return  true;
    
}


void Loading::loadingScene(){

    auto sp = Sprite::create("guaiwulieren.png");
    sp->setScale(visibleSize.width/sp->getContentSize().width, visibleSize.height/sp->getContentSize().height);
    sp->setPosition(visibleSize/2);
    this->addChild(sp);
    
    
    auto progressTo =ProgressFromTo::create(5.0f, 0, 100.0f);
    auto grassSprite = Sprite::create("loading.png");
    auto timer = ProgressTimer::create(grassSprite);
    timer->setPosition(Vec2(visibleSize.width/2,50));
    this->addChild(timer);
    timer->setType(ProgressTimer::Type::BAR);
    timer->setMidpoint(Point(0,0));//从左边开始
    timer->runAction(progressTo);

}
