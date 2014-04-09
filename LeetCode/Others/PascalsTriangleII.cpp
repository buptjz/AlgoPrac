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
 2014.4.9日更新，只使用一个数组，滚动完成，从后向前，不会覆盖！最精简版本
杨辉三角的性质
http://www.cnblogs.com/shawnhue/p/leetcode_119.html
 */
vector<int> getRow(int rowIndex) {
    vector<int> ret(rowIndex+1,1);
    for (int i = 1; i <= rowIndex; i++)//第i个vec，长度是i-1
        for (int j = i - 1; j >= 1; j--)
            ret[j] = ret[j-1]+ret[j];
    return ret;
}