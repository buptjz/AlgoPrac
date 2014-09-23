//
//  InterleavingString.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-23.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_tree.h"

bool isInterleave(string s1, string s2, string s3) {
    int s2_len = (int)s2.size();
    int s1_len = (int)s1.size();
    
    if (s1_len == 0 && s2_len == 0)
        if (s3.length() == 0) return true;
    
    if (s3.length() != s1_len + s2_len) return false;
    if (s1_len == 0){
        if (s2 == s3) return true;
        else return false;
    }
    if (s2_len == 0) {
        if (s1 == s3) return true;
        else return false;
    }
    
    vector<vector<bool>> state;
    for (int i = 0; i <= s2_len ; i++) {
        vector<bool> row(s1_len + 1,false);
        state.push_back(row);
    }
    
    for (int j = 1; j <= s1_len; j++) {
        if (s1[j - 1] != s3[j - 1]) break;
        state[0][j] = true;
    }
    
    for (int i = 1; i <= s2_len; i++) {
        if (s2[i - 1] != s3[i - 1]) break;
        state[i][0] = true;
    }
    
    for (int i = 1; i <= s2_len; i++) {
        for (int j = 1; j <= s1_len; j++) {
            if (s3[i + j - 1] == s1[j - 1] && s3[i + j - 1] == s2[i - 1]){//两个都匹配
                state[i][j] = state[i][j-1] || state[i-1][j];;
            }else if(s3[i + j - 1] == s1[j - 1] ){//s1匹配
                state[i][j] = state[i][j-1];
            }else if(s3[i + j - 1] == s2[i - 1]){//s2匹配
                state[i][j] = state[i-1][j];
            }else{
                state[i][j] = false;
            }
        }
    }
    
    return state[s2_len][s1_len];
}
