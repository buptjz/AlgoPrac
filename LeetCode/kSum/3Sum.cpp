//
//  3Sum.cpp
//  Algorithms
//
//  Created by WangJZ on 14-3-25.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/3sum/

#include "leetcode_others.h"

vector<vector<int> > threeSum(vector<int> &num) {
    vector<vector<int> > retVec;
    int start,end,cur = 0,target;
    int last = (int)num.size() - 1;
    sort(num.begin(), num.end());
    
    for (int i = 0; i <= last; i++) {
        if (i != 0 && num[cur] == num[i]) continue;//如果当前选中的元素和上一次选中的元素重复，则不做处理
        cur = i;
        start = cur+1;
        end = last;
        target = 0 - num[cur];
        while (start < end) {
            if (num[start] + num[end] == target) {
                vector<int> temp = {num[cur],num[start],num[end]};
                if (retVec.empty() || retVec[retVec.size() - 1] != temp) retVec.push_back(temp);
                start++;
                end--;
            }else if(num[start] + num[end] < target){
                start++;
            }else{
                end--;
            }
        }
    }
    return retVec;
}

void testThreeSum(){
    vector<int > temp= {-1,-1,-1,2,2};
    vector<vector<int> >  res = threeSum(temp);
    printf("Finished\n");
}