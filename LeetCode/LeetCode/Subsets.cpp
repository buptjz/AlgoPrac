//
//  Subsets.cpp
//  LeetCode
//
//  Created by WangJZ on 14-2-21.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/subsets/

/*
 例举一个几何的全部子集，使用回溯法，注意复原操作！
 */

#include "Subsets.h"
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &retVec,vector<int> &S,vector<bool> &index){
    if (index.size() == S.size()) {
        vector<int> newVec;
        for (int i = 0; i < (int)S.size(); i++) {
            if (index[i]) {
                newVec.push_back(S[i]);
            }
        }
        retVec.push_back(newVec);
        return;
    }
    //先改变，递归，再复原！这是回溯法的精髓！这里相当于回溯法找到candidate是[0,1]然后用for循环遍历每一个candidate
    index.push_back(true);
    dfs(retVec,S,index);
    index.pop_back();
    
    index.push_back(false);
    dfs(retVec,S,index);
    index.pop_back();
}

vector<vector<int> > subsets(vector<int> &S) {
    vector<vector<int>> retVec;
    vector<bool>index;
    sort(S.begin(), S.end());
    dfs(retVec,S,index);
    return retVec;
}

void testSubsets(){
    vector<int> s = {1,2,3};
    vector<vector<int>> ss = subsets(s);
    printf("Finished");
}