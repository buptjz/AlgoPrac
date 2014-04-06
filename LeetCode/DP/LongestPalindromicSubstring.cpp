//
//  LongestPalindromicSubstring.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-6.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/longest-palindromic-substring/

#include "leetcode_dp.h"

/*
 使用动态规划的算法，时间复杂度是O(n2),有更简洁的方法，请看这里
 http://leetcode.com/2011/11/longest-palindromic-substring-part-i.html
 并且这种做法是涉险过关，之前用vector是会time limit excceed ,而后参照上文换了数组
 */
string longestPalindrome(string s) {
    int length = (int)s.size();
    bool state[1000][1000] = {false};
    int start = 0,max_length = 1;
    for (int step = 0; step < length; step++) {
        for (int i = 0; i < length - step; i++) {
            switch (step) {
                case 0:
                    state[i][step+i] = true;
                    break;
                case 1:
                    if(s[i]==s[step+i]){
                        state[i][step+i] = true;
                        start = i;
                        max_length = step+1;
                    }
                    break;
                default:
                    if(state[i+1][step+i-1] && s[i] == s[step+i]){
                        state[i][step+i] = true;
                        start = i;
                        max_length = step+1;
                    }
                break;
            }
        }
    }
    return s.substr(start,max_length);
}

void testLongestPalindrome(){
    string res = longestPalindrome("abb");
    cout<<res<<endl;
}