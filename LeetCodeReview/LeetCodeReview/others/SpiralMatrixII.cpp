//
//  SpiralMatrixII.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-5.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_others.h"

vector<vector<int> > generateMatrix(int n) {
    vector<vector<int>> matrix;
    if (n == 0) return matrix;
    
    for (int i =0; i < n; i++) {
        vector<int > row(n,0);
        matrix.push_back(row);
    }
    
    int row = n;
    int col = n;
    int cycle = row / 2;
    
    int accum = 1;
    for (int c = 0; c < cycle; c++) {
        //from left to right
        for (int j = c; j <= col - c -2; j++) {
            int i = c;
            matrix[i][j] = accum++;
        }
        //from top to bottom
        for (int i = c; i <= row-c-2; i++) {
            int j = col - c - 1;
            matrix[i][j] = accum++;
        }
        //from right to left
        for (int j = col - c - 1; j >= c+1; j--) {
            int i = row - c - 1;
            matrix[i][j] = accum++;
        }
        //from bottom to up
        for (int i = row -c -1; i >=c+1; i--) {
            int j = c;
            matrix[i][j] = accum++;
        }
    }

    if (n % 2 == 1)
        for (int j = cycle; j <= col - cycle -1; j++) {
            int i = cycle;
            matrix[i][j] = accum++;
        }
    
    return matrix;
}
