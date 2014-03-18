//
//  NextPermutation.cpp
//  LeetCode
//
//  Created by WangJZ on 14-2-20.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/next-permutation/

#include "NextPermutation.h"
#include <vector>

using namespace std;

void nextPermutation(vector<int> &num) {
    int N = (int)num.size();
    if (N == 0 || N == 1) return;
    int last = N-1;
    //step1：找到最后一对严格递增对的左数
    int left = -1;
    while (last > 0) {
        last--;
        if (num[last] < num[last+1]) {
            left = last;
            break;
        }
    }
    //如果left是-1，所以是递减序列，说明是最大值，按照题目的说法，最大值的下一个是最小值，就是排序
    if (left == -1) {
        sort(num.begin(), num.end());
        return;
    }
    //step2：找到最后一对严格递增对的右数（从右开始第一个大于左数的值）
    last = N - 1;
    int right = 0;
    while (last > 0) {
        if (num[last] > num[left]) {
            right = last;
            break;
        }
        last--;
    }
    //step3：交互这俩数
    swap(num[left], num[right]);
    //step4:调转left（不包含left）右边的所有的数，使其升序排列
    last = N - 1;
    left += 1;
    while (last > left) {
        swap(num[last], num[left]);
        last--;
        left++;
    }
}

void testNextPermutation(){
    vector<int>testVector1 = {1,3,2};
    vector<int>testVector2 = {4,4};
    vector<int>testVector3 = {4};
    vector<int>testVector4 = {1,2,3,4,5};
    nextPermutation(testVector1);
    printf("Finished!");
}

