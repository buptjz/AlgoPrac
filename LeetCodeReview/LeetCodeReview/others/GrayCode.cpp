//
//  GrayCode.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-24.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_others.h"


vector<int> grayCode(int n) {
    int len = 1 << n;
    vector<int> ret(len,0);
    for (int i = 1; i < len; i++)
        ret[i] = i ^ (i >> 1);
    
    return ret;
}