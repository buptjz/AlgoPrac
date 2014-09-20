//
//  BestTimetoBuyandSellStock.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-20.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_others.h"


int maxProfit(vector<int> &prices) {
    if (prices.size() == 0) {
        return 0;
    }
    int maxProfit = 0;
    int curMin = prices[0];
    
    for (int i = 1; i < prices.size(); i++) {
        int tmpProfit = prices[i] - curMin;
        maxProfit = max(maxProfit,tmpProfit);
        curMin = min(curMin,prices[i]);
    }
    return maxProfit;
}