//
//  ASingleton.cpp
//  Algorithms
//
//  Created by WangJZ on 14-3-26.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  单例模式之懒汉模式

#include "ASingleton.h"


class ASingleton{
public:
    static ASingleton& getInstance(){
        static ASingleton as;
        return as;
    }
private:
    ASingleton();//构造函数
    ASingleton(ASingleton const &rhs);//拷贝
    ASingleton& operator=(ASingleton const &rhs);//=号重载
    ~ASingleton();//析构
};

//范例代码和注意事项 (最优实现)