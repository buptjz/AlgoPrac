//
//  SortColors.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-3.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/sort-colors/
#include "leetcode_sort.h"
/*
 2014.4.10日更新
 http://blog.csdn.net/zxzxy1988/article/details/8596144
*/

void sortColors(int A[], int n) {
    int left = 0;
    int right = n - 1;
    int index = 0;
    while (index <= right) {
        if (A[index] == 0) {
            swap(A[index], A[left]);
            index++;
            left++;
        }else if(A[index] == 1){
            index++;
        }else{
            swap(A[index], A[right]);
            right--;
        }
    }
}

/*
 有点ugly
 */


void sortColors2(int A[], int n) {
    if (n == 0) return;
    int start = 0;
    int end = n - 1;
    while (start < n && A[start] == 0) start++;
    while (end >= 0 && A[end] == 2) end--;
    int cur = start,temp;
    
    while (cur <= end) {
        if (A[cur] == 0) {
            temp = A[start];
            A[start] = A[cur];
            A[cur] = temp;
            start++;
        }else if(A[cur] == 2){
            temp = A[end];
            A[end] = A[cur];
            A[cur] = temp;
            end--;
            if (A[start] == 0) {
                while (start < n && A[start] == 0) start++;
                cur = start;
            }
        }else{
            cur++;
        }
    }
}

void testSortCorlors(){
    int A[] = {2,0,0};
    sortColors(A, 3);
    int B[] = {2,2,1,1};
    sortColors(B, 4);
    printf("Finished\n");
}
