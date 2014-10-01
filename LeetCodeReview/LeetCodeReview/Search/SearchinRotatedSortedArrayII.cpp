//
//  SearchinRotatedSortedArrayII.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-1.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_search.h"

static bool helper(int A[],int start,int end,int target){
    if (start > end) return false;
    int mid = start + ((end - start) >> 1);
    if (target == A[mid]) return true;
    
    if (A[end] > A[mid]) {//右边是顺序的
        if (target <= A[end] && target > A[mid])
            return helper(A, mid + 1, end, target);
        else
            return helper(A, start, mid - 1, target);
    }else if(A[start] < A[mid]){
        if (target < A[mid] && A[start] <= target)
            return helper(A, start, mid - 1, target);
        else
            return helper(A, mid + 1, end, target);
    }else{
        return helper(A, start , mid-1, target) || helper(A, mid+1, end, target);
    }
}

bool search(int A[], int n, int target) {
    return helper(A, 0, n - 1, target);
}
