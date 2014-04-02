//
//  4Sum.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-2.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/4sum/

/*
 【容易疏忽的地方】不去重
 */

#include "leetcode_others.h"

vector<vector<int> > fourSum(vector<int> &num, int target) {
    vector<vector<int> >retVec;
    int start,end;
    int length = (int)num.size();
    sort(num.begin(),num.end());
    for(int i = 0; i < length; i++){
        if(i!=0 && num[i] == num[i-1]) continue;
        for(int j = i + 1; j < length; j++){
            if(j != i+1 && num[j] == num[j-1]) continue;
            int cur_target = target - (num[i] + num[j]);
            start = j + 1;
            end = length - 1;
            while(start < end){
                if(num[start] + num[end] == cur_target){
                    vector<int> temp = {num[i],num[j],num[start],num[end]};
                    if(retVec.empty() ||temp != retVec[retVec.size() - 1])retVec.push_back(temp);
                    start++;
                    end--;
                }else if(num[start] + num[end] > cur_target) end--;
                else start++;
            }
        }
    }
    return retVec;
}