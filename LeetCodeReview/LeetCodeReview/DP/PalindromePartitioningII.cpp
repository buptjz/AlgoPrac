//
//  PalindromePartitioningII.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-19.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  https://oj.leetcode.com/problems/palindrome-partitioning-ii/

#include "leetcode_dp.h"


int minCut(string s) {
    int len = (int)s.length();
    
    if (len == 0) return 0;
    
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
    
    
    /* use dp to find min-cut
     Under the condition palinMat[start][end] == true:
     1) mins[end] = mins[start - 1] + 1     if mins[end] > mins[start - 1] + 1
     2) mins[end] = 0                       if start == 0
     */
    vector<int> mins(len,len);
    mins[0] = 0;
    for (int start = 0; start < len; start++) {
        for (int end = start; end < len; end++) {
            if (palinMat[start][end] && start == 0) {
                mins[end] = 0;
                continue;
            }
            if (palinMat[start][end] && mins[start - 1] + 1 < mins[end])
                mins[end] = mins[start - 1] + 1;
        }
    }
    
    return mins[len - 1];
}

void testMinCut(){
    string s = "ababababababababababababcbabababababababababababa";
    int res = minCut(s);
    cout << res << endl;
}


