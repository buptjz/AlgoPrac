//
//  EditDistance.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-6.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/edit-distance/

/*
 难度太大，非常经典的题目参考了下面两篇文章
 http://blog.csdn.net/huaweidong2011/article/details/7727482
 https://www.stanford.edu/class/cs124/lec/med.pdf
 */

#include "leetcode_dp.h"

int minDistance(string word1, string word2) {
    //Initializition
    int l1 = (int)word1.size();
    int l2 = (int)word2.size();
    vector<vector<int> >dp(l1+1,vector<int>(l2+1,0));
    dp[0][0] = 0;
    for (int i = 1; i < l1+1; i++)
        dp[i][0] = i;
    for (int i = 1; i < l2+1; i++)
        dp[0][i] = i;
    
    //start dynamic programming
    for (int i = 1; i < l1 + 1; i++) {
        for (int j = 1; j < l2 + 1; j++) {
            int replace = word1[i-1] == word2[j-1] ? 0 : 1;
            dp[i][j] = min(min(dp[i-1][j], dp[i][j-1])+1,replace+dp[i-1][j-1]);
        }
    }
    return dp[l1][l2];
}

void testMinDistance(){
    int res = minDistance("", "execution");
    cout<<res<<endl;
}
