//
//  PalindromePartitioning.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-19.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  https://oj.leetcode.com/problems/palindrome-partitioning/

#include "leetcode_dp.h"


//先用动态规划法求解 回文矩阵，再用回溯法求解解集合。

void backtrack(vector<vector<string>> &result,string s, int index,const vector<vector<bool>> & mat, vector<string> &cur){
    if (index == s.length()) {
        result.push_back(cur);
        return;
    }
    
    for (int step = 0; step + index < s.length(); step ++) {
        int end = index + step;
        if (mat[index][end] == false) continue;
        cur.push_back(s.substr(index,step + 1));
        backtrack(result, s, end + 1, mat, cur);
        cur.pop_back();
    }
}

static vector<vector<string>> partition(string s) {
    vector<vector<string>> retVec;

    int len = (int)s.length();
    
    if (len == 0) return retVec;
    
    /* Step 1 Generate Palindrome Matrix */
    vector<vector<bool>> palinMat;
    for (int i = 0; i < len; i++) {
        vector<bool> palinRow = vector<bool>(len,false);
        palinRow[i] = true;
        palinMat.push_back(palinRow);
    }
    
    // step size from 1 to N - 1
    for (int step = 1; step < len; step++) {
        for (int start = 0; start + step < len; start++) {
            int end = start + step;
            if (s[start] != s[end]) {//s[i] != s[j], mat(i,j) = false
                palinMat[start][end] = false;
            }else{
                //s[i] == s[j], check mat[i+1,j-1] when step > 1,if step == 1 no need to check
                if (step == 1) palinMat[start][end] = true;
                else palinMat[start][end] = palinMat[start + 1][end - 1];
            }
        }
    }
    
    /* Step 2 Generate Palinrome Segments Using Backtrack */
    vector<string> cur;
    backtrack(retVec, s, 0, palinMat,cur);
    
    return retVec;
    
}

void testPartition(){
    string s = "abba";
    vector<vector<string>> res = partition(s);
    
}