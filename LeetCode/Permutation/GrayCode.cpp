//
//  GrayCode.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-3.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/gray-code/

/*
 不知道有什么好方法，我全部列出来之后寻找规律，发现可以依次设置每一个bit位
 第n个比特位从pow(2,n-1)开始：
    1）将连续的pow(2,n)个数的第i位设置为1
    2）跳过pow(2,n)个数
    3）重复2，3操作
 */

#include "leetcode_permutation.h"
#include <math.h>

vector<int> grayCode(int n) {
    int number = (int)pow(2, n);
    vector<int> retVec(number,0);
    int pow2[16] = {0};
    for (int i = 0; i < 16; i++) {
        pow2[i] = (int)pow(2,i);
    }
    for (int i = 1; i <= n; i++) {
        int start_pos = pow2[i-1];
        int distance = pow2[i];
        int keeping = distance;
        while (start_pos < number) {
            retVec[start_pos] = retVec[start_pos] | (1<<(i-1));//第i位置1
            keeping --;
            start_pos ++;
            if (keeping == 0) {
                start_pos += distance;
                keeping = distance;
            }
        }
        
    }
    return retVec;
}

void testGrayCode(){
    vector<int> res = grayCode(1);
    printf("Finished\n");
}