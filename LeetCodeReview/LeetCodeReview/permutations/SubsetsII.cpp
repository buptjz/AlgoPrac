//
//  SubsetsII.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-23.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_permute.h"

void helper(vector<vector<int>> &result,vector<int> &tmp,int index,const vector<int> &S){
    result.push_back(tmp);
    
    for (int i = index; i < S.size(); i++) {
        if (i != index && S[i] == S[i-1]) continue;
        tmp.push_back(S[i]);
        helper(result, tmp, i + 1, S);
        tmp.pop_back();
    }
}


vector<vector<int> > subsetsWithDup(vector<int> &S) {
    sort(S.begin(), S.end());
    vector<vector<int>> res;
    vector<int> cur;
    helper(res,cur,0,S);
    return res;
}
