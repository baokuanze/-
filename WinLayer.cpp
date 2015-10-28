//
//  WinLayer.cpp
//  stupidZombies
//
//  Created by student on 15/9/13.
//
//

#include "WinLayer.h"

WinLayer* WinLayer:: createLayer(){
    
    
    auto layer = new WinLayer();
    
    if (layer && layer->init()) {
        layer->autorelease();
        return layer;
    }
    
    CC_SAFE_DELETE(layer);
    return nullptr;
    
    
}

bool WinLayer:: init(){
    
    if (!LayerColor::initWithColor(Color4B(0,0,0,255))){
        return false;
    }
    
    visibleSize = Director::getInstance()->getVisibleSize();
    this->setOpacity(150);
    this->setPosition(Vec2::ZERO);
    
    
    //胜利标志
    auto levelLabel = Label::createWithSystemFont("Victory!!", "fonts/Marker Felt.ttf", 48);
    levelLabel->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2+200));
    levelLabel->setColor(Color3B(255, 0, 0));
    this->addChild(levelLabel,1);
    
    
    
    //下一关
    auto nextLevel=Button::create();
    nextLevel->loadTextureNormal("nextlevel_nor.png");
    nextLevel->loadTexturePressed("nextlevel_sel.png");
    nextLevel->setPressedActionEnabled(false);
    nextLevel->setZoomScale(2.0f);
    nextLevel->addClickEventListener([this](Ref*){
        
        windelegate->nextLevel();
        this->removeFromParent();
        
//        log("下一关");
        
    });
    nextLevel->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2+100));
    this->addChild(nextLevel);

    
    
    
    
    
    //回主页面
    auto backToMian=Button::create();
    backToMian->loadTextureNormal("back_main_nor.png");
    backToMian->loadTexturePressed("back_main_sel.png");
    backToMian->setPressedActionEnabled(false);
    backToMian->setZoomScale(2.0f);
    backToMian->addClickEventListener([this](Ref*){
        
//        log("回主菜单");
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
        
        windelegate->winRestart();
        this->removeFromParent();
        
//        log("重玩本关");
        
    });
    restart->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2-100));
    this->addChild(restart);

    
    
    
    
    
    
    return true;

}