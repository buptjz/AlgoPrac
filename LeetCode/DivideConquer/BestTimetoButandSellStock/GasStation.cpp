//
//  GasStation.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-1.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/gas-station/

//更优雅的版本http://www.cnblogs.com/TenosDoIt/p/3389924.html
#include "leetcode_others.h"

int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    size_t length = gas.size();
    vector<int> toEnd(gas.size(),0);
    toEnd[length - 1] = gas[length - 1] - cost[length - 1];
    for (size_t i = 1; i < length; i++) {
        size_t toEndIndex = length - 1 - i;
        toEnd[toEndIndex] = toEnd[toEndIndex+1] + gas[toEndIndex] - cost[toEndIndex];
    }
    int cur_max = -1;
    size_t index = -1;
    for (size_t i = 0; i < length; i++) {
        if (toEnd[length - i - 1] > cur_max) {
            index = length - i - 1;
            cur_max = toEnd[length - i - 1];
        }
    }
    return toEnd[0] >= 0? (int)index : -1;
}

void testCanCompleteCircuit(){
    vector<int> gas = {2,4};
    vector<int> cost = {3,4};
    int res = canCompleteCircuit(gas, cost);
    printf("Finished %d \n",res);
}


