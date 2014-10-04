//
//  UniquePaths.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-4.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_dp.h"

int uniquePaths(int m, int n) {
    if (m == 0 && n == 0) return 1;
    if (m == 0 || n == 0) return 1;
    
    vector<vector<int>> state;
    for (int i = 0; i < m; i++) {
        vector<int> row(n,0);
        row[0] = 1;
        state.push_back(row);
    }
    
    for (int j = 0; j < n; j++)
        state[0][j] = 1;
    
    for (int i = 1; i < m; i++)
        for (int j = 1 ; j < n; j++)
            state[i][j] = state[i-1][j] + state[i][j-1];
    
    return state[m-1][n-1];
}
