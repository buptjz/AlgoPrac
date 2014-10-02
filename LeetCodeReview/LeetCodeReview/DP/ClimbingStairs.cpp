//
//  ClimbingStairs.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-2.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_dp.h"

int climbStairs(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    if (n == 2) return 2;
    
    int a1 = 1;
    int a2 = 2;
    
    for (int i = 3; i <= n; i++) {
        int tmp = a1 + a2;
        a1 = a2;
        a2 = tmp;
    }
    return a2;
}
