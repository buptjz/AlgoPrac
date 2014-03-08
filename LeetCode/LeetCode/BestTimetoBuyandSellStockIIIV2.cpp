//
//  BestTimetoBuyandSellStockIIIV2.cpp
//  LeetCode
//
//  Created by WangJZ on 3/8/14.
//  Copyright (c) 2014 WangJZ. All rights reserved.
//

#include "BestTimetoBuyandSellStockIIIV2.h"
#include <vector>


/*
 [思路]Best Time to Buy and Sell Stock III 第一版的改良，参考了
 http://blog.csdn.net/fightforyourdream/article/details/14503469
 状态：通过
 
 */
using namespace std;

void generate02I(vector<int> &prices,vector<int> &retVec){
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
}

void generateI2N(vector<int> &prices,vector<int> &retVec){
    int length = (int)prices.size();
    int cur_max = prices[length - 1];
    int current_max_profit = 0;
    retVec[length - 1] = 0;//最后一点的收益是0
    for (int i = length - 2; i >= 0; i--) {//从第二个点开始计算
        if (prices[i] > cur_max) {
            cur_max = prices[i];
            retVec[i] = retVec[i+1];//当前的最大收益和后一个点的最大收益一样
            continue;
        }
        if (cur_max - prices[i] > current_max_profit) {//当前收益提升了
            current_max_profit = cur_max - prices[i];
            retVec[i] = current_max_profit;
        }else{
            retVec[i] = retVec[i+1];//当前的最大收益和上一次的一样
        }
    }

}

int maxProfit4(vector<int> &prices) {
    //分别一1，2，3，……，n-1点作为分隔，左右分别买卖一次，左右相加是以该点为分隔情况下的最大收益，在n-1个种情况下最大的值就是我们的最大收益
    int left,right;
    int length = (int)prices.size();
    vector<int> zeroToI = vector<int>(length,0);
    vector<int> iToN = vector<int>(length,0);
    generate02I(prices, zeroToI);
    generateI2N(prices, iToN);
    
    int retVal = max(zeroToI[length -1],iToN[0]);
    for (int i = 1; i < length; i++) {
        left = zeroToI[i-1];
        right = iToN[i];
        if (left+right > retVal) {
            retVal = left+right;
        }
    }
    return retVal;
}

void testMaxProfit4(){
    vector<int> prices = {1,2};
    int res = maxProfit4(prices);
    printf("Finished %d\n",res);
    
}