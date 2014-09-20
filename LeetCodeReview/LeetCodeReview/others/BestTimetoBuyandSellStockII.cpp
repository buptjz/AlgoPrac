//
//  BestTimetoBuyandSellStockII.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-20.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_others.h"

static int maxProfit(vector<int> &prices) {
    if (prices.size() == 0) return 0;
    int profit = 0;
    int curMin = prices[0];
    int curMax = prices[0];
    
    for (int i = 1; i < prices.size(); i ++) {
        int tmpPrice = prices[i];
        if (tmpPrice < curMax) {//decrease ,consider sell
            if (curMax > curMin) profit += curMax - curMin;
            curMax = curMin = tmpPrice;
        }else{//continuely increase,do not sell
            curMax = tmpPrice;
        }
    }
    if (curMax > curMin) profit += curMax - curMin;
    return profit;
}
