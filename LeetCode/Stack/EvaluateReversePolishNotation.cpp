//
//  EvaluateReversePolishNotation.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-7.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/evaluate-reverse-polish-notation/

/*
 其实很简单的题目，注意的是细节，比如string转换成Int的时候，是否考虑到了前面的符号
 */

#include "leetcode_stack.h"

int stringToInt(string s){
    int sign,sum;
    if (s[0] == '-') {
        sign = -1;
        sum = 0;
    }else if(s[0] == '+'){
        sign = 1;
        sum = 0;
    }else{
        sign = 1;
        sum = s[0] - '0';
    }
    
    int length = (int)s.size();
    for (int i = 1; i < length; i++)
        sum = sum * 10 + (s[i] - '0');
    return sum * sign;
}
int evalRPN(vector<string> &tokens) {
    if (tokens.size() == 0) return 0;
    int first,second;
    stack<int> st;
    for (int i = 0 ; i < tokens.size(); i++) {
        if (tokens[i] == "*" ||
            tokens[i] == "+" ||
            tokens[i] == "-" ||
            tokens[i] == "/") {
            char sign = tokens[i][0];
            second = st.top();
            st.pop();
            first = st.top();
            st.pop();
            switch (sign) {
                case '+':
                    st.push(first + second);
                    break;
                case '-':
                    st.push(first - second);
                    break;
                case '*':
                    st.push(first * second);
                    break;
                case '/':
                    st.push(first / second);
                    break;
                default:
                    break;
            }
        }else{
            st.push(stringToInt(tokens[i]));
        }
    }
    return st.top();
}

void testEvalRPN(){
    vector<string> str= {"-4", "13", "5", "/", "+"};
    int res = evalRPN(str);
    cout<<res<<endl;
}

