//
//  pointerVSArray.c
//  CiCT
//
//  Created by Wang JZ on 13-9-6.
//  Copyright (c) 2013年 Wang JZ. All rights reserved.
//

#include <stdio.h>
#include "arrayAndString.h"

/**
 玩转数组/指针实参，From C专家编程 P207
 重点是：作为参数的数组，数组的地址和数组首元素的地址不一样！！！
 **/
void testPointer(char *ca);

void testPointer(char ca[]){
    printf("&ca=%p\n&(ca[0])=%p\n&(ca[1])=%p",&ca,&(ca[0]),&(ca[1]));
}