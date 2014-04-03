//
//  FirstMissingPositive.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-3.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/first-missing-positive/

/*
 解法改动了数组
 并且对constant space. 不是很理解，
 貌似网上有更多的解法，需要进一步探索
 */
#include "leetcode_sort.h"

int firstMissingPositive(int A[], int n) {
    //Set the smallest positive to be the first element of the array
    int index = 0;
    while (index < n) {
        if (A[index] <= 0 || A[index] >  n){
            //case 1：out of scope of successive n numbers (1 ~ n)
            index++;
        }else if(A[index] == 1 + index){
            //case 2: number of this element happens to be the proper one
            index++;
        }else if(A[index] != 1 + index){
            //case 3: wrong number ,we should put it to the right position
            if (A[A[index] - 1] == A[index]) {//case 3.1 new position has proper element
                index++;
            }else{//case 3.2 new position has to be set
                int temp = A[A[index] - 1];
                A[A[index] - 1] = A[index];
                A[index] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
        if (A[i] != 1+i)
            return 1+i;
    return 1+n;//edge case: all numbers are positive and successive
}

void testFirstMissingPositive(){
    int A[] = {0,1,1};
    int res = firstMissingPositive(A, 3);
    printf("%d\n",res);
}




