//
//  TrappingRainWater.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-5.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/trapping-rain-water/

#include "leetcode_others.h"

int trap(int A[], int n) {
    if(n <=2) return 0;
    vector<int > left(n,0);
    vector<int > right(n,0);
    int currentMax = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] > currentMax) currentMax = A[i];
        left[i] = currentMax;
    }
    currentMax = 0;
    for (int i = n -1; i>= 0; i--) {
        if (A[i] >currentMax) currentMax = A[i];
        right[i] = currentMax;
    }
    int accum = 0;
    for (int i = 1; i < n- 1; i++) {//exlude the first and last one
        int contain = min(left[i-1], right[i+1]);
        accum += contain > A[i] ? contain - A[i] : 0;
    }
    return accum;
}

void testTrap(){
    int A[] = {};
    int res = trap(A, 0);
    cout<<res<<endl;
}