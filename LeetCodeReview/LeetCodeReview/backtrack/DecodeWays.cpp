//
//  DecodeWays.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-24.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_backtrack.h"


int numDecodings(string s) {
    int len = (int)s.length();
    if (len == 0 || s[0] == '0') return 0;
    
    vector<int> state(len+1,1);
    
    for (int i = 2; i <= len; i++) {
        char cur = s[i-1];
        char pre = s[i-2];
        if (cur == '0') {
            if (pre > '2' || pre == '0') return 0;
            state[i] = state[i-2];
        }else{
            state[i] = state[i-1];
            int num = 10 * (pre - '0') + (cur - '0');
            if (num <= 26 && num > 10) state[i] += state[i-2];
        }
    }
    return state[len];
}