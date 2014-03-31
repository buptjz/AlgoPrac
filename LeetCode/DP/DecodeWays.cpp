//
//  DecodeWays.cpp
//  Algorithms
//
//  Created by WangJZ on 14-3-31.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/decode-ways/

/*
【思路】其实解题思路是逐渐形成的，主要就是通过简单的例子来看，
 有几种特殊的情况要考虑到
 包含0的情况
 从前向后使用DP，
 没次走过一个数，可能会有四中情况
 0）失败了，            比如100，30         遇到失败，直接返回 0
 1）只能自己，           比如101，27         dp[i] = dp[i-1]
 2）只能和前一个数，      比如110              dp[i] = dp[i-2]
 3）两种都可以，         比如11，26           dp[i] = d[i-1] + dp[i-2]
*/

#include "leetcode_dp.h"
//0 代表失败
//1 代表只能自己
//2 代表只能和前一个数组合
//3 代表两种都可以

int group(char a,char b){
    switch (a) {
        case '0':
            if (b == '0') {
                return 0;
            }else{
                return 1;
            }
            break;
        case '1':
            if (b == '0') {
                return 2;
            }else{
                return 3;
            }
            break;
        case '2':
            if (b == '0') {
                return 2;
            }else if(b <= '6'){
                return 3;
            }else{
                return 1;
            }
            break;
        default:
            if (b == '0') {
                return 0;
            }else{
                return 1;
            }
            break;
    }
}
int numDecodings(string s) {
    int last =1,last2 = 1,temp;//分别表示截止目前的倒一数和倒数第二数
    int length = (int)s.length();
    if (length == 0 || s[0] == '0') return 0;
    for (int i = 2; i <= length; i++) {
        temp = last;
        int res = group(s[i-2],s[i-1]);
        switch (res) {
            case 0://错误
                return 0;
                break;
            case 1://只能自己
                last2 = last;
                break;
            case 2://只能和前一个数组合
                last =  last2;
                last2 = 0;
                break;
            case 3://两种都可以
                last = last + last2;
                last2 = temp;
                break;
            default:
                break;
        }
    }
    return last;
}

void testNumDecodings(){
    string s("101200");
    int res = numDecodings(s);
    printf("%d\n",res);
}