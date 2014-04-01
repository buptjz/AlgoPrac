//
//  RemoveDuplicatesfromSortedArrayII.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-1.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

#include "leetcode_others.h"

static int removeDuplicates(int A[], int n) {
    if (n == 0) return 0;
    int last = A[0];//记录上一个数
    int place = 1;//目前放置的位置
    int cur;//当前的坐标
    bool doubled = false;//当前出现的次数
    for (cur = 1; cur < n;  cur++) {
        if (A[cur] == last) {
            if (!doubled) {//之前没有出现重复
                A[place++] = A[cur];
                last = A[cur];
                doubled = true;
            }else{
                continue;
            }
        }else{//不相等
            A[place++] = A[cur];
            last = A[cur];
            doubled = false;
        }
    }
    return place;
}

void testRemoveDuplicates2(){
    int A[] = {1,1,1,2,2,3,3,3,4};
    int res = removeDuplicates(A, 9);
    printf("Finished %d\n",res);
}

