//
//  MaximalRectangle.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-25.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_others.h"

int maximalRectangle(vector<vector<char> > &matrix) {
    if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
    size_t row_len = matrix.size();
    size_t col_len = matrix[0].size();
    
    int retValue = 0;
    vector<int> rowAccum(col_len,0);
    for (size_t i = 0; i < row_len; i++) {
        for (size_t j = 0; j < col_len; j++) {
            if (matrix[i][j] == '0') rowAccum[j]  = 0;
            else rowAccum[j] += 1;
        }
        
        int curMax = 0;
        for (size_t j = 0; j < col_len; j++) {
            if (rowAccum[j] == 0) {
                retValue = max(retValue,curMax);
                curMax = 0;
            }else{
                curMax += rowAccum[j];
            }
        }
    }
    return retValue;
}