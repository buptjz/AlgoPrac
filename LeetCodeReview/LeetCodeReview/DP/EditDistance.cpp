//
//  EditDistance.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-2.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_dp.h"

int minDistance(string word1, string word2) {
    if (word1.empty()) return (int)word2.length();
    if (word2.empty()) return (int)word1.length();
    
    int row = (int)word1.length() + 1;
    int col = (int)word2.length() + 1;
    
    vector<vector<int>> state;
    
    vector<int> firstRow;
    for (int j = 0; j < col; j++) {
        firstRow.push_back(j);
    }
    state.push_back(firstRow);
    for (int i = 1; i < row; i++) {
        vector<int> tmp(col,0);
        tmp[0] = i;
        state.push_back(tmp);
    }
    
    for (int i = 1; i < row; i++) {
        for (int j = 1; j < col; j++) {
            state[i][j] = min(state[i-1][j], state[i][j-1]) + 1;
            if (word1[i-1] == word2[j-1]) {
                state[i][j] = min(state[i][j],state[i-1][j-1]);
            }else{
                state[i][j] = min(state[i][j],state[i-1][j-1] + 1) ;
            }
        }
    }
    return state[row-1][col-1];
}

void testMinDistance(){
    string word1 = "cbbc";
    string word2 = "abbac";
    int ans = minDistance(word1, word2);
    cout<<ans<<endl;
}