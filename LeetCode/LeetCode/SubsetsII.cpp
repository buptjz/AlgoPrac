//
//  SubsetsII.cpp
//  LeetCode
//
//  Created by WangJZ on 14-2-21.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "SubsetsII.h"
#include <vector>

using namespace std;

void dfs(int level,vector<vector<int>> &retVec,vector<int> &S,vector<bool>index,vector<bool>isUsing){
    if (level == (int)S.size() - 1) {
        vector<int>newVec;
        for (int i = 0; i < S.size(); i++) {
            if (index[i]) {
                newVec.push_back(S[i]);
            }
        }
        retVec.push_back(newVec);
        return;
    }
    //如果上一个节点使用中，本节点就不能使用了
    if (level != 0 && isUsing[level - 1] && S[level -1] == S[level]) {
        //
    }
    
    
}
vector<vector<int> > subsetsWithDup(vector<int> &S) {
    vector<vector<int>> ab;
    return ab;
}