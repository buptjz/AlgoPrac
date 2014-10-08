//
//  TrappingRainWater.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-8.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_divide_conquer.h"

int trap(int A[], int n) {
    if (n <= 2) return 0;
    
    vector<int> left(n,0);
    vector<int> right(n,0);
    
    int cur_max = 0;
    for (int i = 0; i < n; i++) {
        cur_max = max(cur_max,A[i]);
        left[i] = cur_max;
    }
    
    cur_max = 0;
    for (int i = n - 1; i >= 0; i--) {
        cur_max = max(cur_max,A[i]);
        right[i] = cur_max;
    }
    
    int accum = 0;
    for (int i = 1 ; i <= n - 2; i++) {
        int level = min(left[i],right[i]);
        if (A[i] < level)
            accum += level - A[i];
    }
    
    return accum;
    
}