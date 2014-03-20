//
//  CombinationSum.cpp
//  LeetCode
//
//  Created by WangJZ on 14-2-22.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/combination-sum/
//http://oj.leetcode.com/problems/combination-sum-ii/

/*
 【思路】依然使用回溯法，分别使用第x个candidate做为第一个位置上得数，对于第一个位置上是第i个候选者的阶段，使用i（包括i/不包括）后面的数作为该阶段的候选者。
 上面包括和不包括就是两道题了，分别是1）一个元素能使用多次，2）一个元素只能使用一次。
 */

#include "leetcode_permutation.h"


int sum(vector<int> &tmp){
    int total = 0;
    for (int i = 0; i < (int)tmp.size(); i++) {
        total += tmp[i];
    }
    return total;
}

void combinationSumHelper(vector<vector<int>> &retVec,vector<int> &candidates,int target,vector<int> &tmp,int start){
    int total = sum(tmp);
    if (total >= target) {//找到了符合要求的数组,或者已经超出要求的值
        if (total == target) {
            retVec.push_back(tmp);
        }
        return;
    }
    int lastNumber = -10000;
    for (int i = start; i < (int)candidates.size(); i++) {
        if (lastNumber == candidates[i]) continue;//如果上一个候选者和本候选者相同，那么跳过本次递归
        tmp.push_back(candidates[i]);
//        combinationSumHelper(retVec, candidates, target, tmp, i);//【题目一】下一个候选者从i（包括i）之后的candidates开始选择
        combinationSumHelper(retVec, candidates, target, tmp, i+1);//【题目二】下一个候选者从i（不包括i）之后的candidates开始选择
        lastNumber = candidates[i];
        tmp.pop_back();
    }
}
vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> retVec;
    vector<int>tmp;
    sort(candidates.begin(), candidates.end());
    combinationSumHelper(retVec,candidates,target,tmp,0);
    return retVec;
}

void testCombinationSum(){
    vector<vector<int>> retVec;
    vector<int> candidate = {10,1,2,7,6,1,5};
    int target = 8;
    retVec = combinationSum(candidate, target);
    printf("Finished");
}
