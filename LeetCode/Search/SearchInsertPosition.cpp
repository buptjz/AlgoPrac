//
//  SearchInsertPosition.cpp
//  LeetCode
//
//  Created by WangJZ on 14-2-27.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
// http://oj.leetcode.com/problems/search-insert-position/

#include "leetcode_others.h"

/*----2014.3.27更新 二分查找最后的start位置就是应该插入的位置----*/
int searchInsert(int A[], int n, int target) {
    int start = 0;
    int end = n - 1;
    int mid;
    while (start <= end) {
        mid = ((end - start) >> 1) + start;
        if (A[mid] == target) return mid;
        else if(A[mid] > target) end = mid - 1;
        else start = mid + 1;
    }
    return start;
}

void testSearchInsert(){
    int a[] = {1,1,3,4,7};
    int n = 5;
    int target = 2;
    int res = searchInsert(a, n, target);
    printf("Finished %d\n",res);
}