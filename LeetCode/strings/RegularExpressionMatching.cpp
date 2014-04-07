//
//  RegularExpressionMatching.cpp
//  LeetCode
//
//  Created by WangJZ on 3/5/14.
//  Copyright (c) 2014 WangJZ. All rights reserved.
//

#include "leetcode_string.h"

/*
 
 update 2014.4.7
 
 此法的秘诀在于if (isMatch(s, p+2)) return true;这一行
 这里有点像backtrack
 先让p+2，与s匹配，如果不匹配，令p退回的到原来的状态，令s+1，再另p变成p+2，直到用尽所有的s，
 这样比isMatch(s,p+2) && isMatch(s+1,p)相比较而言，节省了非常多的计算
 因为
 isMatch(s+1,p)和isMatch(s,p+2)的下一步都可能会计算isMatch(s+1,p+2)
 
 '.' Matches any single character.
 '*' Matches zero or more of the preceding element.
 
 */
bool isMatch(const char *s, const char *p) {
    if (*p == '\0') return *s == '\0';
    
    //next char is not *
    if (*(p+1) != '*')
        return ((*p == *s || (*p == '.' && *s!='\0' )) && isMatch(s+1, p+1));
    
    //next char is *
    while ((*s == *p) || (*p=='.' && *s!='\0')) {
        if (isMatch(s, p+2)) return true;
        s++;
    }
    return isMatch(s, p+2);
}

//下面的代码没有通过

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
bool isMatch2(const char *s, const char *p) {
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
