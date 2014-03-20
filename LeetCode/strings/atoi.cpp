//
//  atoi.cpp
//  LeetCode
//
//  Created by WangJZ on 14-2-28.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/string-to-integer-atoi/

#include "leetcode_string.h"

int atoi(const char *str) {
    long long MIN_INT =  -2147483648;
    long long MAX_INT =  2147483647;
    
    //第一位的判断，可能是+-.
    int INVALID = 0;
    bool num_appear = false;//已经出现number
    bool sign_appear = false;//已经出现了符号
    int Ndot = 0;//已经出现dot的位数
    float sign = 1;
    long long i_part =0;//记录整数部分
    float d_part=0;//记录小数部分
    
    while (*str !='\0') {//按位向后遍历，5情况，‘.’ 数字 空格 + -
        if (*str <= '9' && *str >='0') {//数字
            num_appear = true;//出现了数字
            if (Ndot) {//已经出现过'.'
                d_part = 10 * d_part + *str - '0';
                Ndot++;
            }else{//还在整数部分
                i_part = 10 * i_part + *str - '0';
                if (sign == 1 && i_part > MAX_INT) {
                    return int(MAX_INT);
                }
                if (sign == -1 &&(-1 *i_part) < MIN_INT) {
                    return int(MIN_INT);
                }
            }
        }else if(*str == '.'){
            if (Ndot == 0) {
                Ndot ++;
            }else{
                break;
            }
        }else if(*str == ' '){//空格，如果空格前没有出现过数字或者点，啥也不做
            if (sign_appear || num_appear || Ndot > 0) {
                break;
            }
        }else if(*str == '+'){
            if (sign_appear) {
                break;
            }else{
                sign_appear= true;
            }
            if (num_appear || Ndot > 0) {
                break;
            }else{
                sign = 1;
            }
        }else if(*str == '-'){
            if (sign_appear) {
                break;
            }else{
                sign_appear= true;
            }
            if (num_appear || Ndot > 0) {
                break;
            }else{
                sign = -1;
            }
        }else{
            break;
        }
        str++;
    }
    if (!num_appear) {//【invalid】 没有出现过数字
        return INVALID;
    }
    //计算小数部分
    while (Ndot > 1) {//小数点后出现n个数字，Ndot的值会是n+1
        d_part /= 10;
        Ndot--;
    }
    return int(sign *(float(i_part) + d_part));
}


void testAtoi(){
    char *p = "-2147483648";
    int result = atoi(p);
    printf("Finished");
}