//
//  StringtoInteger.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-15.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_string.h"

#define SPACE ' '
int success = 1;

int atoi(const char *str){
    long retValue = 0;//
    int sign = 0;//0: not set yet
    bool hasNumber = false;
    bool hasSign = false;
    
    int curIndex = 0;
    while (str[curIndex] == SPACE) {
        curIndex++;
    }
    
    while (true) {
        char c = str[curIndex];
        if (isdigit(c)) {//数字
            hasNumber = true;
            if (hasSign == false) {
                hasSign = true;
                sign = 1;
            }
            retValue  = retValue * 10 + sign * (str[curIndex] - '0');
            if (retValue > INT_MAX) return INT_MAX;
            if (retValue < INT_MIN) return INT_MIN;

        }else if(c == '+') {//+
            if (hasSign == true) {
                success = 0;
                return 0;
            }else{
                hasSign = true;
                sign = 1;
            }
        }else if (c == '-'){//-
            if (hasSign == true) {
                success = 0;
                return 0;
            }else{
                hasSign = true;
                sign = -1;
            }
        }else{              //其它
            break;
        }
        curIndex++;
    }
    return (int)retValue;
}

void testAtoi(){
//    cout << atoi("123") <<'\n';//常规的
//    cout << atoi("+") <<'\n';//带加减号
    cout << atoi("2147483648") <<'\n';//开始带空格
    cout << atoi("+21e12") <<'\n';//带e
    cout << atoi("+5.21") <<'\n';//带小数点
    
}