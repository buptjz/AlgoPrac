//
//  SqrtX.cpp
//  LeetCode
//
//  Created by WangJZ on 14-2-26.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

/*
 这个问题的核心是设置搜索上界，应该是2*16,如果大于搜索上届，就是上届，否则的话使用二分查找，也可以使用先将32位的整数转换成64位类型再查找
 */
#include "SqrtX.h"

int sqrt(int x) {
    int LARGEST = 46340;
    int start = 0;
    int end = x;
    if (x > LARGEST) {
        end  = LARGEST;
    }
    if (x >= LARGEST *LARGEST){
        return LARGEST;
    }
    int mid;
    if (x < 0) return -1;
    if (x == 0) return 0;
    while (start <= end) {
        mid = ((end - start) >> 1) + start;
        if (x < mid * mid) {
            end = mid - 1;
        }else{
            if (x == mid * mid) {
                return mid;
            }
            if (x > mid * mid && x < (mid+1)*(mid+1)) {
                return mid;
            }else{
                start = mid + 1;
            }
        }
    }
    return -1;
}

void testSqrtX(){
    int a = sqrt(0);
    int b = sqrt(1);
    int c = sqrt(2);
    int d = sqrt(100);
    int e = sqrt(2147483647);
    printf("Finished");
}