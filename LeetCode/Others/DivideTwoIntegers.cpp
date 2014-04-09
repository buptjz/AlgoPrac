//
//  DivideTwoIntegers.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-8.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://blog.csdn.net/doc_sgl/article/details/12841741

#include "leetcode_others.h"
#include <math.h>

//ref:http://blog.csdn.net/doc_sgl/article/details/12841741
int divide(int dividend, int divisor) {
    long long a = dividend;
    long long b = divisor;
    a = a > 0 ? a:-a;
    b = b > 0 ? b:-b;
    long long res = 0;
    while(a >= b)
    {
        long long c = b;
        for(int i = 0; a >= c; i++, c <<=1)
        {
            a -= c;
            res += 1<<i;
        }
    }
    return int(((dividend ^ divisor) >> 31) ? -res: res);
}

int divide2(int dividend, int divisor) {
    if (dividend == 0 || divisor == 0) return 0;
    long long _dividend = dividend,_divisor = divisor;
    int sign;
    if (_dividend > 0) {
        if (_divisor > 0) {
            sign = 1;
        }else{
            sign = -1;
            _divisor = 0 - _divisor;
        }
    }else{
        _dividend = 0 - _dividend;
        if (_divisor > 0) {
            sign = -1;
        }else{
            _divisor = 0 - _divisor;
        }
    }
    int ret = 0;
    if (_divisor == 1) return (int)_dividend * sign;
    if (_divisor == 2) return (int)(_dividend >> 1) * sign;
    while (_dividend >= _divisor) {
        ret++;
        _dividend -= _divisor;
    }
    return ret * sign;
}

void testDivide(){
    int res = divide(20, 3);
    cout<<res<<endl;
    cout<<(2147483647>>1)<<endl;
    
}

