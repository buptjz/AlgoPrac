//
//  RemoveDuplicatesfromSortedArrayII.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-1.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_search.h"

int removeDuplicates(int A[], int n) {
    if (n == 0 || n == 1) return n;
    int lastInd = 1;
    
    int total = n;
    for (int i = 2; i < n; i++) {
        if (A[lastInd] == A[lastInd - 1] && A[lastInd] == A[i]) {//重复出现两次
            total--;
        }else{
            A[++lastInd] = A[i];
        }
    }
    return total;
}