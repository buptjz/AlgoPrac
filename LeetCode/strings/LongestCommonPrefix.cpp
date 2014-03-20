//
//  LongestCommonPrefix.cpp
//  LeetCode
//
//  Created by WangJZ on 14-2-28.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_string.h"

string longestCommonPrefix(vector<string> &strs) {
    int len = 0;
    int NWords = (int)strs.size();
    if (NWords == 0) {
        string s;
        return s;
    }
    bool should_stop = false;
    char cur;
    while (true) {
        cur = strs[0][len];
        if (cur == '\0') {
            break;
        }
        for (int i = 1; i < NWords; i++) {
            if (strs[i][len] != cur) {
                should_stop = true;
                break;
            }
        }
        if (should_stop) {
            break;
        }
        len++;
    }
    string s(strs[0],0,len);
    return s;
}

void testLongestComminPrefix(){
    string s1 = "abcdefg";
    string s2 = "abcddd";
    vector<string> ss = {s1,s2};
    string res = longestCommonPrefix(ss);
    printf("Finished!");
}