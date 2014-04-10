//
//  RemoveDuplicatesfromSortedArray.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-1.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/remove-duplicates-from-sorted-array/

#include "leetcode_others.h"


int removeDuplicates(int A[], int n) {
    if (n == 0) return 0;
    int last = A[0];//记录上一个数
    int place = 1;//目前放置的位置
    int cur;//当前的坐标
    for (cur = 1; cur < n;  cur++) {
        if (A[cur] == last) {//相等，do nothing
            continue;
        }else{//不相等
            A[place++] = A[cur];
            last = A[cur];
        }
    }
    return place;
}

void testRemoveDuplicates(){
    int A[] = {0};
    int res = removeDuplicates(A, 1);
    printf("Finished %d\n",res);
}
