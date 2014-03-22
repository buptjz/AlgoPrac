//
//  UniquePaths.cpp
//  Algorithms
//
//  Created by WangJZ on 14-3-22.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

int uniquePaths(int m, int n) {
    int grid[101][101];
    for(int i = 0;i < m; i++){
        grid[i][0] = 1;
    }
    for(int j = 0;j < n; j++){
        grid[0][j] = 1;
    }
    for(int i = 1;i < m; i++){
        for(int j = 1;j < n; j++){
            grid[i][j] = grid[i-1][j] + grid[i][j-1];
        }
    }
    return grid[m-1][n-1];
}