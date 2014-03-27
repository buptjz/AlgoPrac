//
//  SetMatrixZeroes.cpp
//  Algorithms
//
//  Created by WangJZ on 14-3-27.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_others.h"

void setZeroes(vector<vector<int> > &matrix) {
    if (matrix.size() == 0) return;
    int column = (int)matrix[0].size();
    int row = (int)matrix.size();
    vector<bool> col_vec(column,false);
    vector<bool> row_vec(row,false);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (matrix[i][j] == 0) {
                col_vec[j] = true;
                row_vec[i] = true;
            }
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (row_vec[i] || col_vec[j]) {
                matrix[i][j] = 0;
            }
        }
    }
}