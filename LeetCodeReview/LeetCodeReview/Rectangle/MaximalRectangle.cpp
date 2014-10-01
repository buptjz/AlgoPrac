//
//  MaximalRectangle.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-1.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
// https://oj.leetcode.com/problems/maximal-rectangle/

#include "leetcode_rectangle.h"

static int largestRectangleArea(vector<int> &height) {
    int len = (int)height.size();
    if (len == 0) return 0;
    
    int retMax = 0;
    stack<int> indexST;
    for (int i = 0; i < height.size(); i++) {
        if (indexST.empty() || height[indexST.top()] < height[i])
            ;
        else{
            while (!indexST.empty() && height[i] <= height[indexST.top()]) {
                int curIndex = indexST.top();
                indexST.pop();
                int preIndex = -1;
                if (!indexST.empty()) preIndex = indexST.top();
                retMax = max(retMax,height[curIndex] * (i - 1 - preIndex));
            }
            
        }
        indexST.push(i);
    }
    int lastIndex = (int)height.size() - 1;
    
    while (!indexST.empty()) {
        int curIndex = indexST.top();
        indexST.pop();
        int preIndex = -1;
        if (!indexST.empty()) preIndex = indexST.top();
        retMax = max(retMax,height[curIndex] * (lastIndex - preIndex));
    }
    
    return retMax;
}

int maximalRectangle(vector<vector<char> > &matrix) {
    int row = (int)matrix.size();
    if (row == 0) return 0;
    int col = (int)matrix[0].size();
    vector<vector<int>> state;
    
    for (int i = 0; i < row; i++) {
        vector<int> colVec(col,0);
        state.push_back(colVec);
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] == '0') state[i][j] = 0;
            else if(i == 0) state[i][j] = 1;
            else state[i][j] = state[i-1][j] + 1;
        }
    }
    
    int maxVal = 0;
    for (int i = 0; i < row; i++) {
        int tmpVal = largestRectangleArea(state[i]);
        maxVal = max(maxVal,tmpVal);
    }
    
    return maxVal;
}


void testMaximalRectangle(){
    vector<vector<char>> mat;
    vector<char> a = {'0','1'};
    mat.push_back(a);
    cout<< maximalRectangle(mat)<<endl;
}






