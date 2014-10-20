//
//  DivideTwoIntegers.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14/10/20.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

/*
 Divide two integers without using multiplication, division and mod operator.
 加减乘除 取模 位移
 基本操作，记得位移！
 */

#include "leetcode_others.h"

int divide(int dividend, int divisor) {
    long long a = dividend, b = divisor;
    if (b == 0) return 0;
    if (a == 0) return 0;
    bool sign = false;

    if ((a > 0 && b > 0) || (a < 0 && b < 0))
        sign = true;
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    long long sava_b = b;
    if (b == 1) {
        if (sign == false) return -a;
        else return a;
    }
    long long  res = 0,tmp;
    while (b <= a) {
        tmp = 1;
        while (b <= a) {
            tmp = tmp << 1;
            b = b << 1 ;
        }
        res += (tmp>>1);
        a -= (b>>1);
        b = sava_b;
    }
    if (sign == false) res = -res;
    return res;
}

void testDivide(){
    cout<< divide(-2147483648, 2)<<endl;
}