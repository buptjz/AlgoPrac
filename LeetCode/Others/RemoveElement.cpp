//
//  RemoveElement.cpp
//  Algorithms
//
//  Created by WangJZ on 14-3-25.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_others.h"

int removeElement(int A[], int n, int elem) {
    int cur = 0,last = n - 1;
    while (cur <= last) {
        if (A[cur] != elem) {
            cur++;
        }else{
            n--;
            A[cur] = A[last];
            last--;
        }
    }
    return n;
}

void testRemoveElement(){
    int A[] = {4,1,3,4};
    int n = 4;
    int elem = 4;
    int res = removeElement(A,n,elem);
    printf("Finished%d\n",res);
}