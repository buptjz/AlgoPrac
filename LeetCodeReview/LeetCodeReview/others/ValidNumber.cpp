//
//  ValidNumber.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-3.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_others.h"

bool isnum(char a){
    if (a <= '9' && a>='0') return true;
    else return false;
}


bool isNumber(const char *s) {
    
    bool hasNum = false;
    bool hasSign = false;
    bool hasTailSpace = false;
    bool hasE = false;
    bool hasPoint = false;
    //eliminate starting spaces
    while (*s == ' ')
        s++;
    
    //\0 without any prefix
    if (*s == '\0') return false;
    
    //scan to end
    while (*s != '\0') {
        if(*s == ' '){
            //结尾空格之前只能是空格或者数字
            if (!isnum(*(s-1)) && *(s-1) != ' ' && *(s-1) != '.') return false;
            hasTailSpace = true;
        }else{
            if (hasTailSpace) return false;//结尾空格之后还有非空格，false
            if (*s == '+' || *s == '-') {
                if (hasE){
                    if(*(s-1) != 'e')
                        return false;
                }else if (hasSign || hasNum || hasPoint) return false;
                
                hasSign = true;
            }else if(isnum(*s)){
                hasNum = true;
            }else if(*s == 'e'){
                if (hasE) return false;
                if (!hasNum) return false;
                hasE = true;
            }else if(*s == '.'){
                if (hasPoint) return false;
                if(hasE) return false;
                hasPoint = true;
            }else{
                return false;
                
            }
        }
        s++;
    }
    
    if (!hasNum) return false;
    if (*(s-1) == 'e' || *(s-1) == '+' || *(s-1) == '-') return false;
    return true;
}



void testIsNumber(){
//    ".1" true
    char *s0 = "00";
    char *s1 = "+3";
    
    char *s2 = "+3-";
    char *s3 = "  3  ";
    char *s4 = "  3 3 ";
    char *s5 = "3a";
    char *s6 = "3e0";
    char *s7 = ".1";
    char *s8 = ".e";
    
}