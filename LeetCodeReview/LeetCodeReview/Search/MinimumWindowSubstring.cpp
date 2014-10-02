//
//  MinimumWindowSubstring.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-2.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_search.h"

bool dicIsEqual(int *s,int *t,int len){
    for (int i = 0; i < len; i++) {
        if (t[i] != 0 && s[i] < t[i]) {
            return false;
        }
    }
    return true;
}

string minWindow(string S, string T) {
    string minString;
    if (S.length() < T.length()) return minString;
    int s_dic[128] = {0};
    int t_dic[128] = {0};
    for (char t : T)
        t_dic[t]++;
    
    int minLength = (int)S.size() + 1;

    int start = 0;
    int end = 0;
    while (end < S.size()) {
        s_dic[S[end]] ++;
        if (dicIsEqual(s_dic,t_dic,128)) {
            while (dicIsEqual(s_dic,t_dic,128) && start <= end)
                s_dic[S[start++]] --;
            int tmp_start = start - 1;
            if (end - tmp_start + 1 < minLength) {
                minLength = end - tmp_start + 1;
                minString = S.substr(tmp_start,minLength);
            }
        }
        end++;
    }
    return minString;
}

void testMinWindow(){
    string S = "ab";
    string T = "aa";
    string ans = minWindow(S, T);
    cout << ans << endl;
}




