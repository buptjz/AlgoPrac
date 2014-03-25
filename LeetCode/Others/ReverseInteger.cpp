//
//  ReverseInteger.cpp
//  Algorithms
//
//  Created by WangJZ on 14-3-25.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/reverse-integer/


static int reverse(int x) {
    int ret = 0;
    while(x != 0){
        ret = ret * 10 + x % 10;
        x /= 10;
    }
    return ret;
}