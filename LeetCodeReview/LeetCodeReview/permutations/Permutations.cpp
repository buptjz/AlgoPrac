//
//  Permutations.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-25.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_permute.h"

void helper(const vector<int> &num,vector<vector<int>> &result,vector<int> &cur,vector<bool> &visited){
    if (cur.size() == num.size()) {
        result.push_back(cur);
        return;
    }
    
    for (uint i = 0; i < num.size(); i++) {
        if (visited[i]) continue;
        cur.push_back(num[i]);
        visited[i] = true;
        helper(num, result, cur, visited);
        visited[i] = false;
        cur.pop_back();
    }
    
}
vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int>> res;
    vector<int> cur;
    vector<bool> visited(num.size(),false);
    helper(num, res, cur, visited);
    return res;
}