//
//  main.c
//  LeetCode
//
//  Created by WangJZ on 14-1-12.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  

#include "leetcode_string.h"
#include "leetcode_list.h"
#include "others.h"
using namespace std;

int count(int i){
    static int count = 0;
    count += i;
    return count;
}

int main(void) {
    int i,j;
    for (i = 0; i <=5; i++) {
        j = count(i);
    }
    printf("%d",j);
    return 0;
}

