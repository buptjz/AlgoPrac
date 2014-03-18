//
//  Triangle.cpp
//  LeetCode
//
//  Created by WangJZ on 14-3-13.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/triangle/

/*
 选择切入的角度很重要！
 从下向上依次查找每一行
 */

#include "Triangle.h"

#include <vector>
using namespace std;

int minimumTotal(vector<vector<int> > &triangle) {
    int length = (int)triangle.size();
    if (length == 0) {
        return 0;
    }
    if (length == 1) {
        return triangle[0][0];
    }
    
    vector<int> tempVec = triangle[length - 1];
    for (int i = length - 2; i >= 0 ; i--) {//从倒数第二行开始，依次处理每一行
        for (int j = 0; j < i+1; j++) {//该行有i+1个元素
            tempVec[j] = triangle[i][j]+min(tempVec[j],tempVec[j+1]);
        }
    }
    return tempVec[0];
}


void testMinimumTotal(){
    vector<int > a0 = {0};
    vector<int > a1 = {3,4};
    vector<int > a2 = {6,5,7};
    vector<int > a3 = {4,1,8,3};
    vector<vector<int>> aa;
    aa.push_back(a0);
    aa.push_back(a1);
    aa.push_back(a2);
    aa.push_back(a3);
    int res = minimumTotal(aa);
    printf("%d",res);
}
