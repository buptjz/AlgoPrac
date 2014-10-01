//
//  PerfectShuffle.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-1.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  完美洗牌问题

//http://www.cnblogs.com/v-July-v/p/3320870.html
//欢欢 雅虎面试题

#include "others.h"

//虽然能够直接写出每个位置应该交换去的位置，但是下面这个写法仍然不行，因为无法知道停止的条件。
void perfectShuffle(int A[],int n){
    int curIndex = 1;
    int shuffleTimes = 2 * n - 1;
    int lastVal= -1;
    while (shuffleTimes-- > 0) {
        int tmp = lastVal;
        lastVal = A[curIndex];
        A[curIndex] = tmp;
        if (curIndex < n) curIndex = curIndex * 2;
        else curIndex = (curIndex - n) * 2 + 1;
    }
}

void testPerfectShuffle(){
    int A[] = {1,2,3,4,5,6,7,8};
    perfectShuffle(A, 4);
    cout << "yes" <<endl;
}