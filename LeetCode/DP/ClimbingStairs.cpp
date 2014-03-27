//
//  ClimbingStairs.cpp
//  Algorithms
//
//  Created by WangJZ on 14-3-27.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/climbing-stairs/

/*经典的爬楼梯问题，就是fibonacci数列*/

#include "leetcode_dp.h"


int climbStairs(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    int last,lastlast,cur;
    lastlast = 1;
    last = 1;
    for (int i = 2; i <= n; i++) {
        cur = last + lastlast;
        lastlast = last;
        last = cur;
    }
    return cur;
}

void testClimbStars(){
    printf("Finished %d\n",climbStairs(6));
}