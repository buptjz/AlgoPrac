//
//  SearchInsertPosition.cpp
//  LeetCode
//
//  Created by WangJZ on 14-2-27.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
// http://oj.leetcode.com/problems/search-insert-position/

#include "leetcode_others.h"

int searchInsert(int A[], int n, int target) {
    int start = 0;
    int end = n - 1;
    int mid;
    if (target > A[n - 1]) {
        return n;
    }
    if (target < A[0]) {
        return 0;
    }
    while (start <= end) {
        mid = ((end - start) >> 1) + start;
        if (A[mid] == target) {
            return mid;
        }else if(A[mid] > target){
            if (A[mid - 1] < target) {
                return mid;
            }else{
                end = mid - 1;
            }
        }else{
            if (A[mid + 1] > target) {
                return mid + 1;
            }else{
                start = mid + 1;
            }
        }
    }
    return -1;
}

void testSearchInsert(){
    int a[] = {1,2,3,4,7};
    int n = 5;
    int target = 7;
    
    int rest = searchInsert(a, n, target);
    printf("Finished");
}