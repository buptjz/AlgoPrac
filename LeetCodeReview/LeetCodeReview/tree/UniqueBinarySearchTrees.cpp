//
//  UniqueBinarySearchTrees.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-22.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_tree.h"


//需要注意的是，使用vector<int> nTrees(n+1,-1);

int helper(int n,vector<int> &table){
    if (table[n] != -1) return table[n];
    int accum = 0;
    for (int i = 0; i < n; i++)
        accum += helper(i, table) * helper(n - 1 - i, table);
    table[n] = accum;
    return accum;
}

int numTrees(int n) {
    if (n == 0) return 0;
    vector<int> nTrees(n+1,-1);
    nTrees[0] = 1;
    nTrees[1] = 1;
    return helper(n, nTrees);
}

void testNumTrees(){
    int n = 3;
    int res = numTrees(n);
    cout << res <<endl;
}
