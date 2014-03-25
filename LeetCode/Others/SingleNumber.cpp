//
//  SingleNumber.cpp
//  LeetCode
//
//  Created by WangJZ on 14-2-24.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include <stdio.h>
int singleNumber(int A[], int n) {
    int final = 0;
    for (int i = 0; i < 32; i++) {//32位数，遍历每一位，找到该位置上得重复的数
        int total = 0;
        for (int j = 0; j < n; j++) {
            total += (A[j] >> i) & 1;
        }
        final += total %  2 << i;
    }
    return final;
}

void testSingleNumber(){
    int a[] = {1,1,2,2,3};
    int x = singleNumber(a,5);
    printf("Finished %d\n",x);
}