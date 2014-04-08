//
//  InterleavingString.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-7.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/interleaving-string/

#include "leetcode_string.h"

/*
 使用DP~发现其实不难，多个字符串匹配的问题经常使用DP
 */
bool isInterleave(string s1, string s2, string s3) {
    int rows = (int)s1.size();
    int cols = (int)s2.size();
    if (rows + cols != s3.size()) return false;
    vector<vector<bool> > dp(rows+1,vector<bool>(cols+1,false));
    dp[0][0] = true;
    for (int i = 0; i < rows + 1; i++) {
        for (int j = 0; j < cols + 1; j++) {
            if (i == 0 && j == 0) continue;//original point
            else if (i == 0) dp[i][j] = dp[i][j-1] && (s2[j-1] == s3[j+i-1]);//first row
            else if (j == 0) dp[i][j] = dp[i-1][j] && (s1[i-1] == s3[j+i-1]);//first column
            else{//others
                dp[i][j] = (dp[i][j-1] && (s2[j-1] == s3[j+i-1]))||
                (dp[i-1][j] && (s1[i-1] == s3[j+i-1]));
            }
        }
    }
    return dp[rows][cols];
}

//多次递归，存在重复的子问题，大集合没有通过，考虑用DP
string a1,a2,a3;

bool helper(int index1,int index2,int index3){
    if (index3 == a3.size()) return true;
    if (a3[index3] == a1[index1])
        if (helper(index1 + 1, index2, index3 + 1))
            return true;
    if (a2[index2] == a3[index3])
        if (helper(index1, index2 + 1, index3 + 1))
            return true;
    
    return false;
}

bool isInterleave2(string s1, string s2, string s3) {
    a1 = s1;
    a2 = s2;
    a3 = s3;
    return helper(0, 0, 0);
}

void testIsInterleave(){
    bool res = isInterleave("", "", "");
    cout<<res<<endl;
}
