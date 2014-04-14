//
//  fork.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-11.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include <stdio.h>
#include <unistd.h>
/*
 腾讯笔试题：问下面函数执行时候会输出多少个-？
 
 答案：
 关于fork的技术，请参见这篇文章http://www.spongeliu.com/123.html
 printf是打印在缓冲区，而fork的时候会继承缓冲区，所以第二次fork的时候会多输出一个-，总计为8
*/
void startFork(){
    int i;
    //如果i<2那么输出24个
    for (i = 0; i < 2; i++) {
        fork();
        printf("-");
    }
}