//
//  UniquePathsII.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-4.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_dp.h"

int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    int row = (int)obstacleGrid.size();
    if (row == 0) return 0;
    int col = (int)obstacleGrid[0].size();
    
    vector<vector<int>> state;
    for (int i = 0; i < row; i++) {
        vector<int> row_vec(col,0);
        state.push_back(row_vec);
    }
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (obstacleGrid[i][j] == 1) {
                state[i][j] = 0;
            }else{
                if (i == 0 && j == 0) {
                    state[i][j] = 1;
                }else if(i == 0){
                    state[i][j] = state[i][j-1];
                }else if(j == 0){
                    state[i][j] = state[i-1][j];
                }else{
                    state[i][j] = state[i-1][j] + state[i][j-1];
                }
            }
        }
    }
    return state[row-1][col-1];
}
