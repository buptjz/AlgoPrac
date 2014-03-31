//
//  RomantoInteger.cpp
//  Algorithms
//
//  Created by WangJZ on 14-3-31.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/roman-to-integer/

#include "leetcode_others.h"

//I(1)，V(5)，X(10)，L(50)，C(100)，D(500)，M(1000)

//备注：leetcode上的这道题没有检测输入是否是正确的！
int getIntFromRoman(char c){
    switch (c) {
        case 'I':
            return 1;
            break;
        case 'V':
            return 5;
            break;
        case 'X':
            return 10;
            break;
        case 'L':
            return 50;
            break;
        case 'C':
            return 100;
            break;
        case 'D':
            return 500;
            break;
        case 'M':
            return 1000;
            break;
        default:
            return 0;
            break;
    }
}
int romanToInt(string s) {
    int length = (int)s.size();
    if(length == 0) return 0;
    int retValue = getIntFromRoman(s[length - 1]);
    for (int i = length - 2; i >= 0; i--) {
        if (getIntFromRoman(s[i])  < getIntFromRoman(s[i+1])) {//当前的数字如果小于上一个数字，要减去当前数字
            retValue -= getIntFromRoman(s[i]);
        }else{
            retValue += getIntFromRoman(s[i]);
        }
    }
    return retValue;
}

void testRomanToInt(){
    int res = romanToInt("IVI");
    printf("Exp: 15 -- %d",res);
    int res2 = romanToInt("MDCLXVI");
    printf("Exp: 1666 -- %d",res2);
}



