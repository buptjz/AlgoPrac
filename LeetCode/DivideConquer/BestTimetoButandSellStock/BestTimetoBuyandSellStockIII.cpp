//
//  BestTimetoBuyandSellStockIII.cpp
//  LeetCode
//
//  Created by WangJZ on 3/8/14.
//  Copyright (c) 2014 WangJZ. All rights reserved.
//

#include "leetcode_others.h"

/*
[思路]分别以每一个点作为作为中间点，认为两次操作在分隔的左右两侧，分别计算两侧一次收益的最大值，相加即为该分割点下的最大收益
 所有n-1中分别情况中的最大值，即为最大收益
 状态： Time Limit Exceeded
 时间复杂度是O(n2log(n))
 */

int maxProfitHelper3(vector<int> &prices,int &max_price,int &min_price,int start,int end){
    //base case
    if (start == end) {
        max_price = prices[start];
        min_price = prices[start];
        return 0;//没有收益
    }
    int mid = (start + end) >> 1;
    int left_min,right_min,left_max,right_max;
    
    int leftProfit = maxProfitHelper3(prices, left_max, left_min, start, mid);
    int rightProfit = maxProfitHelper3(prices, right_max, right_min, mid+1, end);
    int mergeProfit = right_max - left_min;
    
    min_price = min(left_min,right_min);
    max_price = max(left_max,right_max);
    
    //返回三者之后最大的
    return max(max(leftProfit, rightProfit),mergeProfit);
}

int maxProfit3(vector<int> &prices) {
    //分别一1，2，3，……，n-1点作为分隔，左右分别买卖一次，左右相加是以该点为分隔情况下的最大收益，在n-1个种情况下最大的值就是我们的最大收益
    int length = (int)prices.size();
    int retVal = 0;
    int left,right;
    int max_price,min_price;
    for (int i = 1; i < length; i++) {
        left = maxProfitHelper3(prices, max_price,min_price,0, i-1);
        right = maxProfitHelper3(prices, max_price, min_price, i, length-1);
        if (left+right > retVal) {
            retVal = left+right;
        }
    }
    return retVal;
}

void testMaxProfit3(){
    vector<int> prices = {1,3,4,2,1,5};
    int res = maxProfit3(prices);
    printf("Finished %d\n",res);
    
}

