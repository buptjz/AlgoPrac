//
//  SingleNumberIII.cpp
//  LeetCode
//
//  Created by WangJZ on 14-3-12.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_tree.h"

int singleNumberIII(int A[], int n) {
    int final = 0;
    for(int i = 0;i < 32; i++){
        int total = 0;
        for(int j = 0;j < n; j++){
            total += (A[j] >> i) & 1;
        }
        final += ((total % 4) / 2) << i;
    }
    return final;
}

void testSingleNumberIII(){
    int A[] = {3,4,4,4,4,3,3,3,2,2};
    int n = 10;
    int res = singleNumberIII(A, n);
    printf("%d",res);
}