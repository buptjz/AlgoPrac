//
//  Candy.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-18.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_others.h"

int candy(vector<int> &ratings) {
    int len = (int)ratings.size();
    if (len == 0) return 0;
    vector<int> candies = vector<int>(len,1);
    for (int i = 1; i < len; i++) {
        if (ratings[i] > ratings[i - 1])
            candies[i] = candies[i - 1] + 1;
    }
    int retVal = candies[len - 1];
    for (int i = len - 2; i >= 0 ; i --) {
        if (ratings[i] > ratings[i + 1] && candies[i] < candies[i + 1] + 1)
            candies[i] = candies[i + 1] + 1;
        retVal += candies[i];
    }
    return retVal;
}

void testCandy(){
    vector<int> ratings = {4,2,3,4,1};
    int ret = candy(ratings);
    cout << ret << endl;
}