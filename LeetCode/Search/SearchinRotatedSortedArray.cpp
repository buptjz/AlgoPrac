//
//  SearchinRotatedSortedArray.cpp
//  LeetCode
//
//  Created by WangJZ on 14-2-26.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_others.h"

int searchHelper(int A[],int n,int target,int start,int end){
    if (start > end) return -1;
    int mid = (start + end) >> 1;
    if (target == A[mid]) return mid;
    if (target < A[mid]) {
        if (A[end] >= target && A[end] < A[mid]) {//非顺串，并且结尾大于target
            return searchHelper(A, n, target, mid+1, end);
        }else{
            return searchHelper(A, n, target, start,  mid-1);
        }
    }else{
        if (A[start] > A[mid] && A[start] <= target) {
            return searchHelper(A, n, target, start, mid-1);
        }else{
            return searchHelper(A, n, target, mid+1, end);
        }
    }
}
int search(int A[], int n, int target) {
    return searchHelper(A, n, target, 0, n-1);
}

void testSearchRotate(){
    int a[] = {7,8,9,1,2,3,4,5,6};
    int target = 6;
    int n = 9;
    int rest = search(a, n, target);
    printf("Finished");
}