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

/*************************************下面是一种更容易理解的思路*************************************/
//来自http://blog.csdn.net/fightforyourdream/article/details/14503469的启发
int maxProfitt(vector<int> &prices){
    int length = (int)prices.size();
    if (length == 0) {
        return 0;
    }
    vector<int> retVec = vector<int>(length,0);
    int cur_min = prices[0];
    int current_max_profit = 0;
    retVec[0] = 0;//第一个的收益是0
    for (int i = 1; i < (int)prices.size(); i++) {//从第二个点开始计算
        if (prices[i] < cur_min) {
            cur_min = prices[i];
            retVec[i] = retVec[i-1];//当前的最大收益和上一次的一样
            continue;
        }
        if (prices[i] - cur_min > current_max_profit) {//当前收益提升了
            current_max_profit = prices[i] - cur_min;
            retVec[i] = current_max_profit;
        }else{
            retVec[i] = retVec[i-1];//当前的最大收益和上一次的一样
        }
    }
    return retVec[length - 1];
}


void testMaxProfit(){
    vector<int> prices = {1,2,3,10};
    int res = maxProfitt(prices);
    printf("Finishe %d\n",res);
}




