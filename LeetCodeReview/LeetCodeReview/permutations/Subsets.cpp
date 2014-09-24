//
//  Subsets.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-24.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_permute.h"


void helper(vector<vector<int>> &res,vector<int> &cur,int index,vector<int> &S){
    res.push_back(cur);
    for (int i = index; i < S.size(); i++) {
        cur.push_back(S[i]);
        helper(res, cur, i+1, S);
        cur.pop_back();
    }
}

vector<vector<int> > subsets(vector<int> &S) {
    vector<vector<int>> res;
    vector<int> cur;
    sort(S.begin(), S.end());
    helper(res,cur,0,S);
    return res;
}