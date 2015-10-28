//
//  Xmller.h
//  testXml
//
//  Created by student on 15/8/24.
//
//

#ifndef __testXml__Xmller__
#define __testXml__Xmller__

#include <stdio.h>
#include <iostream>
#include "cocos2d.h"
#include "tinyxml2/tinyxml2.h"
using namespace tinyxml2;
using namespace cocos2d;
using namespace std;
class  Xmller {

public:
    
    //文件名字进来直接拷贝到沙盒解析放到容器里面返回
    void createwithxmlfile(std::string xmlfile);
    
    //拷贝到沙盒
    void copyFileToPath(std::string xmlfile);
    //解析
    void XmlParse(std::string xmlfile);
    //修改节点
    void changeLevel01(std::string str);
    void changeLevel02(std::string str);
    void changeLevel03(std::string str);
    void changeLevel04(std::string str);
    void changeLevel05(std::string str);
    void changeLevel06(std::string str);
    //获得值
    std:: string getLevel01();
    std:: string getLevel02();
    std:: string getLevel03();
    std:: string getLevel04();
    std:: string getLevel05();
    std:: string getLevel06();
    
    //生成xml文档
    
    void giveBirthTo(std::string xmlfile);
    
private:
    //用来显示值的
    std::string str1;
    std::string str2;
    std::string str3;
    std::string str4;
    std::string str5;
    std::string str6;
    
    std::string wpath;
    
    XMLElement *parentelement;
    XMLDocument *myDocument;
    
    //节点值对象，用来改变值
    XMLNode *level01Node;
    XMLNode *level02Node;
    XMLNode *level03Node;
    XMLNode *level04Node;
    XMLNode *level05Node;
    XMLNode *level06Node;
    

};

#endif /* defined(__testXml__Xmller__) */
