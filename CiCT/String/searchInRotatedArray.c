//
//  searchInRotatedArray.c
//  CiCT
//
//  CiCT 11.3
//  Given a sorted array of n integers that has been rotated an unknown number of times,
//  write code to find an element in the array.
//  You may assume that the array was originally sorted in increasing order.
//  和leetcode的http://oj.leetcode.com/problems/search-in-rotated-sorted-array-ii/这个题很相似


#include <stdio.h>
#include "arrayAndString.h"
//前提条件：一个rotate串，无论从哪一点分成两半，其中一半必然是排序好的。所以我们只要判断其中一边，如果是排序好的。
int searchInRotateArray(int *A,int start,int end,int target){
    if (A == NULL || start > end) return -1;//base case
    
    int mid = start + ((end - start) >> 1);
    if (A[mid] == target) return mid; //找到，立即返回
    
    if (A[mid] == A[start] && A[mid] == A[end]) {
        int result = searchInRotateArray(A, start, mid-1,target);
        if (result == -1) {
            //先在左边找，如果没找到，再去右边找，不能用||，因为这里return的是-1而不是0
            result = searchInRotateArray(A, mid+1, end,target);
        }
        return result;
    }else if(A[start] < A[mid]) {//左串排好序的
        if (target < A[mid] &&  target >= A[start]) {
            //x夹在左、中之间，那么右串都是在A[start]~A[mid]范围之外的，所以不用考虑
            return searchInRotateArray(A, start, mid-1,target);
        }else{
            return searchInRotateArray(A, mid+1, end,target);
        }
    }else if(A[start] > A[mid]){//右串排序了,很关键
        if (target <= A[end] &&  target > A[mid]) {
            //x夹在右、中之间，那么左串都是>A[end],<A[mid]的，所以不用考虑
            return searchInRotateArray(A, mid+1, end,target);
        }else{
            return searchInRotateArray(A, start, mid-1,target);
        }
    }else if(A[start] == A[mid]){
        //特殊条件：左串是重复的，而右串非重复，也就是A[start]和A[mid]中间所有的数都是重复的，那么只在右边找
        return searchInRotateArray(A, mid+1, end,target);
    }
    
    return -1;
}

void testSearchInRotateArray(){
    int a[5] = {3,4,5,1,2};
    int r1 = searchInRotateArray(a, 0, 4, 3);
    printf("Expected %d and get %d\n",1,r1);
    
    int b[10] = {1,1,1,1,1,1,0,1,1,1};
    int r2 = searchInRotateArray(b, 0, 9, 0);
    printf("Expected %d and get %d\n",6,r2);
}