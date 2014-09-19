//
//  ReverseInteger.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-19.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_bit.h"

int reverse(int x) {
    int reverse = 0;
    int sign = (x >= 0) ? 1 : -1;
    x = (x >= 0)? x : -x;
    while (x != 0) {
        int digit = x % 10;
        x = x / 10;
        reverse = reverse * 10 + digit;
    }
    return reverse * sign;
}

void testReverse(){
    int x = 2;
    cout<< reverse(x) << endl;
}