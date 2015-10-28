//
//  monster3.cpp
//  stupidZombies
//
//  Created by student on 15/9/11.
//
//

#include "Monster.h"


bool Monster:: init(Boss_type sprite){
    
    if (!Sprite::init()) {
        return  false;
    }

    switch (sprite) {
        case Boss_1:
        SpriteFrameCache::getInstance()->addSpriteFramesWithFile("monster1.plist");
        this->Sprite::initWithSpriteFrameName("A3_0.png");
        this->setFlippedX(true);
        this->runMonster1Action();
            break;
            
        case Boss_2:
            SpriteFrameCache::getInstance()->addSpriteFramesWithFile("monster2.plist");
            this->Sprite::initWithSpriteFrameName("A11_0.png");
            this->setFlippedX(true);
             this->runMonster2Action();
            
            break;
            
        case Boss_3:
            SpriteFrameCache::getInstance()->addSpriteFramesWithFile("monster3.plist");
            this->Sprite::initWithSpriteFrameName("A5_0.png");
            this->setFlippedX(true);
             this->runMonster3Action();
            
            break;
            
        case Boss_4:
            SpriteFrameCache::getInstance()->addSpriteFramesWithFile("monster4.plist");
            this->Sprite::initWithSpriteFrameName("A6_0.png");
            this->setFlippedX(true);
             this->runMonster4Action();
            
            break;
            
        case Boss_5:
            SpriteFrameCache::getInstance()->addSpriteFramesWithFile("monster5.plist");
            this->Sprite::initWithSpriteFrameName("A9_0.png");
            this->setFlippedX(true);
             this->runMonster5Action();
            
            break;
            
        default:
            break;
    }

    
    return true;
}

Monster*Monster::create(Boss_type sprite){
    
    Monster* M = new(std::nothrow) Monster();
    
    if (M && M->init(sprite)) {
        M->autorelease();
        return M;
    }else{
        delete M;
        M = NULL;
        return NULL;
    }
}

void Monster::runMonster1Action(){

    this->stopAllActions();
    
    //用来存放每一帧图片的容器。//miner_0701.png
    Vector<SpriteFrame *> vector;
    
    char name[20];
    for (int i=0; i<=3; i++) {
        sprintf(name, "A3_%d.png",i);
        //取出所有帧图片，放到容器中。
        auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(name);
        vector.pushBack(frame);
        
    }
    
    //用容器中的帧图片来创建一个动画对象。第二个参数表示这个动画执行多长时间。第三个参数表示这个动画执行了多少次。
    auto animation = Animation::createWithSpriteFrames(vector, 0.1, 1);
    auto animate = Animate::create(animation);
    this->runAction(RepeatForever::create(animate));

}
void Monster::runMonster2Action(){
    
    this->stopAllActions();
    
    //用来存放每一帧图片的容器。//miner_0701.png
    Vector<SpriteFrame *> vector;
    
    char name[20];
    for (int i=0; i<=3; i++) {
        sprintf(name, "A11_%d.png",i);
        //取出所有帧图片，放到容器中。
        auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(name);
        vector.pushBack(frame);
    }
    //用容器中的帧图片来创建一个动画对象。第二个参数表示这个动画执行多长时间。第三个参数表示这个动画执行了多少次。
    auto animation = Animation::createWithSpriteFrames(vector, 0.05, 1);
    auto animate = Animate::create(animation);
    this->runAction(RepeatForever::create(animate));
    


}
void Monster::runMonster3Action(){

    this->stopAllActions();
    
    //用来存放每一帧图片的容器。//miner_0701.png
    Vector<SpriteFrame *> vector;
    
    char name[20];
    for (int i=0; i<=3; i++) {
        
        sprintf(name, "A5_%d.png",i);
        
        
        //取出所有帧图片，放到容器中。
        auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(name);
        vector.pushBack(frame);
        
    }
    
    //用容器中的帧图片来创建一个动画对象。第二个参数表示这个动画执行多长时间。第三个参数表示这个动画执行了多少次。
    auto animation = Animation::createWithSpriteFrames(vector, 0.05, 1);
    auto animate = Animate::create(animation);
    this->runAction(RepeatForever::create(animate));
}
void Monster::runMonster4Action(){

    this->stopAllActions();
    
    //用来存放每一帧图片的容器。//miner_0701.png
    Vector<SpriteFrame *> vector;
    
    char name[20];
    for (int i=0; i<=3; i++) {
        
        sprintf(name, "A6_%d.png",i);
        
        
        //取出所有帧图片，放到容器中。
        auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(name);
        vector.pushBack(frame);
        
    }
    
    //用容器中的帧图片来创建一个动画对象。第二个参数表示这个动画执行多长时间。第三个参数表示这个动画执行了多少次。
    auto animation = Animation::createWithSpriteFrames(vector, 0.05, 1);
    auto animate = Animate::create(animation);
    this->runAction(RepeatForever::create(animate));
    

}
void Monster::runMonster5Action(){

    this->stopAllActions();
    
    //用来存放每一帧图片的容器。//miner_0701.png
    Vector<SpriteFrame *> vector;
    
    char name[20];
    for (int i=0; i<=3; i++) {
        
        sprintf(name, "A9_%d.png",i);
        
        
        //取出所有帧图片，放到容器中。
        auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(name);
        vector.pushBack(frame);
        
    }
    
    //用容器中的帧图片来创建一个动画对象。第二个参数表示这个动画执行多长时间。第三个参数表示这个动画执行了多少次。
    auto animation = Animation::createWithSpriteFrames(vector, 0.05, 1);
    auto animate = Animate::create(animation);
    this->runAction(RepeatForever::create(animate));

}

