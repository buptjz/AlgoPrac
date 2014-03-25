//
//  SearchforaRange.cpp
//  LeetCode
//
//  Created by WangJZ on 14-2-26.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/search-for-a-range/

/*
 思路：我们要查找的是starting 和ending point,考虑到starting的特点是：该位置的值比target小，而右边的数比target大，ending的特点与此相反，要找到具有这样特点的两个数，采用二分查找的思想就好了，分两次调用二分查找，写的时候注意边缘条件即可！
 */

#include "leetcode_others.h"

int searchRangeHelper(int A[],int n,int target,bool M){
    //binary search
    int left = 0;
    int right = n - 1;
    int mid;
    while (left <= right) {
        mid = (left + right) >> 1;
        if (M) {//looking for starting point
            if (A[0] == target) {//exceptional case
                return 0;
            }
            if (A[mid] < target) {
                if ((mid+1) < n && A[mid + 1] == target) {
                    return mid + 1;
                }else{
                    left = mid + 1;
                }
            }else{
                right = mid - 1;
            }
        }else{//looking for ending point
            if (A[n-1] == target) {//exceptional case
                return n-1;
            }
            if (A[mid] > target) {
                if ((mid -1) >=0  && A[mid-1] == target) {
                    return mid-1;
                }else{
                    right = mid - 1;
                }
            }else{
                left = mid + 1;
            }
        
        }
    }
    return -1;//没有找到，返回-1
}
vector<int> searchRange(int A[], int n, int target) {
    vector<int>res;
    int left = searchRangeHelper(A, n, target, true);
    int right = searchRangeHelper(A, n, target, false);
    if (left == -1 || right == -1) {
        res.push_back(-1);
        res.push_back(-1);
    }else{
        res.push_back(left);
        res.push_back(right);
    }
    return res;
}

void testSearchRange(){
    int A[] = {4,5,6,7,7,8};
    int n = 6;
    int target = 7;
    vector<int>res1 = searchRange(A, n, target);
    
    int A2[] = {4,4,4,4,5};
    int n2 = 5;
    int target2 = 4;
    vector<int>res2 = searchRange(A2, n2, target2);
    printf("Finisehd");
}
