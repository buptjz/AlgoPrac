//
//  RotateImage.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-7.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_others.h"

void rotate(vector<vector<int> > &matrix) {
    int n = (int)matrix.size();
    if (n == 0 || n == 1) return;
    for (int c = 0; c < n / 2; c++) {
        int row = c;
        for (int col = row; col <= n - c - 2; col++) {
            int tmp = matrix[row][col];
            matrix[row][col] = matrix[n-1-col][row];
            matrix[n-1-col][row] = matrix[n-1-row][n-1-col];
            matrix[n-1-row][n-1-col] = matrix[col][n-1-row];
            matrix[col][n-1-row] = tmp;
        }
    }
}
