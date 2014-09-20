//
//  DistinctSubsequences.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-20.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  https://oj.leetcode.com/problems/distinct-subsequences/

//S = "rabbbit", T = "rabbit"


#include "leetcode_dp.h"

int numDistinct(string S, string T) {
    int T_len = (int)T.length();
    int S_len = (int)S.length();

    
    //init state matrix
    vector<vector<int>> state;
    state.push_back(vector<int>(S_len + 1,1));
    for (int i = 0; i < T_len; i++)
        state.push_back(vector<int>(S_len + 1,0));
    
    //start dp
    for (int row = 1; row <= T_len; row++) {
        for (int col = row; col <= S_len; col++) {
            if (T[row - 1] == S[col - 1])
                state[row][col] = state[row][col - 1] + state[row - 1][col - 1];
            else
                state[row][col] = state[row][col - 1];
        }
    }
    return state[T_len][S_len];
}

