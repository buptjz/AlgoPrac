//
//  PascalsTriangle.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-2.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/pascals-triangle/

#include "leetcode_others.h"

//
static vector<vector<int> > generate(int numRows) {
    vector<vector<int> > retVec;
    if (numRows == 0) return retVec;//base case
    vector<int> lastVec = {1};
    retVec.push_back(lastVec);
    for (int i = 1; i < numRows; i++) {//第i个vec，长度是i+1
        vector<int> cur;
        cur.push_back(1);
        for (int j = 1; j < i; j++) {
            cur.push_back(lastVec[j-1]+lastVec[j]);
        }
        cur.push_back(1);
        retVec.push_back(cur);
        lastVec = cur;
    }
    return retVec;
}

void testGeneratePTri(){
    vector<vector<int> > res = generate(5);
    printf("Finsihed\n");
}