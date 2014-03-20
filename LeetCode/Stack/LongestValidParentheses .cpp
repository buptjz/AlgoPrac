//
//  LongestValidParentheses .cpp
//  Algorithms
//
//  Created by WangJZ on 14-3-20.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_stack.h"

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
