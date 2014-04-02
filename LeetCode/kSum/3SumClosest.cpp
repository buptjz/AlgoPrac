//
//  3SumClosest.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-2.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/3sum-closest/

#include "leetcode_others.h"

int threeSumClosest(vector<int> &num, int target) {
    if (num.size() < 3) return -1;
    int cur_close = abs(num[0] + num[1] + num[2] - target);
    int cur_sum = num[0] + num[1] + num[2];
    int length = (int)num.size();
    int start,end,curTarget;
    sort(num.begin(), num.end());//递增排序
    for (int i = 0; i < length; i++) {
        if (i!=0 && num[i] == num[i - 1]) continue;//如果和上一个一样，不做处理
        start = i + 1;
        end = length - 1;
        curTarget = target - num[i];
        while (start < end) {
            if (cur_close > abs(num[start] + num[end] - curTarget)) {
                cur_close = abs(num[start] + num[end] - curTarget);
                cur_sum = num[start] + num[end] + num[i];
            }
            if (num[start] + num[end] < curTarget) start++;
            else end--;
        }
    }
    return cur_sum;
}

void testThreeSumClosest(){
    vector<int>x = {1,1,3,-4};
    int res = threeSumClosest(x, 1);
    printf("%d\n",res);
}