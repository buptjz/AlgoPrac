//
//  LongestValidParentheses .cpp
//  Algorithms
//
//  Created by WangJZ on 14-3-20.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//



#include "leetcode_stack.h"

static bool isPair(char a,char b){
    if (a == '(' && b == ')')return true;
    return false;
}
//***-------------------2014.3.20更新-------------------***
//不需要一个stack，只需要一个记录当前匹配串的最大长度，如果一个右括号进来不且不匹配，当前最大长度就清零
//悲催的是这种思路是不行的，例如"()(()"
int longestValidParentheses2(string s) {
    int max_length = 0;
    int current_length = 0;
    stack<char> dataStack;
    for (int i = 0; i < (int)s.length(); i++) {
        if (dataStack.empty() || !isPair(dataStack.top(), s[i])) {//情况1：stack里没有或者不匹配
            if (s[i] == ')') {//当前这一轮的匹配结束了
                max_length = max(max_length,current_length);
                current_length = 0;
            }
            dataStack.push(s[i]);
        }else{//情况2：匹配
            current_length += 2;
            dataStack.pop();
        }
    }
    return max_length;
}


//思路：使用另一个stack记录当前栈中没有匹配的最后一个数字的index，那么每一次有匹配，本次匹配的长度就是i - stack.top() + 1
//最开始要push一个0进去

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
