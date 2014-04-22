//
//  IntegertoRoman.cpp
//  Algorithms
//
//  Created by WangJZ on 14-3-31.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/integer-to-roman/

#include "leetcode_others.h"

/*
 2014.4.22日更新，体会用数据来编程,参考http://www.cnblogs.com/MrLJC/archive/2014/04/19/3674400.html
 */
string roman[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
int value[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
string intToRoman2(int num) {
    string ans;
    for (int i = 0; num != 0; i++) {
        while (num >= value[i]) {
            ans += roman[i];
            num -= value[i];
        }
    }
    return ans;
}

char getRomanFromInt(int i){
    switch (i) {
        case 1:
            return 'I';
            break;
        case 5:
            return 'V';
            break;
        case 10:
            return 'X';
            break;
        case 50:
            return 'L';
            break;
        case 100:
            return 'C';
            break;
        case 500:
            return 'D';
            break;
        case 1000:
            return 'M';
            break;
        default:
            return 0;
            break;
    }
}
string getRepresentFromInt(int remainder,int index)
{
    string retString;
    char x = getRomanFromInt(1 * index);
    char y = getRomanFromInt(5 * index);
    char z = getRomanFromInt(10 * index);
    switch (remainder) {
        case 0:
            break;
        case 1:{
            retString += x;
            break;
        }
        case 2:{
            retString += x;
            retString += x;
            break;
        }
        case 3:{
            retString += x;
            retString += x;
            retString += x;
            break;
        }
        case 4:{
            retString += x;
            retString += y;
            break;
        }
        case 5:{
            retString += y;
            break;
        }
        case 6:{
            retString += y;
            retString += x;
            break;
        }
        case 7:{
            retString += y;
            retString += x;
            retString += x;
            break;
        }
        case 8:{
            retString += y;
            retString += x;
            retString += x;
            retString += x;
            break;
        }
        case 9:{
            retString += x;
            retString += z;
            break;
        }
        default:
            break;
    }
    return retString;
}
string intToRoman(int num) {
    int index = 1;
    string retString;
    while (num) {
        string s = getRepresentFromInt(num % 10, index);
        retString = s+retString;
        num = num / 10;
        index *= 10;
    }
    return retString;
}

void testIntToRoman(){
    string s = intToRoman(1);
    cout<< s << endl;
}

