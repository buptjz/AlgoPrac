//
//  BestTimetoBuyandSellStockIII.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-20.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

#include "leetcode_others.h"

// at most two transactions. Pay attention to at most

static int maxProfit(vector<int> &prices) {
    int length = (int)prices.size();
    if (length == 0) return 0;
    
    int curMin = prices[0];
    int curMax = prices[length - 1];
    int curProfit = 0;
    int maxProfit = 0;
    
    vector<int> leftProfit(length,0);
    vector<int> rightProfit(length,0);

    for (int i = 1; i < length; i++) {
        int tmpPrice = prices[i];
        curProfit = max(curProfit,tmpPrice - curMin);
        leftProfit[i] = curProfit;
        curMin = min(curMin,tmpPrice);
    }
    maxProfit = max(maxProfit,curProfit);
    
    curProfit = 0;
    for (int i = length - 2; i >=0; i--) {
        int tmpPrice = prices[i];
        curProfit = max(curProfit,curMax - tmpPrice);
        rightProfit[i] = curProfit;
        curMax = max(curMax,tmpPrice);
    }
    
    maxProfit = max(maxProfit,curProfit);
    for (int i = 0; i < length - 1; i++) {
        maxProfit = max(maxProfit,leftProfit[i] + rightProfit[i + 1]);
    }
    return maxProfit;
}

