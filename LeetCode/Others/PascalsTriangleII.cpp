//
//  PascalsTriangleII.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-2.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/pascals-triangle-ii/

#include "leetcode_others.h"
/*
    没有找到直接计算的通项，还是自低向上的动态规划法，在I的基础上简单改写的
 */
vector<int> getRow(int rowIndex) {
    vector<int> lastVec = {1};
    for (int i = 0; i < rowIndex; i++) {//第i个vec，长度是i+1
        vector<int> cur;
        cur.push_back(1);
        for (int j = 1; j <= i; j++) {
            cur.push_back(lastVec[j-1]+lastVec[j]);
        }
        cur.push_back(1);
        lastVec = cur;
    }
    return lastVec;
}