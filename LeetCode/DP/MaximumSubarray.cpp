//
//  MaximumSubarray.cpp
//  Algorithms
//
//  Created by WangJZ on 14-3-25.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/maximum-subarray/

//新浪面试题，查找最大子数组

#include "leetcode_dp.h"

int maxSubArray(int A[], int n) {
    int maxL = A[0];
    int accum = 0;
    for(int i = 0; i < n; i++){
        accum += A[i];
        if(accum > maxL) maxL = accum;
        if(accum < 0){
            accum = 0;
        }
    }
    return maxL;
}