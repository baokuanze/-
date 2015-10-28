//
//  AddScene.cpp
//  stupidZombies
//
//  Created by student on 15/9/11.
//
//

#include "AddScene.h"


AddScene* AddScene:: selectScene(int i){
    
    AddScene* s = new(std::nothrow) AddScene();

    if (s && s->init(i)) {
        s->autorelease();
        return s;
    }else{
        delete s;
        s = NULL;
        return NULL;
    }
    
 
  
}
bool AddScene:: init(int i){

    if (!Node::init()) {
        return false;
    }
    
    WALL_MASK =00001;
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    
    auto str = __String::createWithFormat("Scene_%d",i);
    
    node =  CSLoader::createNode(str->getCString());/////??
    node->setAnchorPoint(Vec2( 0.5,0.5));
    node->setPosition(Vec2(visibleSize/2));
    addChild(node);
    switch (i) {
        case 1:
            addGangti1();
            break;
            
        case 2:
            addGangti2();
            break;
            
        case 3:
            addGangti3();
            break;
            
        case 4:
            addGangti4();
            break;
            
        case 5:
            addGangti5();
            break;
        default:
            break;
    }

    return true;

}

void AddScene::addGangti1() {

    //木头
    for (int i = 1; i<=9 ;i++ ) {
        auto str = __String::createWithFormat("wood_%d",i);
        Sprite* woods1 = node->getChildByName<Sprite*>(str->getCString());
        //       log("tag = %d",woods1->getTag());
        if (woods1->getTag() ==5) {
            auto body = PhysicsBody::createBox(woods1->getContentSize());
            body->setDynamic(false);
            body->getShape(0)->setRestitution(1);//反弹力
            body->getShape(0)->setFriction(0);//摩擦力
            woods1->setPhysicsBody(body);
            woods1->getPhysicsBody()->setContactTestBitmask(WALL_MASK);
        }
        
        
    }
    
    //墙壁
    for (int i =1; i<=4; i++) {
        auto str2 =__String::createWithFormat("wall_%d",i);
        auto wall = node->getChildByName<Sprite*>(str2->getCString());
        if (wall->getTag() == 25) {
            auto body2 = PhysicsBody::createBox(Size(wall->getContentSize().width,wall->getContentSize().height));//den res fri
            
            body2->setDynamic(false);
            body2->getShape(0)->setFriction(0);
            body2->getShape(0)->setRestitution(1);
            
            
            wall->setPhysicsBody(body2);
            
            wall->getPhysicsBody()->setContactTestBitmask(WALL_MASK);
        }
        
    }
    
    //石头
    for (int i =1; i<= 3; i++) {
        
        auto str3 =__String::createWithFormat("stone_%d",i);
        auto stone = node->getChildByName<Sprite*>(str3->getCString());
        if (stone->getTag() == 45) {
            //            auto body2 = PhysicsBody::createBox(Size(stone->getContentSize().width,stone->getContentSize().height));//den res fri
            //
            auto body3 = PhysicsBody::createCircle(stone->getContentSize().width/2);
            
            body3->setDynamic(false);
            body3->getShape(0)->setFriction(0);
            body3->getShape(0)->setRestitution(1.5);//弹力
            stone->setPhysicsBody(body3);
            stone->getPhysicsBody()->setContactTestBitmask(WALL_MASK);
        }
    }
    

}
void AddScene::addGangti2() {
    
    
    
    //木头
    for (int i = 1; i<=8 ;i++ ) {
        auto str = __String::createWithFormat("wood_%d",i);
        Sprite* woods1 = node->getChildByName<Sprite*>(str->getCString());
        //       log("tag = %d",woods1->getTag());
        if (woods1->getTag() ==5) {
            auto body = PhysicsBody::createBox(woods1->getContentSize());
            body->setDynamic(false);
            body->getShape(0)->setRestitution(1);//反弹力
            body->getShape(0)->setFriction(0);//摩擦力
            woods1->setPhysicsBody(body);
            woods1->getPhysicsBody()->setContactTestBitmask(WALL_MASK);
        }
        
    }
    
    //墙壁
    for (int i =1; i<=4; i++) {
        auto str2 =__String::createWithFormat("wall_%d",i);
        auto wall = node->getChildByName<Sprite*>(str2->getCString());
        if (wall->getTag() == 25) {
            auto body2 = PhysicsBody::createBox(Size(wall->getContentSize().width,wall->getContentSize().height));//den res fri
            
            body2->setDynamic(false);
            body2->getShape(0)->setFriction(0);
            body2->getShape(0)->setRestitution(1);
            
            
            wall->setPhysicsBody(body2);
            
            wall->getPhysicsBody()->setContactTestBitmask(WALL_MASK);
        }
        
    }
    
    //石头
    auto stone = node->getChildByName<Sprite*>("stone_1");
    if (stone->getTag() == 45) {
        auto body3 = PhysicsBody::createCircle(stone->getContentSize().width/2);
        body3->setDynamic(false);
        body3->getShape(0)->setFriction(0);
        body3->getShape(0)->setRestitution(1.5);//弹力
        stone->setPhysicsBody(body3);
        stone->getPhysicsBody()->setContactTestBitmask(WALL_MASK);
    }
    
    
    //石头墙
    
    for (int i = 1; i<=9 ;i++ ) {
        auto str3 = __String::createWithFormat("wod_%d",i);
        Sprite* woods1 = node->getChildByName<Sprite*>(str3->getCString());
        //       log("tag = %d",woods1->getTag());
        if (woods1->getTag() ==55) {
            auto body = PhysicsBody::createBox(woods1->getContentSize());
            body->setDynamic(false);
            body->getShape(0)->setRestitution(1.3);//反弹力
            body->getShape(0)->setFriction(0);//摩擦力
            woods1->setPhysicsBody(body);
            woods1->getPhysicsBody()->setContactTestBitmask(WALL_MASK);
        }
        
    }
    

}
void AddScene::addGangti3() {
    
    
    
    //墙壁
    for (int i =1; i<=4; i++) {
        auto str2 =__String::createWithFormat("wall_%d",i);
        auto wall = node->getChildByName<Sprite*>(str2->getCString());
        if (wall->getTag() == 25) {
            auto body2 = PhysicsBody::createBox(Size(wall->getContentSize().width,wall->getContentSize().height));
            
            body2->setDynamic(false);
            body2->getShape(0)->setFriction(0);
            body2->getShape(0)->setRestitution(1);
            
            
            wall->setPhysicsBody(body2);
            
            wall->getPhysicsBody()->setContactTestBitmask(WALL_MASK);
        }
        
    }
    
    
    //石头墙
    
    for (int i = 1; i<=4 ;i++ ) {
        auto str3 = __String::createWithFormat("wod_%d",i);
        Sprite* woods1 = node->getChildByName<Sprite*>(str3->getCString());
        //       log("tag = %d",woods1->getTag());
        if (woods1->getTag() ==55) {
            auto body = PhysicsBody::createBox(woods1->getContentSize());
            body->setDynamic(false);
            body->getShape(0)->setRestitution(1.3);//反弹力
            body->getShape(0)->setFriction(0);//摩擦力
            woods1->setPhysicsBody(body);
            woods1->getPhysicsBody()->setContactTestBitmask(WALL_MASK);
        }
        
    }
    
    
    //木头
    for (int i = 1; i<=8 ;i++ ) {
        auto str = __String::createWithFormat("wood_%d",i);
        Sprite* woods1 = node->getChildByName<Sprite*>(str->getCString());
        //       log("tag = %d",woods1->getTag());
        if (woods1->getTag() ==5) {
            auto body = PhysicsBody::createBox(woods1->getContentSize());
            body->setDynamic(false);
            body->getShape(0)->setRestitution(1);//反弹力
            body->getShape(0)->setFriction(0);//摩擦力
            woods1->setPhysicsBody(body);
            woods1->getPhysicsBody()->setContactTestBitmask(WALL_MASK);
        }
        
    }
    
    
    //石头
    for (int i =1; i<= 3; i++) {
        auto str3 =__String::createWithFormat("stone_%d",i);
        auto stone = node->getChildByName<Sprite*>(str3->getCString());
        if (stone->getTag() == 45) {
            auto body3 = PhysicsBody::createCircle(stone->getContentSize().width/2);
            body3->setDynamic(false);
            body3->getShape(0)->setFriction(0);
            body3->getShape(0)->setRestitution(1.5);//弹力
            stone->setPhysicsBody(body3);
            stone->getPhysicsBody()->setContactTestBitmask(WALL_MASK);
        }
    }
    
    
    


}
void AddScene::addGangti4() {
    
    
    
    //墙壁
    for (int i =1; i<=4; i++) {
        auto str2 =__String::createWithFormat("wall_%d",i);
        auto wall = node->getChildByName<Sprite*>(str2->getCString());
        if (wall->getTag() == 25) {
            auto body2 = PhysicsBody::createBox(Size(wall->getContentSize().width,wall->getContentSize().height));
            
            body2->setDynamic(false);
            body2->getShape(0)->setFriction(0);
            body2->getShape(0)->setRestitution(1);
            
            
            wall->setPhysicsBody(body2);
            
            wall->getPhysicsBody()->setContactTestBitmask(WALL_MASK);
        }
    }
    
    //木头
    for (int i = 1; i<=9 ;i++ ) {
        auto str = __String::createWithFormat("wood_%d",i);
        Sprite* woods1 = node->getChildByName<Sprite*>(str->getCString());
        //       log("tag = %d",woods1->getTag());
        if (woods1->getTag() ==5) {
            auto body = PhysicsBody::createBox(woods1->getContentSize());
            body->setDynamic(false);
            body->getShape(0)->setRestitution(1);//反弹力
            body->getShape(0)->setFriction(0);//摩擦力
            woods1->setPhysicsBody(body);
            woods1->getPhysicsBody()->setContactTestBitmask(WALL_MASK);
        }
        
    }
    
    //石头墙
    
    for (int i = 1; i<=3 ;i++ ) {
        auto str3 = __String::createWithFormat("wod_%d",i);
        Sprite* woods1 = node->getChildByName<Sprite*>(str3->getCString());
        //       log("tag = %d",woods1->getTag());
        if (woods1->getTag() ==55) {
            auto body = PhysicsBody::createBox(woods1->getContentSize());
            body->setDynamic(false);
            body->getShape(0)->setRestitution(1.3);//反弹力
            body->getShape(0)->setFriction(0);//摩擦力
            woods1->setPhysicsBody(body);
            woods1->getPhysicsBody()->setContactTestBitmask(WALL_MASK);
        }
        
    }
    
    
    //石头
    for (int i =1; i<= 3; i++) {
        auto str3 =__String::createWithFormat("stone_%d",i);
        auto stone = node->getChildByName<Sprite*>(str3->getCString());
        if (stone->getTag() == 45) {
            auto body3 = PhysicsBody::createCircle(stone->getContentSize().width/2);
            body3->setDynamic(false);
            body3->getShape(0)->setFriction(0);
            body3->getShape(0)->setRestitution(1.5);//弹力
            stone->setPhysicsBody(body3);
            stone->getPhysicsBody()->setContactTestBitmask(WALL_MASK);
        }
    }
    
    


}
void AddScene::addGangti5() {
    
    
    //墙壁
    for (int i =1; i<=4; i++) {
        auto str2 =__String::createWithFormat("wall_%d",i);
        auto wall = node->getChildByName<Sprite*>(str2->getCString());
        if (wall->getTag() == 25) {
            auto body2 = PhysicsBody::createBox(Size(wall->getContentSize().width,wall->getContentSize().height));
            
            body2->setDynamic(false);
            body2->getShape(0)->setFriction(0);
            body2->getShape(0)->setRestitution(1);
            
            
            wall->setPhysicsBody(body2);
            
            wall->getPhysicsBody()->setContactTestBitmask(WALL_MASK);
        }
    }
    
    //木头
    for (int i = 1; i<=6 ;i++ ) {
        auto str = __String::createWithFormat("wood_%d",i);
        Sprite* woods1 = node->getChildByName<Sprite*>(str->getCString());
        //       log("tag = %d",woods1->getTag());
        if (woods1->getTag() ==5) {
            auto body = PhysicsBody::createBox(woods1->getContentSize());
            body->setDynamic(false);
            body->getShape(0)->setRestitution(1);//反弹力
            body->getShape(0)->setFriction(0);//摩擦力
            woods1->setPhysicsBody(body);
            woods1->getPhysicsBody()->setContactTestBitmask(WALL_MASK);
        }
        
    }
    
    //石头
    for (int i =1; i<= 6; i++) {
        auto str3 =__String::createWithFormat("stone_%d",i);
        auto stone = node->getChildByName<Sprite*>(str3->getCString());
        if (stone->getTag() == 45) {
            auto body3 = PhysicsBody::createCircle(stone->getContentSize().width/2);
            body3->setDynamic(false);
            body3->getShape(0)->setFriction(0);
            body3->getShape(0)->setRestitution(1.5);//弹力
            stone->setPhysicsBody(body3);
            stone->getPhysicsBody()->setContactTestBitmask(WALL_MASK);
        }
    }
    


}



