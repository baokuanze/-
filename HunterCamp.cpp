//
//  HunterCamp.cpp
//  stupidZombies
//
//  Created by student on 15/9/7.
//
//

#include "HunterCamp.h"
#include "MainLayer.h"
#include "GameLayer.h"

Scene* HunterCamp::createScene()
{
    auto scene = Scene::create();
    auto layer = HunterCamp::create();
    scene->addChild(layer);
    return scene;
}

bool HunterCamp::init()
{
    
    
    if (!Layer::init())
    {
        return false;
    }
    
    visibleSize = Director::getInstance()->getVisibleSize();
    
    
    //文件解析
    str="Data.xml";
    xmller.createwithxmlfile(str);
    loadingScene();
    return  true;
}


void HunterCamp:: loadingScene(){


    //csb节点
    auto node = CSLoader::createNode("MainScene_1.csb");
//    auto node1 = CSLoader::createNode("Node_1.csb");//不用加载node的子节点
    
    node->setAnchorPoint(Vec2( 0.5,0.5));
    
    node->setScale(visibleSize.width/node->getContentSize().width,visibleSize.height/node->getContentSize().height);
    
    node->setPosition(Vec2(visibleSize/2));
      this->addChild(node);
    
    //返回按钮
   auto button= node->getChildByName<ui::Button *>("Button_1");
    
    button->addClickEventListener([this](Ref* r){
      
        log("返回营地");
        
        auto scene = MainLayer::createScene();
        
        Director::getInstance()->replaceScene(scene);
        
        
    });
    //node的子节点
   auto buttonNode = node->getChildByName<Node*>("ProjectNode_1");
    //第一关按钮
    auto button1 = buttonNode->getChildByName<ui::Button *>("Button_2");
    button1->addClickEventListener([this](Ref* r){
        
        log("第一关");
        
        //把level的值改成1，再写进去
        int i = 1;
        char temp[50];
        sprintf(temp,"%d",i);
        xmller.changeLevel01(temp);//改变xml数据
      
        
        //改变子弹的数量
        int tt = 30;
        sprintf(temp, "%d",tt);
        xmller.changeLevel03(temp);
        
        
        xmller.XmlParse(str);//解析
        
        
       auto scene =  GameLayer::createScene();
        
        Director::getInstance()->replaceScene(scene);
        
    });
    
    //第二关按钮
    
    auto button2 = buttonNode->getChildByName<ui::Button *>("Button_2_0");
    button2->addClickEventListener([this](Ref* r){
        
        log("第二关");
        
        //把level的值改成2，再写进去
        int i = 2;
        char temp[50];
        sprintf(temp,"%d",i);
        xmller.changeLevel01(temp);//改变xml数据
        
        //改变子弹的数量
        int tt = 40;
        sprintf(temp, "%d",tt);
        xmller.changeLevel03(temp);
   
        
        xmller.XmlParse(str);//解析
        
        auto scene =  GameLayer::createScene();
        Director::getInstance()->replaceScene(scene);
        
    });
    
    //第三关
    
    auto button3 = buttonNode->getChildByName<ui::Button *>("Button_2_1");
    button3->addClickEventListener([this](Ref* r){
        
        log("第三关");
        
        //把level的值改成3，再写进去
        int i = 3;
        char temp[50];
        sprintf(temp,"%d",i);
        xmller.changeLevel01(temp);//改变xml数据
        
        //改变子弹的数量
        int tt = 50;
        sprintf(temp, "%d",tt);
        xmller.changeLevel03(temp);
        
        
        xmller.XmlParse(str);//解析
        
        auto scene =  GameLayer::createScene();
        Director::getInstance()->replaceScene(scene);
        
    });
    
    //第四关
    
    auto button4 = buttonNode->getChildByName<ui::Button *>("Button_2_2");
    button4->addClickEventListener([this](Ref* r){
        
        log("第四关");
        
        //把level的值改成3，再写进去
        int i = 4;
        char temp[50];
        sprintf(temp,"%d",i);
        xmller.changeLevel01(temp);//改变xml数据
        
        //改变子弹的数量
        int tt = 30;
        sprintf(temp, "%d",tt);
        xmller.changeLevel03(temp);
        
        
        xmller.XmlParse(str);//解析
        auto scene =  GameLayer::createScene();
        Director::getInstance()->replaceScene(scene);
        
    });
    
    //第五关
    
    auto button5 = buttonNode->getChildByName<ui::Button *>("Button_2_3");
    button5->addClickEventListener([this](Ref* r){
        
        log("第五关");
        
        //把level的值改成3，再写进去
        int i = 5;
        char temp[50];
        sprintf(temp,"%d",i);
        xmller.changeLevel01(temp);//改变xml数据
        
        //改变子弹的数量
        int tt = 20;
        sprintf(temp, "%d",tt);
        xmller.changeLevel03(temp);
        
        
        xmller.XmlParse(str);//解析
        auto scene =  GameLayer::createScene();
        Director::getInstance()->replaceScene(scene);
        
    });


}





