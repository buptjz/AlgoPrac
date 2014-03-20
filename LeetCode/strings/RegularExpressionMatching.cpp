//
//  RegularExpressionMatching.cpp
//  LeetCode
//
//  Created by WangJZ on 3/5/14.
//  Copyright (c) 2014 WangJZ. All rights reserved.
//

#include "leetcode_string.h"
bool isMatchHelper(const char *s, const char *p){
    //base case 1：s走到了尽头，匹配完成
    if (*s == '\0') {
        if (*(p+1) == '*') return isMatchHelper(s, p+2);
        else return *p == '\0';
    }
    //base case 2:s没有匹配完成，p却走到了尽头
    switch (*p) {
        case '\0':
            return false;
            break;
            
        case '.':{
            if (*(p+1) == '*') {
                return isMatchHelper(s+1,p) || isMatchHelper(s,p+2);
            }else{
                return isMatchHelper(s+1,p+1);
            }
            break;
        }
            
        case '*':{
            return false;
        }
            
        default:
            if (*(p+1) == '*') {//如果下一个字符是*
                if (*s == *p) {//当前是一样的，有3种选择
                    return isMatchHelper(s+1,p) || isMatchHelper(s,p+2);
                }else{//当前并不匹配，有一种选择
                    return isMatchHelper(s,p+2);
                }
            }else{//普通情况
                if (*s == *p) {
                    return isMatchHelper(s+1,p+1);
                }else{
                    return false;
                }
            }
            break;
    }
}
bool isMatch(const char *s, const char *p) {
    if (*p == '*') {
        return false;
    }else{
        return isMatchHelper(s,p);
    }
}
//bool isMatch2(const char *s, const char *p) {
//    count++;
//    if (*p == '\0') return *s == '\0';
//    
//    // next char is not '*': must match current character
//    if (*(p+1) != '*') {
//        return ((*p == *s) || (*p == '.' && *s != '\0')) && isMatch2(s+1, p+1);
//    }
//    // next char is '*'
//    while ((*p == *s) || (*p == '.' && *s != '\0')) {
//        if (isMatch2(s, p+2)) return true;
//        s++;
//    }
//    return isMatch2(s, p+2);
//}



void testIsMatch(){
    bool a = isMatch("a", "ab*");
    printf("Finishd %d\n",1);
}
