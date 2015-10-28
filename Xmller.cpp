//
//  Xmller.cpp
//  testXml
//
//  Created by student on 15/8/24.
//
//

#include "Xmller.h"

//拷贝文件到沙盒
void Xmller::copyFileToPath(std::string xmlfile){

    
    FileUtils *fu=FileUtils::getInstance();
    
    std::string wrpath=fu->getWritablePath();
    
    log("沙盒路径==%s",wrpath.c_str());
    
    wrpath+=xmlfile;
    
    if(!fu->isFileExist(wrpath))
    {
        std::string dataPath=fu->fullPathForFilename(xmlfile.c_str());//获取App里面的路径
        std::string pFileContent=fu->getStringFromFile(dataPath);
        
        FILE *file=fopen(wrpath.c_str(), "w");
        
        if(file)
        {
            fputs(pFileContent.c_str(),file);
            fclose(file);
        }
    }
    
    log("拷贝文件成功");

}

//xml解析
void Xmller:: XmlParse(std::string xmlfile){
    
    FileUtils *fe=FileUtils::getInstance();
    wpath=fe->getWritablePath();
    wpath+=xmlfile;
    
    myDocument=new XMLDocument();
    XMLError errorID=myDocument->LoadFile(wpath.c_str());


    if (errorID != 0) {
        log("解析错误!");
        return;
    }

    XMLElement * rootelement=myDocument->RootElement();
    
    while(!rootelement->GetText())
    {
        parentelement=rootelement;
        
        rootelement=rootelement->FirstChildElement();
    }

    int index=0;
    
    do
    {
        if(index++)
        parentelement=parentelement->NextSiblingElement();
        
        
        rootelement=parentelement->FirstChildElement();
        str1=rootelement->GetText();////显示数据
        level01Node = rootelement->FirstChild();//用来改变分数
        
        
        rootelement=rootelement->NextSiblingElement();
        str2=rootelement->GetText();//
        level02Node = rootelement->FirstChild();
        
        
        rootelement=rootelement->NextSiblingElement();
         str3=rootelement->GetText();////
         level03Node = rootelement->FirstChild();
        
        rootelement=rootelement->NextSiblingElement();
        str4=rootelement->GetText();////
        level04Node = rootelement->FirstChild();
        
        rootelement=rootelement->NextSiblingElement();
        str5=rootelement->GetText();////
        level05Node = rootelement->FirstChild();
        
        rootelement=rootelement->NextSiblingElement();
        str6=rootelement->GetText();////
        level06Node = rootelement->FirstChild();
        
        // int  number=atoi(num.c_str());    //类型转换
        // int  locked=atoi(lock.c_str());
        
        
    }while (parentelement->NextSiblingElement());
   
    log("解析文件成功");

}

void Xmller:: createwithxmlfile(std::string xmlfile){

    copyFileToPath(xmlfile);    //拷贝xml文件到沙盒
    XmlParse(xmlfile);          //解析xml文件
    

}

//修改节点的值
void Xmller:: changeLevel01(std::string str){

    level01Node->SetValue(str.c_str());
    myDocument->SaveFile(wpath.c_str());

}

void Xmller:: changeLevel02(std::string str){

    
    level02Node->SetValue(str.c_str());
    myDocument->SaveFile(wpath.c_str());

}

void Xmller:: changeLevel03(std::string str){

     level03Node->SetValue(str.c_str());
    myDocument->SaveFile(wpath.c_str());

}

void Xmller:: changeLevel04(std::string str){
    
    level04Node->SetValue(str.c_str());
    myDocument->SaveFile(wpath.c_str());
    
}

void Xmller:: changeLevel05(std::string str){
    
    level05Node->SetValue(str.c_str());
    myDocument->SaveFile(wpath.c_str());
    
}

void Xmller:: changeLevel06(std::string str){
    
    level06Node->SetValue(str.c_str());
    myDocument->SaveFile(wpath.c_str());
    
}




//返回节点的值
std:: string Xmller:: getLevel01(){
    
    return str1;

}
std:: string Xmller:: getLevel02(){
    return str2;

}
std:: string Xmller:: getLevel03(){
    return str3;

}

std:: string Xmller:: getLevel04(){
    return str4;
    
}

std:: string Xmller:: getLevel05(){
    return str5;
    
}

std:: string Xmller:: getLevel06(){
    return str6;
    
}

//生成文件
void Xmller:: giveBirthTo(std::string xmlfile){

    std::string filePath = FileUtils::getInstance()->getWritablePath() + xmlfile;
    log("生成文件＝%s",filePath.c_str());
    XMLDocument *pDoc = new XMLDocument();
    
    //xml 声明（参数可选）
    XMLDeclaration *pDel = pDoc->NewDeclaration("xml version=\"1.0\" encoding=\"UTF-8\"");
    
    pDoc->LinkEndChild(pDel);
    
    //添加plist节点
    XMLElement *plistElement = pDoc->NewElement("Chapters");
//    plistElement->SetAttribute("version", "1.0");
    pDoc->LinkEndChild(plistElement);
    
//    XMLComment *commentElement = pDoc->NewComment("this is xml comment");
//    plistElement->LinkEndChild(commentElement);
    
    //添加dic节点
//    XMLElement *dicElement = pDoc->NewElement("dic");
//    plistElement->LinkEndChild(dicElement);
    
    //添加key节点
//    XMLElement *keyElement = pDoc->NewElement("key");
//    keyElement->LinkEndChild(pDoc->NewText("Text"));
//    dicElement->LinkEndChild(keyElement);
    
    XMLElement *arrayElement = pDoc->NewElement("Chapter");
    plistElement->LinkEndChild(arrayElement);
    
//    for (int i = 0; i<3; i++) {
//        XMLElement *elm = pDoc->NewElement("name");
//        elm->LinkEndChild(pDoc->NewText("Cocos2d-x"));
//        arrayElement->LinkEndChild(elm);
//    }
    
    XMLElement* elm = pDoc->NewElement("Level");     //标签
     elm->LinkEndChild(pDoc->NewText("0"));             //数值
     arrayElement->LinkEndChild(elm);
    
    XMLElement* elm1 = pDoc->NewElement("Score");
    elm1->LinkEndChild(pDoc->NewText("0"));
    arrayElement->LinkEndChild(elm1);
    
    XMLElement* elm2 = pDoc->NewElement("BulletNumber");
    elm2->LinkEndChild(pDoc->NewText("0"));
    arrayElement->LinkEndChild(elm2);
    
    XMLElement* elm3 = pDoc->NewElement("gun");
    elm3->LinkEndChild(pDoc->NewText("0"));
    arrayElement->LinkEndChild(elm3);
    
    XMLElement* elm4 = pDoc->NewElement("level05");
    elm4->LinkEndChild(pDoc->NewText("0"));
    arrayElement->LinkEndChild(elm4);
    
    XMLElement* elm5 = pDoc->NewElement("level06");
    elm5->LinkEndChild(pDoc->NewText("0"));
    arrayElement->LinkEndChild(elm5);
    
    pDoc->SaveFile(filePath.c_str());
    pDoc->Print();
    
    delete pDoc;
}




