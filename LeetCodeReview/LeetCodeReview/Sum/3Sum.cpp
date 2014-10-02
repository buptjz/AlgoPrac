//
//  3Sum.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-2.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_sum.h"

vector<vector<int> > threeSum(vector<int> &num) {
    int len = (int) num.size();
    vector<vector<int>> res;
    sort(num.begin(),num.end());
    for (int i = 0; i < len; i++) {
        if (i != 0 && num[i] == num[i-1]) continue;
        int start = i + 1;
        int end = len - 1;
        while (start < end) {
            if (num[i] + num[start] + num[end] < 0) start++;
            else if(num[i] + num[start] + num[end] > 0) end--;
            else{
                vector<int>tmp = {num[i],num[start],num[end]};
                if (res.empty() || tmp != res[res.size() - 1]) res.push_back(tmp);
                start++;
                end--;
            }
        }
    }
    return res;
}
