//
//  LengthofLastWord.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-6.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_string.h"

/*
 Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 
 If the last word does not exist, return 0.
 */

int lengthOfLastWord(const char *s) {
    int start = -1,end = -1;
    bool inWord = false;
    int cur = 0;
    while (s[cur] != '\0') {
        if (s[cur] == ' ') {
            inWord = false;
        }else{
            if (inWord) {
                end = cur;
            }else{
                start = cur;
                end = cur;
            }
            inWord = true;
        }
        cur++;
    }
    if(start >= 0) return end - start + 1;
    else return 0;
}