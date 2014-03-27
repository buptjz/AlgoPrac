//
//  MergeSortedArray.cpp
//  Algorithms
//
//  Created by WangJZ on 14-3-27.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_others.h"

static void merge(int A[], int m, int B[], int n) {
    if (m+n <= 0) return;
    int cur = m + n - 1;
    m--;
    n--;
    while (n >= 0) {
        if (m < 0 || A[m] <= B[n]) A[cur--] = B[n--];
        else A[cur--] = A[m--];
    }
}

void test2Merge(){
    int a[] = {1,4,5,0,0,0,0};
    int b[] = {2,3,3};
    merge(a, 3, b, 3);
    printf("Finished\n");
}