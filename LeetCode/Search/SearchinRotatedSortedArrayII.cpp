//
//  SearchinRotatedSortedArrayII.cpp
//  Algorithms
//
//  Created by WangJZ on 14-3-25.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/search-in-rotated-sorted-array-ii/

#include "leetcode_others.h"

static bool searchHelper(int A[],int n,int target,int start,int end){
    if (start > end) return false;
    int mid = (start + end) >> 1;
    if (target == A[mid]) return true;
    if (target < A[mid]) {
        if (A[mid] == A[end] && A[mid] == A[start]) {
            return searchHelper(A, n, target, mid+1, end) || searchHelper(A, n, target, start,  mid-1);
        }else if (A[end] >= target && A[end] < A[mid]) {//非顺串，并且结尾大于target
            return searchHelper(A, n, target, mid+1, end);
        }else{
            return searchHelper(A, n, target, start,  mid-1);
        }
    }else{
        if (A[mid] == A[end] && A[mid] == A[start]) {
            return searchHelper(A, n, target, mid+1, end) || searchHelper(A, n, target, start,  mid-1);
        }else if (A[start] > A[mid] && A[start] <= target) {
            return searchHelper(A, n, target, start, mid-1);
        }else{
            return searchHelper(A, n, target, mid+1, end);
        }
    }
}

static bool search(int A[], int n, int target) {
    return searchHelper(A, n, target, 0, n-1);
}

void testSearchRotate2(){
    int a[] = {1,0,1,1,1};
    int target = 0;
    int n = 5;
    bool rest = search(a, n, target);
    printf("Finished %d\n",rest);
}