//
//  align_malloc.cpp
//  Algorithms
//
//  Created by WangJZ on 14-3-20.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

/*
 
13.9编写支持对其分配的 malloc和free函数，分配内存时，malloc函数返回的地址必须能被2的n次方整出。
 
*/

#include "cict_c++.h"

void *align_malloc(size_t alignment,size_t byte_needed){
    void *p1;//申请的指针
    void **p2;//返回的指针
    size_t offset = alignment - 1  + sizeof(void*);
    if((p1 = (void *)malloc(byte_needed + offset)) == NULL){
        return NULL;
    };
    p2 = (void **)(((size_t)(p1) + offset) & ~(alignment - 1));
    p2[-1] = p1;
    return p2;
}

void align_free(void *p2){
    void *p1 = ((void**)p2)[-1];
    free(p1);
}
