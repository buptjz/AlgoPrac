//
//  Pow(x, n).cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-6.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_others.h"

static double helper(double x,int n){
    if (n == 1) return x;
    if (n == 2) return x * x;
    
    double tmp = helper(x, n>>1);
    if (n % 2 == 0) {
        return tmp * tmp;
    }else{
        return tmp * tmp * x;
    }
}

double pow(double x, int n) {
    //那么问题来了，到底小到多少才算小呢？
    if ((x - 1) * (x - 1) < 0.000000000001) return 1;
    if ((x + 1) * (x + 1) < 0.000000000001) {
        if (n % 2 == 1) return -1.0;
        else return 1.0;
    }
    if (n == 0) return 1.0;
    if (n < 0) return 1.0 / helper(x, -n);
    else return helper(x,n);
}