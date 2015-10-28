//
//  Gun.cpp
//  stupidZombies
//
//  Created by student on 15/9/9.
//
//

#include "Gun.h"

bool Gun::init(){
    this->initWithFile("gunone.png");
    setScale(0.5);
    setAnchorPoint(Point(0.5,0 ));
    setRotation(90);
    return true;
}