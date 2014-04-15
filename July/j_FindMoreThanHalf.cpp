//
//  j_FindMoreThanHalf.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-14.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://blog.csdn.net/v_july_v/article/details/6890054

/*
 找到数组中出现一般次数以上的数
 */
#include "JulyHeaders.h"

//使用俩数不同退隐法
int findMoreThanHalf(int *a,int n){
    int times = 0;
    int current;
    for (int i = 0; i < n; i++) {
        if (times == 0) {
            times++;
            current = a[i];
        }else{
            if (current == a[i]) times++;
            else times--;
        }
    }
    return current;
}
static void swap(int *a,int index1,int index2){
    int temp = a[index1];
    a[index1] = a[index2];
    a[index2] = temp;
}
//使用快排思想
int findMoreThanHalfHelper(int *a,int start,int end,int target_index){
    if (start >= end) return a[start];
    int last = start;
    for (int i = start+1; i <= end; i++)
        if (a[i] < a[start])
            swap(a,++last,i);
    if (last == target_index){
        return a[start];
    }else{
        swap(a, start, last);
        if(target_index > last) return findMoreThanHalfHelper(a, last + 1, end,target_index);
        else return findMoreThanHalfHelper(a, start, last - 1,target_index);
    }
}

int findMoreThanHalf2(int *a,int n){
    return findMoreThanHalfHelper(a,0,n-1,n/2);
}

void testFindMoreThanHalf(){
    int a[] = {1,2,5,3,1,1,1};
    int n = 7;
    int res = findMoreThanHalf2(a, n);
    printf("%d\n",res);
}