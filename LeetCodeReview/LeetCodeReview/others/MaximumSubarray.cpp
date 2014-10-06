//
//  MaximumSubarray.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-6.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_dp.h"

//这是个难题，真的不骗你！
int maxSubArray(int A[], int n) {
    if (n == 0) return 0;
    
    int largest = A[0];
    int accum = A[0];
    for (int i = 1; i < n; i++) {
        if (accum < 0) accum = 0;
        accum += A[i];
        largest = max(largest,accum);
    }
    
    return largest;
}
