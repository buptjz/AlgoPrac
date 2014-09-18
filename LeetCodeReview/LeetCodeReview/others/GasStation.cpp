//
//  GasStation.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-18.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_others.h"

int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int accum = 0;
    int need = 0,startPoint = 0;
    for (int i = 0; i < gas.size(); i++) {
        need += gas[i] - cost[i];
        accum += gas[i] - cost[i];
        if (accum < 0) {
            accum = 0;
            startPoint = i + 1;
        }
    }
    
    if (accum + need >= 0)return startPoint;
    else return -1;
}
