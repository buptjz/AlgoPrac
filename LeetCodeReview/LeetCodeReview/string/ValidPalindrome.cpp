//
//  ValidPalindrome.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-19.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  https://oj.leetcode.com/problems/valid-palindrome/

#include "leetcode_string.h"

bool isPalindrome(string s) {
    int len = (int)s.size();
    if (len <= 1) return true;
    int left = 0, right = len - 1;
    while (left < right) {
        if(!isalnum(s[left])) {
            left++;
        }else if(!isalnum(s[right])){
            right--;
        }else{
            if (tolower(s[right]) != tolower(s[left])) {
                return false;
            }else{
                left++;
                right--;
            }
        }
    }
    return true;
}
