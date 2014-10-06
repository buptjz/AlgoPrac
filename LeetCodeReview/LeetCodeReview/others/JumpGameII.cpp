//
//  JumpGameII.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-6.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_others.h"

/*
 * We use "last" to keep track of the maximum distance that has been reached
 * by using the minimum steps "ret", whereas "curr" is the maximum distance
 * that can be reached by using "ret+1" steps. Thus,
 * curr = max(i+A[i]) where 0 <= i <= last.
 */


//大神的解法
int jump(int A[], int n) {
    int last = 0;
    int coverage = 0;
    int ret = 0;
    
    for (int i = 0 ; i < n; i++) {
        if (i > last) {
            ret++;
            last = coverage;
        }
        coverage = max(coverage,A[i] + i);
        
    }
    return ret;
}