//
//  PermutationsII.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-24.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_permute.h"

void helper(vector<vector<int>> &res,vector<int> &cur,vector<bool> &visited,vector<int> &num){
    if (cur.size() == num.size())
        res.push_back(cur);
    
    int lastIndex = -1;
    for (int i = 0; i < num.size(); i++) {
        if (visited[i]) continue;
        if (lastIndex != -1 && num[i] == num[lastIndex]) continue;
        cur.push_back(num[i]);
        visited[i] = true;
        helper(res, cur, visited, num);
        visited[i] = false;
        cur.pop_back();
        lastIndex = i;
    }
}

vector<vector<int> > permuteUnique(vector<int> &num) {
    int len = (int)num.size();
    
    vector<vector<int>> res;
    if (len == 0) return res;
    
    vector<int> cur;
    vector<bool> visited(len,false);
    sort(num.begin(), num.end());
    
    helper(res,cur,visited,num);
    return res;
}
