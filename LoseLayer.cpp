//
//  LoseLayer.cpp
//  stupidZombies
//
//  Created by student on 15/9/13.
//
//

#include "LoseLayer.h"

LoseLayer* LoseLayer:: createLayer(){
    
    
    auto layer = new LoseLayer();
    
    if (layer && layer->init()) {
        layer->autorelease();
        return layer;
    }
    CC_SAFE_DELETE(layer);
    return nullptr;
}



bool LoseLayer:: init(){
    
    if (!LayerColor::initWithColor(Color4B(0,0,0,255))){
        return false;
    }

    
    visibleSize = Director::getInstance()->getVisibleSize();
    this->setOpacity(150);
    this->setPosition(Vec2::ZERO);
    
    
    //失败标志
    auto levelLabel = Label::createWithSystemFont("You Lose!!", "fonts/Marker Felt.ttf", 48);
    levelLabel->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2+100));
    levelLabel->setColor(Color3B(255, 0, 0));
    this->addChild(levelLabel,1);
    
    
    //回主页面
    auto backToMian=Button::create();
    backToMian->loadTextureNormal("back_main_nor.png");
    backToMian->loadTexturePressed("back_main_sel.png");
    backToMian->setPressedActionEnabled(false);
    backToMian->setZoomScale(2.0f);
    backToMian->addClickEventListener([this](Ref*){
        
                log("loseLayer回主菜单");
        auto l = MainLayer::createScene();
        Director::getInstance()->replaceScene(l);
    });
    backToMian->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));
    this->addChild(backToMian);
    
    
    //重玩本关
    auto restart=Button::create();
    restart->loadTextureNormal("restart_nor.png");
    restart->loadTexturePressed("restart_sel.png");
    restart->setPressedActionEnabled(false);
    restart->setZoomScale(2.0f);
    restart->addClickEventListener([this](Ref*){
        
        losedelegate->loseRestart();
//        this->removeFromParent();
        
        log("loseLayer重玩本关");
        
    });
    restart->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2-100));
    this->addChild(restart);
    
    return true;

}