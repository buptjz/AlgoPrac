//
//  ScrambleString.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-24.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_others.h"

string ss1,ss2;

bool hasSameChars(string a1,string a2){
    char dic1[256] = {0};
    char dic2[256] = {0};
    for (int i = 0; i < a1.length(); i++) {
        dic1[a1[i]] += 1;
        dic2[a2[i]] += 1;
    }
    
    for (int i = 0; i < 256; i++) {
        if (dic1[i] != dic2[i]) return false;
    }
    
    return true;
}

bool helper(int s1_start,int s1_end,int s2_start,int s2_end){
    if (s1_start == s1_end) return ss1[s1_start] == ss2[s2_start];
    string tmp1 = ss1.substr(s1_start,s1_end - s1_start + 1);
    string tmp2 = ss2.substr(s2_start,s2_end - s2_start + 1);
    if (tmp1 == tmp2) return true;
    if (!hasSameChars(tmp1, tmp2)) return false;
    
    for (int i = s1_start; i < s1_end ; i++) {
        if (helper(s1_start, i, s2_start, s2_start + i -s1_start)&&
            helper(i+1, s1_end, s2_end - s1_end + i+1, s2_end))
            return true;
    }
    
    for (int i = s1_start; i < s1_end ; i++) {
        if (helper(s1_start, i, s2_end - i + s1_start, s2_end)&&
            helper(i+1, s1_end, s2_start, s2_start + s1_end - (i+1)))
            return true;
    }
    
    return false;
}

bool isScramble(string s1, string s2) {
    int len = (int)s1.length();
    if (len == 0) return true;
    ss1 = s1;
    ss2 = s2;
    return helper(0,len - 1,0,len - 1);
}

void testIsScramble(){
    string a1 = "ccabcbabcbabbbbcbb";
    string a2 = "bbbbabccccbbbabcba";
    cout<<isScramble(a1, a2)<<endl;
}