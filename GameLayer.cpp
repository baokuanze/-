//
//  GameLayer.cpp
//  stupidZombies
//
//  Created by student on 15/9/7.
//
//

#include "GameLayer.h"

#define BALL_MASK      00010
#define WALL_MASK      00001
Scene* GameLayer::createScene()
{
    auto scene = Scene::createWithPhysics();
//    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    auto layer = GameLayer::create();
    layer->setPhyWorld(scene->getPhysicsWorld());
    scene->addChild(layer);
    layer->test();
    scene->getPhysicsWorld()->setAutoStep(false);//解决穿透
    return scene;
}

void GameLayer::test()
{
    scheduleOnce(schedule_selector(GameLayer::updateStart), 0.001f);
}

bool GameLayer::init(){
    
    if ( !LayerColor::initWithColor(Color4B(255, 255, 255, 255)) )
    {
        return false;
    }
    

    
    visibleSize = Director::getInstance()->getVisibleSize();

    gun = Gun::create();
    gun->setScale(0.25);
    gun->setPosition(Vec2(120,visibleSize.height/2-180));
    addChild(gun,1);

    touchTest();    //触摸检测
    
    
    this->schedule(schedule_selector(GameLayer::checkCollision), 0.1);//启动检测碰撞的函数

    ////////////////////////////

    //文件解析
    str="Data.xml";
//    xmller.giveBirthTo(str);
    xmller.createwithxmlfile(str);
    
    //更换背景
    std::string a= xmller.getLevel01();
    int i = atoi(a.c_str());

    log("哇擦了%d",i);
    auto levelNumber = __String::createWithFormat("bg%d.png",i);
    log("%s",levelNumber->getCString());
    auto bg = Sprite::create(levelNumber->getCString());
    bg->setPosition(visibleSize/2);
    
    auto fade1 = FadeTo::create(2.0, 150);
    auto fade2 = FadeIn::create(2.0);
    auto seq = RepeatForever::create( Sequence::create(fade1,fade2,NULL));
    bg->runAction(seq);
    addChild(bg);
    
    loadLayer();    //加载场景
    addSprite();    //添加界面UI元素
    
    //拿到子弹数量,给全局变量
    auto bulletnm = xmller.getLevel03();
    int b = atoi(bulletnm.c_str());
    bulletNumber = b;

    butemp =0;
    return true;
}


void GameLayer:: loseRestart(){
    log("GameLayer loseRestart");
     Director::getInstance()->replaceScene(GameLayer::createScene());
}


