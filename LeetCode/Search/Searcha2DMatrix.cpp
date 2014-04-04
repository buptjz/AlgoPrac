//
//  Searcha2DMatrix.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-4.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/search-a-2d-matrix/

#include "leetcode_others.h"

bool searchMatrix(vector<vector<int> > &matrix, int target) {
    if(matrix.size() == 0) return false;
    int height = (int)matrix.size();
    int width = (int)matrix[0].size();
    int x = width -1;
    int y = 0;
    while(x >=0 && y < height){
        if(matrix[y][x] == target) return true;
        if(matrix[y][x] > target) x--;
        else y++;
    }
    return false;
}
