//
//  MinimumPathSum.cpp
//  LeetCode
//
//  Created by WangJZ on 3/6/14.
//  Copyright (c) 2014 WangJZ. All rights reserved.
//

#include "leetcode_others.h"

static int minPathSum(vector<vector<int> > &grid) {
    int a_length = (int)grid.size();
    int b_length = (int)grid[0].size();

    //初始化记录数组，记录数组（长+1）*（宽+1），从点（1，1）开始查找
    vector<vector<int>> record;
    for (int i = 0; i < a_length; i++) {
        vector<int> tmp;
        for (int j = 0; j < b_length; j++) {
            tmp.push_back(0);
        }
        record.push_back(tmp);
    }
    
    for (int i = 0; i < a_length; i++) {
        for (int j = 0 ; j < b_length ; j++) {
            if (i == 0 && j == 0) record[i][j] = grid[i][j];
            else if(i == 0) record[i][j] = grid[i][j] + record[i][j-1];
            else if(j == 0) record[i][j] = grid[i][j] + record[i-1][j];
            else record[i][j] = min(record[i-1][j], record[i][j-1]) + grid[i][j];
        }
    }
    return record[a_length-1][b_length-1];
}

void testMinPathSum(){
    vector<vector<int>> grid = {{1,2,3},{1,2,3},{1,2,3}};
    int res = minPathSum(grid);
    printf("%d\n",res);
}
