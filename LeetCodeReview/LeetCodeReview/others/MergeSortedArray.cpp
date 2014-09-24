//
//  MergeSortedArray.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-24.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_others.h"

void merge(int A[], int m, int B[], int n) {
    if (n == 0) return;
    
    A[m+n] = '\0';//leetcode 上这一句是不需要的！
    
    int aIndex = m - 1,bIndex = n - 1;
    int lastIndex = m + n - 1;
    while (bIndex >= 0 && aIndex >= 0) {
        if (A[aIndex] > B[bIndex]) A[lastIndex--] = A[aIndex--];
        else A[lastIndex--] = B[bIndex--];
    }
    
    while (bIndex >= 0)
        A[lastIndex--] = B[bIndex--];
    
    
}

void testMerge(){
    int A[8] = {0};
    int B[5] = {1,2,3,4,5};
    merge(A, 0, B, 5);
    
}
