//
//  QuickSort.cpp
//  Algorithms
//
//  Created by WangJZ on 14-3-24.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "other_sort.h"
void swap(int x[],int index1,int index2){
    int temp = x[index2];
    x[index2] = x[index1];
    x[index1] = temp;
}

void quicksort(int x[],int left, int right)
{
    if (left >= right) return;
    //swap(x,left,choosePivot(left, right));//如果这句话不执行,默认选择了第一个作为pivot
    int last = left;
    for (int i = left+1; i <= right; i++)
        if (x[i] < x[left])
            swap(x,++last, i);
    swap(x,left, last);
    quicksort(x,left, last-1);
    quicksort(x,last+1, right);
}

void testQuickSort(){
    int a[] = {9,0,3,37,8,100,8,4,6,245,8976,324,1,3,3,3,2,6,8,29};
    quicksort(a, 0, sizeof(a)/sizeof(int) - 1);
    printf("Finished\n");
}