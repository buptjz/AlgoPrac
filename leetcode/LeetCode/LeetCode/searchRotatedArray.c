//
//  searchRotatedArray.c
//  LeetCode
//
//  Created by WangJZ on 14-1-12.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include <stdio.h>

int searchhelperatleat(int *A,int n,int target,int atleast){
    if (n<1) return 0;
    int mid = n >> 1;
    if (A[mid] == target) return 1;
    if (A[mid] > target) {//中间的值比要寻找的大
        //return searchhelpernormal(A,mid,target);
        return searchhelperatleat(A,mid,target,atleast);
    }else{
        if (A[mid] == atleast) {
            return searchhelperatleat(A+mid+1,n-mid-1,target,atleast) || searchhelperatleat(A,mid,target,atleast);
        }
        else if (A[mid] > atleast) {
            return searchhelperatleat(A+mid+1,n-mid-1,target,atleast);
        }else{
            return searchhelperatleat(A,mid,target,atleast);
        }
        
    }
}

int searchhelperatmost(int *A,int n,int target,int atmost){
    if (n<1) return 0;
    int mid = n >> 1;
    if (A[mid] == target) return 1;
    if (A[mid] > target) {//中间的值比要寻找的大
        if (A[mid] == atmost) {//数组中有重复的情况，不能删掉任何一个分支
            return searchhelperatmost(A,mid,target,atmost)|| searchhelperatmost(A+mid+1,n-mid-1,target,atmost);
        }
        if (A[mid] < atmost) {
            return searchhelperatmost(A,mid,target,atmost);
        }else{
            return searchhelperatmost(A+mid+1,n-mid-1,target,atmost);
        }
    }else{
        //        return searchhelpernormal(A+mid+1,n-mid-1,target);
        return searchhelperatleat(A+mid+1,n-mid-1,target,atmost);
    }
}
int search(int A[], int n, int target) {
    if(A == NULL || n <1) return 0;
    int mid = n >> 1;
    if(A[mid] == target) return 1;
    if (A[mid] > target) {
        return searchhelperatmost(A+mid+1,n-mid-1,target,A[mid]) || search(A,mid,target);
    }else{
        return searchhelperatleat(A,mid,target,A[mid]) || search(A+mid+1,n-mid-1,target);
    }
}


