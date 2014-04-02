//
//  SubsetsII.cpp
//  LeetCode
//
//  Created by WangJZ on 14-2-21.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/subsets-ii/

/*
 思路：找到所有的subsets，可以分解为：包含0个元素的subsets+包含1个元素的subsets+...+包含n个元素的subsets,所以用一个循环去查找
 当查找包含k个元素的子集的时候，利用了permuteUnique的思想，从level 0递归查找，在每个level分别以level后面的元素作为该level的候选者（这点是与permute不同的，permute可以以level之前的元素作为候选者），为了避免选到重复的候选者，使用一个变量记录我们的前一个候选者！
 
 修正：level指示的是递归的层级，需要用另一个位置来指示从第x位开始，查找，如果我们当前选择了第i位置上得数，进入下一层递归，下一层递归需要从第i+1位之后开始选择候选者！
 */

#include "leetcode_permutation.h"

void subsetsWithCertainNumber(int start,int level,int numberInSet, vector<int>&num, vector<int>&tmp, vector<vector<int> >&ret, vector<bool>&isVisited)
{
    if(level == numberInSet)
    {
        ret.push_back(tmp);
        return;
    }
    int lastNumber = -10000;
    for(int i = start; i < num.size(); ++i)
    {
        if(isVisited[i] || num[i] == lastNumber)continue;
        isVisited[i] = true;
        lastNumber = num[i];
        tmp.push_back(num[i]);
        subsetsWithCertainNumber(i+1,level + 1,numberInSet, num, tmp, ret, isVisited);
        isVisited[i] = false;
        tmp.pop_back();
    }
}

vector<vector<int> > subsetsWithDup(vector<int> &S) {
    vector<vector<int>> retVec;
    sort(S.begin(), S.end());
    for (int i = 0; i < (int)S.size()+1; i++) {//i表示的是包含数字的个数!
        vector<int>tmp;
        vector<bool>isVisited = vector<bool>((int)S.size(),false);
        subsetsWithCertainNumber(0,0, i,S, tmp, retVec, isVisited);
    }
    
    return retVec;
}

void testSubsetsWithDup(){
    vector<int> s = {1,3,3};
    vector<vector<int>> ss = subsetsWithDup(s);
    printf("Finished");
}
