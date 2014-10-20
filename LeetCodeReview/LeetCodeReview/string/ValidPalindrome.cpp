//
//  ValidPalindrome.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-19.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  https://oj.leetcode.com/problems/valid-palindrome/

#include "leetcode_string.h"

//2014 10 12 更新
bool isPalindrome2(string s){
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    auto left =s.begin(), right = prev(s.end());
    while (left < right) {
        if (!isalnum(*left)) ++left;
        else if(!isalnum(*right)) ++right;
        else if(*left != *right) return false;
        else{left++; right--;}
    }
    return true;
}

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
