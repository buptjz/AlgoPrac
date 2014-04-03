//
//  ScrambleString.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-3.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/scramble-string/

/*
    难题，参考了http://blog.csdn.net/jecklee/article/details/20854679的解法
 其中可以用到三维的动态规划，太猛了！
 */
#include "leetcode_others.h"

bool isScramble(string s1, string s2) {
    if (s1.size() != s2.size()) return false;
    if (s1 == s2) return true;
    int vcnt[26] = {0};
    for (int i = 0; i < s1.size(); i++) {
        vcnt[s1[i]-'a'] += 1;
    }
    for (int i = 0; i < s2.size(); i++) {
        vcnt[s2[i]-'a'] -= 1;
    }
    for (int i = 0; i < 26; i++) {
        if (vcnt[i] != 0) return false;
    }
    
    for (int i = 1; i < s1.size(); i++) {
        if ((isScramble(s1.substr(0,i), s2.substr(0,i))
             &&isScramble(s1.substr(i), s2.substr(i)))
            ||
            (
             (isScramble(s1.substr(0,i), s2.substr(s2.size() - i))
                    &&
              isScramble(s1.substr(i), s2.substr(0,s2.size() - i))
              )
             )
            ){
            return true;
        }
    }
    return false;
}


/*
 审题错误，没有说binary tree是怎么分割的，我这里默认当做是均匀分割，左侧=右侧 或者    左侧 = 右侧-1
 */
static string str1,str2;
bool isScrambleHelper(int b1,int e1,int b2,int e2){
    if (b1 - e1 == 0) {//base case 1: only 1 space
        if (str1[b1] == str2[b2]) return true;
        else return false;
    }
    int mid1 = (b1 + e1) >> 1;
    int mid2 = (b2 + e2) >> 1;
    if (mid1 - b1 == e1 - mid1) {//odd
        return
        (isScrambleHelper(b1, mid1 - 1, b2, mid2 - 1) && isScrambleHelper(mid1, e1, mid2, e2))
        ||
        (isScrambleHelper(b1, mid1 - 1, mid2 + 1, e2) && isScrambleHelper(mid1, e1, b2, mid2));
    }else{//even
        return
        (isScrambleHelper(b1, mid1, b2, mid2) && isScrambleHelper(mid1+1, e1, mid2+1, e2))
        ||
        (isScrambleHelper(b1, mid1, mid2 + 1, e2) && isScrambleHelper(mid1+1, e1, b2, mid2));
    }
}

bool isScramble2(string s1, string s2) {
    str1 = s1;
    str2 = s2;
    if (s1.size()!= s2.size()) return false;
    int length = (int)s1.size();
    return isScrambleHelper(0, length - 1, 0, length - 1);
}

void testIsCrramble(){
    bool res = isScramble("abc", "cba");
    printf("%d\n",res);
}