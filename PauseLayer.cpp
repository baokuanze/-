//
//  PauseLayer.cpp
//  stupidZombies
//
//  Created by student on 15/9/13.
//
//

#include "PauseLayer.h"
#include "MainLayer.h"

PauseLayer* PauseLayer:: createLayer(){

    
    auto layer = new PauseLayer();
    
    if (layer && layer->init()) {
        layer->autorelease();
        return layer;
    }
    
    CC_SAFE_DELETE(layer);
    return nullptr;


}


bool PauseLayer:: init(){

    if (!LayerColor::initWithColor(Color4B(0,0,0,255))){
        return false;
    }

    visibleSize = Director::getInstance()->getVisibleSize();
    this->setOpacity(150);
    this->setPosition(Vec2::ZERO);
    
    //继续游戏
    
    auto continueButton=Button::create();
    continueButton->loadTextureNormal("continue_game_nor.png");
    continueButton->loadTexturePressed("continue_game_sel.png");
//    continueButton->setScale9Enabled(true);
//    continueButton->setContentSize(Size(128,128));
    continueButton->setPressedActionEnabled(false);
    continueButton->setZoomScale(2.0f);//大于1有效小于1无效
    continueButton->addClickEventListener([this](Ref*){
        
        delegate->continueGame();
        this->removeFromParent();

        log("继续游戏");
        
    });
    continueButton->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2+100));
    this->addChild(continueButton);
    
    //回主页面
    auto backToMian=Button::create();
    backToMian->loadTextureNormal("back_main_nor.png");
    backToMian->loadTexturePressed("back_main_sel.png");
    backToMian->setPressedActionEnabled(false);
    backToMian->setZoomScale(2.0f);
    backToMian->addClickEventListener([this](Ref*){
        
        log("回主菜单");
        delegate->continueGame();
        
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
        
        delegate->restartGame();
        this->removeFromParent();

        log("重玩本关");
        
    });
    restart->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2-100));
    this->addChild(restart);

    

    return true;
}