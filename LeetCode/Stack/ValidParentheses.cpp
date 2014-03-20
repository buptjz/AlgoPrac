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
#include "leetcode_stack.h"

static bool isPair(char a,char b){
    if (a == '{' && b == '}')return true;
    if (a == '[' && b == ']')return true;
    if (a == '(' && b == ')')return true;
    return false;
}
bool isValid(string s) {
    stack<char> dataStack;
    for (int i = 0; i < (int)s.length(); i++) {
        if (dataStack.empty() || !isPair(dataStack.top(), s[i])) {//情况1：stack里没有或者不匹配
            dataStack.push(s[i]);
        }else{//情况2：匹配
            dataStack.pop();
        }
    }
    
    //评判合法的标准时栈是否为空？
    if (dataStack.empty()) {
        return true;
    }else{
        return false;
    }
}