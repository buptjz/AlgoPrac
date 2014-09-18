//
//  SingleNumberII.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-18.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  https://oj.leetcode.com/problems/single-number-ii/

#include "leetcode_bit.h"


int singleNumber(int A[], int n) {
    int a[32] = {};
    for (int i = 0 ; i < n; i++) {
        for (int bit = 0; bit < 32; bit++) {
            a[bit] += (A[i] >> bit) & 1;
        }
    }
    
    int ret = 0;
    for (int bit = 0; bit < 32; bit++) {
        ret += (a[bit] % 3) << bit;
    }
    return ret;
}

void testSingleNumber(){
    int test[] = {12,-8,7,7,7,12,12};
    int n = 7;
    cout<<singleNumber(test, n) <<endl;
}