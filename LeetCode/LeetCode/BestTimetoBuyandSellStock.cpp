//
//  BestTimetoBuyandSellStock.cpp
//  LeetCode
//
//  Created by WangJZ on 3/7/14.
//  Copyright (c) 2014 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock/


#include "BestTimetoBuyandSellStock.h"
#include <vector>
using namespace std;

//Binary search
int maxProfitHelper(vector<int> &prices,int &max_price,int &min_price,int start,int end){
    //base case
    if (start == end) {
        max_price = prices[start];
        min_price = prices[start];
        return 0;//没有收益
    }
    int mid = (start + end) >> 1;
    int left_min,right_min,left_max,right_max;
    
    int leftProfit = maxProfitHelper(prices, left_max, left_min, start, mid);
    int rightProfit = maxProfitHelper(prices, right_max, right_min, mid+1, end);
    int mergeProfit = right_max - left_min;
    
    min_price = min(left_min,right_min);
    max_price = max(left_max,right_max);
    
    //返回三者之后最大的
    return max(max(leftProfit, rightProfit),mergeProfit);
}

int maxProfit(vector<int> &prices) {
    if (prices.size() == 0) {
        return 0;
    }
    int max_price;
    int min_price;
    return maxProfitHelper(prices, max_price, min_price, 0, (int)prices.size() - 1);
}

void testMaxProfit(){
    vector<int> prices = {5,4,4,8,5,2,3};
    int res = maxProfit(prices);
    printf("Finishe %d\n",res);
}




