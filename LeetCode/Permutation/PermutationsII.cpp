//
//  PermutationsII.cpp
//  Algorithms
//
//  Created by WangJZ on 14-3-20.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_permutation.h"

static void permuteUniqueHelper(int level, vector<int>&num, vector<int>&tmp,
                         vector<vector<int> >&ret, vector<bool>&isVisited,int lenght)
{
    if(level == lenght)
    {
        ret.push_back(tmp);
        return;
    }
    int lastNumber = -6000;
    for(int i = 0; i < num.size(); ++i)
    {
        if(isVisited[i] || num[i] == lastNumber)continue;
        isVisited[i] = true;
        lastNumber = num[i];
        tmp.push_back(num[i]);
        permuteUniqueHelper(level + 1, num, tmp, ret, isVisited,lenght);
        isVisited[i] = false;
        tmp.pop_back();
    }
}

vector<vector<int> > permuteUnique(vector<int> &num)
{
    vector<vector<int> > retVec;
    sort(num.begin(), num.end());
    vector<bool> isVisited(num.size(), false);
    vector<int> tmp;
    int lenght = (int)num.size();

    permuteUniqueHelper(0, num, tmp, retVec, isVisited,lenght);
    return retVec;
}