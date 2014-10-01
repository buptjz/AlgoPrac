//
//  SortColors.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-1.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_others.h"


void sortColors(int A[], int n) {
    int left = 0;
    int right = n - 1;
    int cur = 0;
    while (cur <= right) {
        if (A[cur] == 0) {
            if (cur == left) {
                cur++;
                continue;
            }
            int tmp = A[cur];
            A[cur] = A[left];
            A[left++] = tmp;
        }else if(A[cur] == 2){
            int tmp = A[cur];
            A[cur] = A[right];
            A[right--] = tmp;
        }else{
            cur++;
        }
    }
}

void testSortColors(){
    int A[] = {2,1};
    sortColors(A, 2);
    cout<<"yes"<<endl;
}

