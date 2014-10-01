//
//  RemoveDuplicatesfromSortedArray.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-1.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_search.h"

int removeDuplicates(int A[], int n) {
    if (n == 0 || n == 1) return n;
    
    int total = n;
    int lastInd = 0;
    for (int i = 1; i < n; i++) {
        if (A[i] != A[lastInd]) {//跟前一个不重复
            A[++lastInd] = A[i];
        }else{//重复，计数减1
            total--;
        }
    }
    return total;
}