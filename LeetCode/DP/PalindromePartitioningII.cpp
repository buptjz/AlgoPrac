//
//  PalindromePartitioningII.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-6.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/palindrome-partitioning-ii/

#include "leetcode_dp.h"

static vector<vector<string> > ret;
static vector<vector<bool> > table;
static string str;
static int length;
static vector<vector<bool> > getState(const string &s) {
    vector<vector<bool>> state(length,vector<bool>(length,false));
    for (int step = 0; step < length; step++) {
        for (int i = 0; i < length - step; i++) {
            switch (step) {
                case 0:
                    state[i][step+i] = true;
                    break;
                case 1:
                    state[i][step+i] = s[i]==s[step+i];
                    break;
                default:
                    if(state[i+1][step+i-1] && s[i] == s[step+i])
                        state[i][step+i] = true;
                    break;
            }
        }
    }
    return state;
}

int minCut(string s) {
    if (s.size() == 0) return 0;
    length = (int)s.size();
    table = getState(s);
    str = s;
    vector<int> mins(length,length);
    for (int end = 0; end < length; end++)
        if (table[0][end])
            mins[end] = 0;
    
    for (int start = 1; start < length; start++) {
        for (int end = start; end < length; end++) {
            if (table[start][end] && mins[end] > mins[start-1] + 1)
                mins[end] = mins[start-1] + 1;
        }
    }
    return mins[length-1];
}

void testMinCut(){
    int res = minCut("");
    cout<<res<<endl;
}