void GameLayer:: onEnter(){
    
    Layer::onEnter();
    
    //设置score的分数为xml里面的分数
    std::string ss= xmller.getLevel02();
    score = atoi(ss.c_str());
    log("onEnterScore = %d",score);
    
    
    auto contlistener = EventListenerPhysicsContact::create();
    contlistener->onContactBegin =CC_CALLBACK_1(GameLayer::on, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(contlistener, this);
    

    log("onEnter()//////////////////");
}

bool GameLayer::on(PhysicsContact& contact)
{
    switch (contact.getShapeA()->getBody()->getContactTestBitmask()|contact.getShapeB()->getBody()->getContactTestBitmask())
    {
            
        case BALL_MASK|WALL_MASK:
            
        {
            auto A = dynamic_cast<Bullet*>(contact.getShapeA()->getBody()->getNode());
            auto B = dynamic_cast<Bullet*>(contact.getShapeB()->getBody()->getNode());
            
            if (A==nullptr && B==nullptr) {
                return false;
            }
            Bullet* M;
            if (A==nullptr) {
                M=B;
            }else
            {
                M=A;
            }
            int a = M->getHp();
            M->setHp(--a);
            
            if (M->getHp() ==0) {
                M->removeFromParent();
                bulletArray.eraseObject(M);
                M=nullptr;
            }
        }
            break;
        default:
            break;
            log("子弹碰到墙壁");
    }
    return true;
    
}

void GameLayer::continueGame(){  //暂停代理方法1
    Director::getInstance()->resume();
}


void GameLayer::restartGame(){  //暂停代理方法2
    Director::getInstance()->replaceScene(GameLayer::createScene());
    Director::getInstance()->resume();
}

void GameLayer::nextLevel(){        //胜利层下一关
    
    log("gamelayer 下一关");
    
    std::string level01= xmller.getLevel01();
    int  number=atoi(level01.c_str());
    
    if (number>0 && number<=5 ) {
        number++;
        char temp[50];
        sprintf(temp,"%d",number);
        
        xmller.changeLevel01(temp);//改变xml数据
        xmller.XmlParse(str);//解析
        
        if (number>5) {
            
            number=1;
            char temp[50];
            sprintf(temp,"%d",number);
            
            xmller.changeLevel01(temp);//改变xml数据
            xmller.XmlParse(str);//解析
        }
        
        
        //判断关卡，改变xmller子弹的数量
        switch (number) {
            case 1: //第一关
            {
                //改变子弹的数量
                int tt = 30;
                sprintf(temp, "%d",tt);
                xmller.changeLevel03(temp);
                xmller.XmlParse(str);//解析
            }
                break;
            case 2:
            {
                //改变子弹的数量
                int tt = 40;
                sprintf(temp, "%d",tt);
                xmller.changeLevel03(temp);
                xmller.XmlParse(str);//解析
            }
                break;
            case 3:
                
            {
                //改变子弹的数量
                int tt = 50;
                sprintf(temp, "%d",tt);
                xmller.changeLevel03(temp);
                xmller.XmlParse(str);//解析
            }
                break;
            case 4:
                
            {
                //改变子弹的数量
                int tt = 30;
                sprintf(temp, "%d",tt);
                xmller.changeLevel03(temp);
                xmller.XmlParse(str);//解析
            }
                break;
            case 5:
                
            {
                //改变子弹的数量
                int tt = 20;
                sprintf(temp, "%d",tt);
                xmller.changeLevel03(temp);
                xmller.XmlParse(str);//解析
            }
                break;
                
            default:
                break;
        }
        
        
        
        
        
        
        
    }
    
    
    Director::getInstance()->replaceScene(GameLayer::createScene());
    
}
void GameLayer::winRestart(){       //重新开始
    
    log("gamelayer 重新开始");
    Director::getInstance()->replaceScene(GameLayer::createScene());

}


void GameLayer::updateStart(float dt){

    scheduleUpdate();
}
//
void GameLayer::update(float dt){
    

    for (int i =0; i<3; i++) {
        
        m_world->step(1/180.0f);
    }
    //动态改变界面上的金钱数量
    auto str = __String::createWithFormat("Money: %d",score);
    scoreLabel->setString(str->getCString());
    
    //改变xml数据
    char temp[50];
    sprintf(temp, "%d",score);
    xmller.changeLevel02(temp);
    
    

    //如果没打完敌人则显示失败层
    //得到xmller里面的子弹数量来比较
    
    std::string kk= xmller.getLevel03();
    int gg=atoi(kk.c_str());
    
    if (tempBullet.size()==gg &&bulletArray.size()==0 && gebulinArray.size()>0) {
        
        //添加失败层
        auto loseLayer = LoseLayer::createLayer();
        loseLayer->setPosition(Vec2::ZERO);
        loseLayer->setLoseDelegate(this);
        addChild(loseLayer,2);
        
        
        //触摸吞噬
        auto lis = EventListenerTouchOneByOne::create();
        lis->setSwallowTouches(true);
        lis->onTouchBegan=([](Touch*, Event*){
            return true;
        });
        _eventDispatcher->addEventListenerWithSceneGraphPriority(lis, loseLayer);
    

    
    
        unscheduleUpdate(); //停止调度
        tempBullet.clear();
    
    }



}

void GameLayer:: addBall(Point p){

    
   auto bullet = Bullet::create();
    
    bullet->setScale(0.5);
    bullet->setPosition(p);
    
    this->addChild(bullet);
    float tt = sqrtf(x*x+ y*y);
    
    auto body = bullet->getPhysicsBody();
    
    body->setVelocity(Vec2(x, y)/tt*1600);
    
    bullet->getPhysicsBody()->setContactTestBitmask(BALL_MASK);
    
    
    bulletArray.pushBack(bullet);   //子弹添加到数组
    tempBullet.pushBack(bullet);
    log("子弹数==%zd",bulletArray.size());
  
    
    
}

void GameLayer:: touchTest(){
    
    auto listener = EventListenerTouchOneByOne::create();
    
    listener->onTouchBegan = [&](Touch* t,Event* e){
        
//        log("touchbegin");
        
        Vec2 lo= t->getLocation();
        int gunX = gun->getPositionX();
        int gunY = gun->getPositionY();
        x = lo.x-gunX;
        y = lo.y-gunY;
        float atan = atan2f(x, y)*180/3.14;
        //        log("atan=%f",atan);
        
//        if (atan>=-10 && atan<=250) {
            gun->setRotation(atan);
            
//        }

        
        return true;
    };
    
    
    listener->onTouchMoved =[&](Touch* t,Event* e){
        
        
        Vec2 lo= t->getLocation();
        int gunX = gun->getPositionX();
        int gunY = gun->getPositionY();
        x = lo.x-gunX;
        y = lo.y-gunY;
        float atan = atan2f(x, y)*180/3.14;
        //        log("atan=%f",atan);
        
        if (atan>=-10 && atan<=250) {
            gun->setRotation(atan);
            
        }
        
        
    };
    
    
    listener->onTouchEnded =[&](Touch* t,Event* e){
        
//        log("onTouchEnded");
        
        butemp++;

        std::string kk= xmller.getLevel03();
        int gg=atoi(kk.c_str());

        
        //得到xmller里面的子弹数量来比较,小于它则可以发射
        if (butemp<=gg) {
            
            bulletNumber--;
            log("子弹数量=%d",bulletNumber);
            
            auto stri = __String::createWithFormat("Bullet: %d",bulletNumber);
            
            bulletLabel->setString(stri->getCString());
            
            this->addBall(Vec2(gun->getPositionX(),gun->getPositionY()));
  
        }
        
        
      
        
  
        
        
        
        
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
}

void GameLayer:: loadLayer(){
   //从xml里面读数据
    xmller.XmlParse(str);
    std::string levelnumber= xmller.getLevel01();
    int  iii=atoi(levelnumber.c_str());
    log("------xmlLevel=%d",iii);
    level=iii;
    
    auto str = __String ::createWithFormat("Scene_%d.csb",level);

    node = CSLoader::createNode(str->getCString());
    
    node->setAnchorPoint(Vec2( 0.5,0.5));

    node->setPosition(Vec2(visibleSize/2));
    
    this->addChild(node);
    
    switch (level) {
        case 1:
            addGangti1();
            addMonster1();
            break;
        case 2:
            addGangti2();
            addMonster2();
            break;
        case 3:
            addGangti3();
            addMonster3();
            break;
        case 4:
            addGangti4();
            addMonster4();
            break;
        case 5:
            addGangti5();
            addMonster5();
            break;
        default:
            break;
    }
    
}


//添加怪物(5关)

void GameLayer:: addMonster1(){
    
    //1.大怪  2.蛋蛋  3.树怪  4.橡皮怪  5.萝卜怪
    
    auto m1 = Monster::create(Boss_type::Boss_3);
    auto m2 = Monster::create(Boss_type::Boss_1);
    auto m3 = Monster::create(Boss_type::Boss_3);
    auto m4 = Monster::create(Boss_type::Boss_3);
    auto m5 = Monster::create(Boss_type::Boss_3);
    auto m6 = Monster::create(Boss_type::Boss_3);
    auto m7 = Monster::create(Boss_type::Boss_3);
    auto m8 = Monster::create(Boss_type::Boss_3);
    auto m9 = Monster::create(Boss_type::Boss_3);

    m1->setPosition(Vec2(464,562));
    m2->setPosition(Vec2(822,566));
    m3->setPosition(Vec2(242,441));
    m4->setPosition(Vec2(462,437));
    m5->setPosition(Vec2(661,433));
    m6->setPosition(Vec2(872,434));
    m7->setPosition(Vec2(518,262));
    m8->setPosition(Vec2(836,261));
    m9->setPosition(Vec2(676,129));
    
    addChild(m1);
    addChild(m2);
    addChild(m3);
    addChild(m4);
    addChild(m5);
    addChild(m6);
    addChild(m7);
    addChild(m8);
    addChild(m9);
    
    gebulinArray.pushBack(m1);
    gebulinArray.pushBack(m2);
    gebulinArray.pushBack(m3);
    gebulinArray.pushBack(m4);
    gebulinArray.pushBack(m5);
    gebulinArray.pushBack(m6);
    gebulinArray.pushBack(m7);
    gebulinArray.pushBack(m8);
    gebulinArray.pushBack(m9);

}
void GameLayer::addMonster2(){
    
    //1.大怪  2.蛋蛋  3.树怪  4.橡皮怪  5.萝卜怪
    auto m1 = Monster::create(Boss_type::Boss_2);
    auto m2 = Monster::create(Boss_type::Boss_2);
    auto m3 = Monster::create(Boss_type::Boss_2);
    auto m4 = Monster::create(Boss_type::Boss_2);
    auto m5 = Monster::create(Boss_type::Boss_1);
    auto m6 = Monster::create(Boss_type::Boss_2);
    auto m7 = Monster::create(Boss_type::Boss_2);
    auto m8 = Monster::create(Boss_type::Boss_2);

    
    m1->setPosition(Vec2(162,406));
    m2->setPosition(Vec2(448,418));
    m3->setPosition(Vec2(674,414));
    m4->setPosition(Vec2(309,296));
    m5->setPosition(Vec2(785,287));
    m6->setPosition(Vec2(317,115));
    m7->setPosition(Vec2(578,169));
    m8->setPosition(Vec2(816,123));

    
    addChild(m1);
    addChild(m2);
    addChild(m3);
    addChild(m4);
    addChild(m5);
    addChild(m6);
    addChild(m7);
    addChild(m8);

    
    gebulinArray.pushBack(m1);
    gebulinArray.pushBack(m2);
    gebulinArray.pushBack(m3);
    gebulinArray.pushBack(m4);
    gebulinArray.pushBack(m5);
    gebulinArray.pushBack(m6);
    gebulinArray.pushBack(m7);
    gebulinArray.pushBack(m8);

}
void GameLayer::addMonster3(){
    
    
    //1.大怪  2.蛋蛋  3.树怪  4.橡皮怪  5.萝卜怪
    auto m1 = Monster::create(Boss_type::Boss_5);
    auto m2 = Monster::create(Boss_type::Boss_5);
    auto m3 = Monster::create(Boss_type::Boss_5);
    auto m4 = Monster::create(Boss_type::Boss_5);
    auto m5 = Monster::create(Boss_type::Boss_5);
    auto m6 = Monster::create(Boss_type::Boss_5);
    auto m7 = Monster::create(Boss_type::Boss_1);
    auto m8 = Monster::create(Boss_type::Boss_5);
    auto m9 = Monster::create(Boss_type::Boss_5);
    auto m10 = Monster::create(Boss_type::Boss_5);
    auto m11 = Monster::create(Boss_type::Boss_5);
    auto m12 = Monster::create(Boss_type::Boss_5);
    
    m1->setPosition(Vec2(383,525));
    m2->setPosition(Vec2(623,601));
    m3->setPosition(Vec2(873,597));
    m4->setPosition(Vec2(549,439));
    m5->setPosition(Vec2(855,451));
    m6->setPosition(Vec2(327,348));
    m7->setPosition(Vec2(719,328));
    m8->setPosition(Vec2(385,150));
    m9->setPosition(Vec2(570,207));
    m10->setPosition(Vec2(873,221));
    m11->setPosition(Vec2(553,86));
    m12->setPosition(Vec2(760,121));
    
    addChild(m1);
    addChild(m2);
    addChild(m3);
    addChild(m4);
    addChild(m5);
    addChild(m6);
    addChild(m7);
    addChild(m8);
    addChild(m9);
    addChild(m10);
    addChild(m11);
    addChild(m12);
    
    gebulinArray.pushBack(m1);
    gebulinArray.pushBack(m2);
    gebulinArray.pushBack(m3);
    gebulinArray.pushBack(m4);
    gebulinArray.pushBack(m5);
    gebulinArray.pushBack(m6);
    gebulinArray.pushBack(m7);
    gebulinArray.pushBack(m8);
    gebulinArray.pushBack(m9);
    gebulinArray.pushBack(m10);
    gebulinArray.pushBack(m11);
    gebulinArray.pushBack(m12);
    
}
void GameLayer::addMonster4(){
    
    //1.大怪  2.蛋蛋  3.树怪  4.橡皮怪  5.萝卜怪
    auto m1 = Monster::create(Boss_type::Boss_4);
    auto m2 = Monster::create(Boss_type::Boss_4);
    auto m3 = Monster::create(Boss_type::Boss_4);
    auto m4 = Monster::create(Boss_type::Boss_4);
    auto m5 = Monster::create(Boss_type::Boss_4);
    auto m6 = Monster::create(Boss_type::Boss_4);
    auto m7 = Monster::create(Boss_type::Boss_4);
    auto m8 = Monster::create(Boss_type::Boss_4);
    auto m9 = Monster::create(Boss_type::Boss_1);
    
    m1->setPosition(Vec2(362,570));
    m2->setPosition(Vec2(850,576));
    m3->setPosition(Vec2(569,506));
    m4->setPosition(Vec2(366,435));
    m5->setPosition(Vec2(599,357));
    m6->setPosition(Vec2(859,414));
    m7->setPosition(Vec2(354,315));
    m8->setPosition(Vec2(688,85));
    m9->setPosition(Vec2(853,100));
    
    addChild(m1);
    addChild(m2);
    addChild(m3);
    addChild(m4);
    addChild(m5);
    addChild(m6);
    addChild(m7);
    addChild(m8);
    addChild(m9);
    
    gebulinArray.pushBack(m1);
    gebulinArray.pushBack(m2);
    gebulinArray.pushBack(m3);
    gebulinArray.pushBack(m4);
    gebulinArray.pushBack(m5);
    gebulinArray.pushBack(m6);
    gebulinArray.pushBack(m7);
    gebulinArray.pushBack(m8);
    gebulinArray.pushBack(m9);

}
void GameLayer::addMonster5(){

    //1.大怪  2.蛋蛋  3.树怪  4.橡皮怪  5.萝卜怪
    auto m1 = Monster::create(Boss_type::Boss_1);
    auto m2 = Monster::create(Boss_type::Boss_1);
    auto m3 = Monster::create(Boss_type::Boss_1);
    auto m4 = Monster::create(Boss_type::Boss_1);
    auto m5 = Monster::create(Boss_type::Boss_1);
    auto m6 = Monster::create(Boss_type::Boss_1);
    
    
    m1->setPosition(Vec2(534,561));
    m2->setPosition(Vec2(541,397));
    m3->setPosition(Vec2(545,227));
    m4->setPosition(Vec2(791,461));
    m5->setPosition(Vec2(796,299));
    m6->setPosition(Vec2(805,120));
    
    addChild(m1);
    addChild(m2);
    addChild(m3);
    addChild(m4);
    addChild(m5);
    addChild(m6);

    gebulinArray.pushBack(m1);
    gebulinArray.pushBack(m2);
    gebulinArray.pushBack(m3);
    gebulinArray.pushBack(m4);
    gebulinArray.pushBack(m5);
    gebulinArray.pushBack(m6);
    
}


//添加一些显示标签
void GameLayer:: addSprite(){
    
    //显第几关的label
    auto temp = __String::createWithFormat("Level: %d",level);
    levelLabel = Label::createWithSystemFont(temp->getCString(), "fonts/Marker Felt.ttf", 32);
    levelLabel->setPosition(Point(80, visibleSize.height-40));
    levelLabel->setColor(Color3B(255, 255, 255));
    this->addChild(levelLabel,1);
    
    
    //显分数的label
    xmller.XmlParse(str);
    std::string level02= xmller.getLevel02();
    int  number=atoi(level02.c_str());
    log("xml score=%d",number);
    auto sc = __String::createWithFormat("Money: %d",number);
    scoreLabel = Label::createWithSystemFont(sc->getCString(), "fonts/Marker Felt.ttf", 32);
    scoreLabel->setPosition(Point(110, visibleSize.height-80));
    scoreLabel->setColor(Color3B(255, 255, 0));
    this->addChild(scoreLabel,1);
    
    
    //显示子弹数量
    std::string level03 = xmller.getLevel03();
    int bb = atoi(level03.c_str());
    auto cc = __String::createWithFormat("Bullet: %d",bb);
    bulletLabel = Label::createWithSystemFont(cc->getCString(), "fonts/Marker Felt.ttf", 32);
    bulletLabel->setPosition(Point(110, visibleSize.height-120));
    bulletLabel->setColor(Color3B(0, 255, 0));
    this->addChild(bulletLabel,1);
    
    //暂停的按钮
    
    auto ub=Button::create();
    ub->loadTextureNormal("newPause_Normal.png");
    ub->loadTexturePressed("newPause_Select.png");
    ub->setScale(0.4);
    ub->setScale9Enabled(true);
    ub->setContentSize(Size(128,128));
    ub->setPressedActionEnabled(false);
    ub->setZoomScale(2.0f);//大于1有效小于1无效
    ub->addClickEventListener([this](Ref*){
        
        
        auto l = PauseLayer::createLayer();
        
        l->setDelegate(this);   //设置代理----------------------
        this->addChild(l);
        
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan=([](Touch*, Event*){
            return true;
        });
        
        _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, l);
        
        Director::getInstance()->pause();
        
        
    });
    ub->setPosition(Vec2(visibleSize.width-50,50));
    this->addChild(ub);
}

//检测碰撞，删除怪物
void GameLayer:: checkCollision(float f){

//    log("检测碰撞");
  
    Vector<Monster*>::iterator it;//哥布林
    Vector<Bullet*>::iterator it1;//子弹
    for (it1=bulletArray.begin(); it1!=bulletArray.end();it1++)
        
    {       auto hh = *it1;     //子弹
        
     for (it=gebulinArray.begin(); it!=gebulinArray.end();it++ )
        {
    
         auto gg = *it;          //哥布林
            if (iscollision(hh,gg))
            {
                log("子弹和怪物碰撞");
                
               //创建粒子

                auto par = ParticleSun::create();
                par->setDuration(0.5);
                par->setSpeed(100);
                par->setAutoRemoveOnFinish(true);//自动移除
                par->setPosition(gg->getPosition());
                addChild(par,1);

                gg->removeFromParent();     //列表中删除
                gg=nullptr;
                score+=1;
                gebulinArray.erase(it); //数组中删除
                
                log("怪物数==%zd",gebulinArray.size());
                
                if (gebulinArray.size() ==0) {  //怪物数0 显示胜利页面
                    
                    //胜利页面
                    auto winLayer = WinLayer::createLayer();
                    winLayer->setPosition(Vec2::ZERO);
                    winLayer->setWinDelegate(this);
                    addChild(winLayer);
                    
                    //触摸吞噬
                    auto lis = EventListenerTouchOneByOne::create();
                    lis->setSwallowTouches(true);
                    lis->onTouchBegan=([](Touch*, Event*){
                        return true;
                    });
                    _eventDispatcher->addEventListenerWithSceneGraphPriority(lis, winLayer);
                }
                
                
                
              
              break;
            }
          
        }
      
    }
    
    //这种方法删除也是可以的
//    for (int i = 0; i<gebulinArray.size(); i++) {
//        for (int j =0; j<bulletArray.size(); j++) {
//
//            
//            if (iscollision(gebulinArray.at(i),bulletArray.at(j)))
//            {
//                gebulinArray.at(i)->removeFromParent() ;
//                gebulinArray.erase(i);
//                log("size = %zd",gebulinArray.size());
//            }
//        }
//        
//    }
 


}


//子弹和怪物碰撞
bool GameLayer:: iscollision(Sprite *sprite1, Sprite *sprite2){
    auto rect1 = sprite1->getBoundingBox();//子弹
    auto rect2 = sprite2->getBoundingBox();//怪物

   return !(rect1.getMaxX() < rect2.getMinX() ||
            rect2.getMaxX() <  rect1.getMinX() ||
            rect1.getMaxY() < rect2.getMinY() ||
            rect2.getMaxY() <rect1.getMinY());
}

//第一关(添加5关的关卡刚体)
void GameLayer:: addGangti1(){
    
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
    for (int i =1; i<= 2; i++) {

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
//第二关
void GameLayer:: addGangti2(){
    
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
//第三关
void GameLayer::addGangti3(){

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
    for (int i =1; i<= 2; i++) {
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
//第四关
void GameLayer::addGangti4(){

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
//第五关
void GameLayer::addGangti5(){
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


void GameLayer:: onExit(){

    Layer::onExit();
    _eventDispatcher->removeEventListenersForTarget(this);

}











