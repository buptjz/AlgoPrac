//
//  Combinations.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-1.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_permute.h"

void combineHeler(vector<vector<int>> &result,int cur,int n,int k,vector<int> &curVec){
    if (curVec.size() == k) {
        result.push_back(curVec);
        return;
    }
    
    for (int i = cur; i <= n; i++) {
        curVec.push_back(i);
        combineHeler(result,i+1,n,k,curVec);
        curVec.pop_back();
    }
}

vector<vector<int> > combine(int n, int k) {
    vector<vector<int>> result;
    if (k == 0) return result;
    vector<int> curVec;
    combineHeler(result,1,n,k,curVec);
    return result;
}

void testCombine(){
    vector<vector<int>> ans = combine(4, 2);
    cout<<"yes"<<endl;
}


