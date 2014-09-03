//
//  ReverseWordsinaString.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-3.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_string.h"

/*
 https://oj.leetcode.com/problems/reverse-words-in-a-string/
 
 What constitutes a word?
 A sequence of non-space characters constitutes a word.
 Could the input string contain leading or trailing spaces?
 Yes. However, your reversed string should not contain leading or trailing spaces.
 How about multiple spaces between two words?
 Reduce them to a single space in the reversed string.

 */

void reverseWords(string &s) {
    int len = (int)s.length();
    if (len == 0) return;
    string tmpString = "";
    int right = (int)s.length() - 1;
    int left = right - 1;
    while (left >=0 && right >=0) {
        if (s[right] == SPACE) {
            right--;
            left --;
        }else if(s[left] == SPACE){
            if (tmpString.length() != 0) tmpString += " ";
            tmpString += s.substr(left+1,right - left);
            right = left - 1;
            left = right - 1;
        }else{
            left --;
        }
    }
    if (right >=0 && s[right] != SPACE) {
        if (tmpString.length() != 0) tmpString += " ";
        tmpString += s.substr(0,right+1);
    }
    s = tmpString;
}


void testReverseWords(){
    string s = "  a  bc" ;
    reverseWords(s);
    cout << s<<endl;
}


