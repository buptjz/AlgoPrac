//
//  ValidParentheses.cpp
//  LeetCode
//
//  Created by WangJZ on 14-3-1.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/longest-valid-parentheses/

/*
 思路：
 用一个number的stack记录在括号stack中上一个推入栈括号（不匹配的括号）是第几个，这样我们每次向后遍历的时候，更新max时根据前一个位置与现在到第几个数来更新 
 if (max_length < i + 1 - numberStack.top()) {
    max_length = i + 1 - numberStack.top();
 }
 
 */

#include "ValidParentheses.h"
#include <string>
#include <stack>
using namespace std;
bool isPair(char a,char b){
    if (a == '(' && b == ')')return true;
    return false;
}
int longestValidParentheses(string s) {
    int max_length = 0;
    stack<char> dataStack;
    stack<int> numberStack;
    numberStack.push(0);
    for (int i = 0; i < (int)s.length(); i++) {
        if (dataStack.empty() || !isPair(dataStack.top(), s[i])) {//情况1：stack里没有或者不匹配
            dataStack.push(s[i]);
            numberStack.push(i+1);
        }else{//情况2：匹配
            dataStack.pop();
            numberStack.pop();
        }
        if (max_length < i + 1 - numberStack.top()) {
            max_length = i + 1 - numberStack.top();
        }
    }
    return max_length;
}

void testIsValid(){
    string s = "(()))";
    int res = longestValidParentheses(s);
    printf("finished!");
}