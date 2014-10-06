//
//  JumpGame.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-6.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_dp.h"

//注意边缘条件！

bool canJump(int A[], int n) {
    if (n == 0) return true;
    if (A[0] == 0 && n > 1) return false;
    
    vector<int> state(n,0);
    state[0] = A[0];
    
    for (int i = 1; i < n - 1; i++) {
        state[i] = max(A[i],state[i-1] - 1);
        if (state[i] == 0) return false;
    }
    
    
    return true;
}
