//
//  SetMatrixZeroes.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-2.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  https://oj.leetcode.com/problems/set-matrix-zeroes/

//比想象中有难度

#include "leetcode_others.h"

void setZeroes(vector<vector<int> > &matrix) {
    const int ROW = (int) matrix.size();
    const int COL = (int) matrix[0].size();
    
    bool row00 = false,col00 = false;
    for (int i = 0; i < ROW; i++) {
        if (matrix[i][0] == 0) {
            col00 = true;
        }
    }
    
    for (int j = 0; j < COL; j++) {
        if (matrix[0][j] == 0) {
            row00 = true;
        }
    }
    
    
    for (int i = 1; i < ROW; i++) {
        for (int j = 1; j < COL; j++) {
            if (matrix[i][j] == 0) {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }
    
    for (int i = 1; i < ROW; i++)
        for (int j = 1; j < COL; j++)
            if (matrix[i][0]== 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
    
    if (row00) fill(begin(matrix[0]),end(matrix[0]),0);
    if (col00)
        for (int i = 0; i < ROW; i++)
            matrix[i][0] = 0;
}


