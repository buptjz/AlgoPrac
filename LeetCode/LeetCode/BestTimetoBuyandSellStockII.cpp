//
//  BestTimetoBuyandSellStockII.cpp
//  LeetCode
//
//  Created by WangJZ on 3/7/14.
//  Copyright (c) 2014 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/



#include "BestTimetoBuyandSellStockII.h"
#include <vector>
using namespace std;

//遇到连续下降，在最低点买入
//遇到连续上升，在最高点卖出

int maxProfit2(vector<int> &prices) {
    if (prices.size() == 0) {
        return 0;
    }
    int buy = 0;
    bool isBuy = false;
    int length = (int)prices.size();
    int accumulate = 0;
    for (int i = 1; i < length; i++) {
        if (!isBuy) {//需要买进
            if (prices[i] <= prices[i-1]) {//走下坡路，不着急买
                continue;
            }else{//往上走了，可以买进前一个
                isBuy = true;
                buy = prices[i-1];
            }
        }else{//需要卖出
            if (prices[i] > prices[i - 1]) {//走上坡路,并且不是最后一个，不着急卖
                continue;
            }else{//卖掉
                accumulate += prices[i - 1] - buy;
                buy = 0;
                isBuy = false;
            }
        }
    }
    if (isBuy) {//需要卖出
        accumulate += prices[length - 1] - buy;
    }
    return accumulate;
}

void testMaxProfit2(){
    vector<int > prices = {2,4,3,1};
    int res = maxProfit2(prices);
    printf("Finishing  %d\n",res);
    
}