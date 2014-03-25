//
//  QuickSort.cpp
//  Algorithms
//
//  Created by WangJZ on 14-3-24.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "other_sort.h"

int choosePivot(int a[],int left,int right){
    int mid = left + ((right - left) >> 2);
    if ((a[left] - a[mid]) * (a[mid] - a[right]) > 0) {
        return mid;
    }else if((a[mid] - a[left]) * (a[left] - a[right]) > 0){
        return left;
    }else{
        return right;
    }
}

void swap(int x[],int index1,int index2){
    int temp = x[index2];
    x[index2] = x[index1];
    x[index1] = temp;
}

void quicksort(int x[],int left, int right)
{
    if (left >= right) return;
    //swap(x,left,choosePivot(x,left, right));//如果这句话不执行,默认选择了第一个作为pivot
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
void testChoosePivot(){
    int a[] = {1,2,3,4,8,6,5};
    int c = choosePivot(a, 0, 6);
    printf("%d",c);
}

