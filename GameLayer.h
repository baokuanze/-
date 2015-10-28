//
//  GameLayer.h
//  stupidZombies
//
//  Created by student on 15/9/7.
//
//

#ifndef __stupidZombies__GameLayer__
#define __stupidZombies__GameLayer__

#include <stdio.h>
#include "cocos2d.h"
#include "Box2D/Box2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "Gun.h"
#include "Bullet.h"
#include "Monster.h"
#include "PauseLayer.h"
#include "WinLayer.h"
#include "LoseLayer.h"
#include "Xmller.h"
USING_NS_CC;

using namespace cocos2d::ui;
using namespace cocostudio;
using namespace timeline;
using namespace cocos2d ;
class GameLayer:public LayerColor,Delegate,WinLayerDelegate,LoseDelegate{
    
public:
    
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(GameLayer);
    void setPhyWorld(PhysicsWorld* world){m_world=world;

    }
    
    
public:
    //暂停页面代理
//    Delegate* delgate;
     void continueGame();
     void restartGame();
    
    //胜利页面代理
//    WinLayerDelegate* windelegate;
    void nextLevel();
    void winRestart();
    
    //失败代理
     void losenextLevel();
     void loseRestart();

    
    
public:
    
    void addBall(Point p);
    void touchTest();   //触摸检测
    void loadLayer();   //加载游戏关卡
    
    void addSprite();   //添加精灵UI界面
    
    void stopLayer();
   virtual void onEnter();
   virtual void onExit();

    
    void checkCollision(float f);
    bool iscollision(Sprite *sprite1, Sprite *sprite2);
    bool on(PhysicsContact& contact);
    
public:
    //解决穿透问题
    void updateStart(float dt);
    void update(float dt);
    void test();
    
public:
    //添加刚体
    void addGangti1();
    void addGangti2();
    void addGangti3();
    void addGangti4();
    void addGangti5();
public:
    //添加怪物
    void addMonster1();
    void addMonster2();
    void addMonster3();
    void addMonster4();
    void addMonster5();
    
private:
    
    float x;
    float y;
    float a;
    float l;

    Gun* gun;
    
    Size visibleSize;
    PhysicsWorld* m_world;
    Node* node;
    
    Vector<Monster*>gebulinArray;
    Vector<Bullet*>bulletArray;
    
    Vector<Bullet*>tempBullet;                             //

private:

    int level ;       //关卡数
    int score;          //分数
    int bulletNumber;   //子弹数
    int butemp;         //临时点击数，点击几下就不能调用addball()
    
    Label* levelLabel;  //关卡数标签
    Label* scoreLabel;  //分数标签
    Label* bulletLabel; //子弹数量
    
public:
    //数据存储
    Xmller xmller;//创建解析对象
    std::string str;

    
};
#endif /* defined(__stupidZombies__GameLayer__) */
