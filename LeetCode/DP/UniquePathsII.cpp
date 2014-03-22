//
//  UniquePathsII.cpp
//  Algorithms
//
//  Created by WangJZ on 14-3-22.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_dp.h"

int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    int m = (int)obstacleGrid.size();
    int n = (int)obstacleGrid[0].size();
    int grid[101][101];
    if(obstacleGrid[0][0] == 1) return 0;
    grid[0][0] = 1;
    for(int i = 1; i < m; i++){
        if(obstacleGrid[i][0] == 1){
            grid[i][0] = 0;
        }else{
            grid[i][0] = grid[i-1][0];
        }
    }
    
    for(int j = 1; j < n; j++){
        if(obstacleGrid[0][j] == 1){
            grid[0][j] = 0;
        }else{
            grid[0][j] = grid[0][j-1];
        }
    }
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(obstacleGrid[i][j] == 1){
                grid[i][j] = 0;
            }else{
                grid[i][j] = grid[i-1][j] + grid[i][j-1];
            }
        }
    }
    return grid[m-1][n-1];
}