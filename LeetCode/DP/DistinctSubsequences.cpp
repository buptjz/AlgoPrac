//
//  DistinctSubsequences.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-7.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_others.h"

/*
 比较不好想的DP问题
 http://zhongyinzhang.wordpress.com/2014/03/05/distinct-subsequences/
 http://stackoverflow.com/questions/20459262/distinct-subsequences-dp-explanation
 */

int numDistinct(string S, string T) {
    int rows = (int)S.size();
    int cols = (int)T.size();
    
    //Initialize
    vector<vector<int> >dp(rows+1,vector<int>(cols+1,0));
    for (int i = 0; i < rows + 1; i++) {
        dp[i][0] = 1;
    }
    
    //Dynamic programming
    for (int i = 1; i < rows + 1; i++) {
        for (int j = 1; j < cols + 1; j++) {
            dp[i][j] = dp[i-1][j];
            if (S[i-1] == T[j-1])
                dp[i][j] += dp[i-1][j-1];
        }
    }
    return dp[rows][cols];
}

void testNumDistinct(){
    int res = numDistinct("rabbbit", "rabbit");
    cout<<res<<endl;
}