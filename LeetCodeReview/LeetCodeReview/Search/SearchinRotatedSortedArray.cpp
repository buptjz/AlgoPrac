//
//  SearchinRotatedSortedArray.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-1.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_search.h"

int helper(int A[],int start,int end,int target){
    if (start > end) return -1;
    int mid = start + ((end - start) >> 1);
    
    if (A[mid] == target) return mid;
    if (A[end] > A[mid]) {//右侧是顺序的一边
        if (target <= A[end] && target > A[mid]) {
            return helper(A, mid + 1, end, target);
        }else{
            return helper(A, start, mid - 1, target);
        }
    }else{
        if (target >= A[start] && target < A[mid]) {
            return helper(A, start, mid - 1, target);
        }else{
            return helper(A, mid + 1, end, target);
        }
    }
}


int search(int A[], int n, int target) {
    return helper(A,0,n-1,target);
}