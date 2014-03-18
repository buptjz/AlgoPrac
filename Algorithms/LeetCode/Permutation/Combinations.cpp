//
//  Combinations.cpp
//  LeetCode
//
//  Created by WangJZ on 14-2-22.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "Combinations.h"
#include <vector>

using namespace std;


void combineHelper(int start,int k,int n,vector<vector<int>> &retVec,vector<int> &tmp){
    if ((int)tmp.size() == k) {
        retVec.push_back(tmp);
        return;
    }
    for (int i = start; i < n+1; i++) {
        tmp.push_back(i);
        combineHelper(i+1, k,n, retVec,tmp);
        tmp.pop_back();
    }

}
vector<vector<int> > combine(int n, int k) {
    vector<vector<int>> retVec;
    vector<int> tmp;
    combineHelper(1,k,n,retVec,tmp);
    return retVec;
}

void testCombine(){
    vector<vector<int>> retVec;
    retVec = combine(4, 2);
    printf("Finished");
}