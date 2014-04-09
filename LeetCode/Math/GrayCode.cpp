//
//  GrayCode.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-3.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/gray-code/

#include "leetcode_permutation.h"
#include <math.h>

/*
 2014.4.9更新
 方案一：
 http://www.cnblogs.com/lihaozy/archive/2012/12/31/2840437.html这篇文章提到了
 二进制码可以直接转换为格雷码，转换公式是：
 grayCode = i ^ (i>>1)
 
 方案二：
 http://leetcodenotes.wordpress.com/2013/10/19/leetcode-gray-code-%E7%94%9F%E6%88%90%E7%9B%B8%E9%82%BB%E4%B8%A4%E4%B8%AA%E6%95%B0%E5%8F%AA%E6%9C%891%E4%BD%8D%E4%B8%8D%E5%90%8C%E7%9A%84%E5%BA%8F%E5%88%97%EF%BC%8C%E6%AF%8F%E4%B8%AA%E6%95%B0/
 假设有n-1的答案为：G0, G1, …, Gn，想得到n的答案，只需要在G0…Gn左边加上一个0，再把G0…Gn颠倒顺序，在左边加上一个1即可

 */
vector<int> grayCode(int n) {
    vector<int> retVec(1<<n,0);
    for (int i = 0; i < (1<<n); i++)
        retVec[i] = i ^ (i>>1);
    return retVec;
}

/*
 不知道有什么好方法，我全部列出来之后寻找规律，发现可以依次设置每一个bit位
 第n个比特位从pow(2,n-1)开始：
 1）将连续的pow(2,n)个数的第i位设置为1
 2）跳过pow(2,n)个数
 3）重复2，3操作
 */
vector<int> grayCode2(int n) {
    int number = (int)pow(2, n);
    vector<int> retVec(number,0);
    int pow2[16] = {0};
    for (int i = 0; i < 16; i++)
        pow2[i] = (int)pow(2,i);
    
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