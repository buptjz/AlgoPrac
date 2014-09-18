//
//  SingleNumber.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-18.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_bit.h"

int singleNumber(int A[], int n) {
    int retVal = 0;
    for (int i = 0; i < n; i++) {
        retVal ^= A[i];
    }
    return retVal;
}