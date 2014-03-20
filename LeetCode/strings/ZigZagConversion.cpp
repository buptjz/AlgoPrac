//
//  ZigZagConversion.cpp
//  LeetCode
//
//  Created by WangJZ on 14-1-22.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_string.h"

string convert(string s, int nRows)
{
    int length = (int)s.length();
    if (length == 0 || nRows == 1) return s;//边缘条件又忽略了 "A", 1
    
    int isMid;
    int dis = 2 * nRows - 2;
    int index;//原数组的下标
    int count = 0;//返回数组的下标

    string ret = string(s);
    for (int i = 0; i < nRows; i++) {
        index = i;
        isMid = false;
        while (index < length) {
            ret[count++] = s[index];
            if (i == 0 || i == nRows -1) {//第一行和最后一行
                index += dis;
            }else{
                if(isMid) index += 2 * i;
                else index += dis - 2 * i;
                isMid = !isMid;
            }
        }
    }
    return ret;
}


void testConvert(){
    string s = "ABCD";
    string a = convert(s, 2);
    printf("Finished\n");
}