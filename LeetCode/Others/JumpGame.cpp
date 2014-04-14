//
//  JumpGame.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-2.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/jump-game/

#include "leetcode_dp.h"

bool canJump(int A[], int n) {
    int cover = 0;
    for (int i = 0; i < n; i++) {
        if (i > cover) return false;
        cover = max(cover,A[i] + i);
    }
    return true;
}

void testCanJump(){
    int A[] = {0,2,3};
    bool res = canJump(A, 3);
    printf("%d\n",res);
}
