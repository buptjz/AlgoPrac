//
//  Searcha2DMatrix.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-1.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_search.h"

bool searchMatrix(vector<vector<int> > &matrix, int target) {
    int row_len = (int)matrix.size();
    int col_len = (int)matrix[0].size();
    
    int row = 0;
    int col = col_len - 1;
    while (row < row_len && col >= 0) {
        if (matrix[row][col] == target) {
            return true;
        }else if(matrix[row][col] < target){
            row++;
        }else{
            col--;
        }
    }
    return false;
}
