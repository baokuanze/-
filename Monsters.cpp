//
//  Monsters.cpp
//  zixuanxiangmu
//
//  Created by student on 15/9/9.
//
//

#include "Monsters.h"
#include "cocos2d.h"

using namespace cocos2d;
Monsters::Monsters(Item_type sprite)
{
    this->isflag = false;
    
    switch (sprite)
    {
        case Item_gebulin1:
        {
            this->initWithFile("gebulin1.png");
            this->score = 10;
            this->stopAllActions();
            Vector<SpriteFrame* >vector;
            
            auto tempDic = __Dictionary::createWithContentsOfFile("gebulin1.plist");
            auto dic = (__Dictionary*)tempDic->objectForKey("frames");
            int num = (int)dic->allKeys()->count();
            log("gebulin  %d",num);
            
            for (int i=12;i<18; ++i)
            {
                SpriteFrame *frame = NULL;
                frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(__String::createWithFormat("gebulin1_%d.png",i)->getCString());
                vector.pushBack(frame);
            }
            auto animation = Animation::createWithSpriteFrames(vector,0.2,1);
            auto plitAnimate = Animate::create(animation);
            this->runAction(RepeatForever::create(plitAnimate));
            
            break;
        }
        case Item_gebulin2:
        {
            this->initWithFile("gebulin2.png");
            this->score = 15;
            this->stopAllActions();
            Vector<SpriteFrame* >vector;
            
            for (int i=12;i<18; ++i)
            {
                SpriteFrame *frame = NULL;
                frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(__String::createWithFormat("gebulin2_%d.png",i)->getCString());
                vector.pushBack(frame);
            }
            auto animation = Animation::createWithSpriteFrames(vector,0.2,1);
            auto plitAnimate = Animate::create(animation);
            this->runAction(RepeatForever::create(plitAnimate));
            break;
        }
        case Item_gebulin3:
        {
            this->initWithFile("gebulin3.png");
            this->score = 20;
            this->stopAllActions();
            Vector<SpriteFrame* >vector;
            
            for (int i=12;i<18; ++i)
            {
                SpriteFrame *frame = NULL;
                frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(__String::createWithFormat("gebulin3_%d.png",i)->getCString());
                vector.pushBack(frame);
            }
            auto animation = Animation::createWithSpriteFrames(vector,0.2,1);
            auto plitAnimate = Animate::create(animation);
            this->runAction(RepeatForever::create(plitAnimate));
            
            break;
        }
        default:
            break;
    }
}
void Monsters::setMonsterPosition(int t,cocos2d::Vec2 p1, cocos2d::Vec2 p2)
{
    auto moveToright = MoveTo::create(t,p1);
    auto moveToleft = MoveTo::create(t,p2);
    auto func = CallFunc::create(CC_CALLBACK_0(Monsters::change,this));
    
    auto seq = Sequence::create(moveToright,DelayTime::create(1),func,moveToleft,func,NULL);
    this->runAction(RepeatForever::create(seq));
}
void Monsters::change(){
    isflag = !isflag;
    if (isflag) {
        this->setFlippedX(true);
    }else{
        this->setFlippedX(false);
    }
}