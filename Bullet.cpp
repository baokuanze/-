//
//  Bullet.cpp
//  stupidZombies
//
//  Created by student on 15/9/8.
//
//

#include "Bullet.h"

bool Bullet::init(){

    this->initWithFile("zidan.png");
//    this->setScale(0.5);
   PhysicsBody *body = PhysicsBody::createCircle(this->getContentSize().width/2);
    body->setDynamic(true);
    body->setMass(0);
    body->getShape(0)->setFriction(0);
    body->getShape(0)->setRestitution(1);
    body->setGravityEnable(false);
    this->setPhysicsBody(body);
    this->getPhysicsBody()->setGroup(-1);
    hp=10;
    
    this->setColor(Color3B::ORANGE);
//    auto comet = ParticleSystemQuad::create("FireBall.plist");
//    comet->setScale(0.3);
//    comet->setPosition(Vec2(this->getPositionX()+10, this->getPositionY()+10));
//    comet->setAutoRemoveOnFinish(true);//自动移除
//    this->addChild(comet);
    
    return true;
}


