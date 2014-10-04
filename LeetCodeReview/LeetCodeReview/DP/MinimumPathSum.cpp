//
//  MinimumPathSum.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-4.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_dp.h"

int minPathSum(vector<vector<int> > &grid) {
    int row = (int) grid.size();
    if(row == 0) return 0;
    int col =(int) grid[0].size();
    
    vector<vector<int>> state;
    for (int i = 0; i < row; i++) {
        vector<int> row_vec(col,0);
        state.push_back(row_vec);
    }
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i == 0 && j == 0) {
                state[i][j] = grid[i][j];
            }else if(i == 0){
                state[i][j] = state[i][j-1] + grid[i][j];
            }else if(j == 0){
                state[i][j] = state[i-1][j] + grid[i][j];
            }else{
                state[i][j] = min(state[i-1][j],state[i][j-1]) + grid[i][j];
            }
        }
    }
    return state[row-1][col-1];
}