//
//  RestoreIPAddresses.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-3.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/restore-ip-addresses/

/*
 使用正常的回溯法即可，因为IP地址不算很长，不太用考虑prune的问题
    难点在于判断 一段ip地址<255 上
 */

#include "leetcode_others.h"

vector<string>retVec;//{"255.255.11.135", "255.255.111.35"}
vector<string>temp;//{"255","255","11"}
string target;

vector<string>generateCandidate(int index){
    vector<string> retVec;
    if (index == target.size()) return retVec;
    retVec.push_back(string(1,target[index]));
    
    if(target[index] == '0') return retVec;
    if (index+1 < target.size()) retVec.push_back(string(1,target[index]) + string(1,target[index+1]));
    if (index+2 < target.size()){
        if (target[index] == '1' ||
            (target[index] == '2' && target[index+1] <= '4') ||
            (target[index] == '2' && target[index+1] == '5' && target[index + 2] <='5'))
            retVec.push_back(string(1,target[index]) + string(1,target[index+1]) + string(1,target[index+2]));
    }
    return retVec;
}
static void backtrack(int index){
    if (index == target.size() || temp.size() == 4) {
        if (index == target.size() && temp.size() == 4)
            retVec.push_back(temp[0] +"."+ temp[1] +"."+ temp[2] +"."+ temp[3]);
        return;
    }
    vector<string>candidates = generateCandidate(index);
    for (int i = 0; i < candidates.size(); i++) {
        temp.push_back(candidates[i]);
        backtrack(index+(int)candidates[i].size());
        temp.pop_back();
    }
    
}

vector<string> restoreIpAddresses(string s) {
    target = s;
    backtrack(0);
    return retVec;
}

void testRestoreIpaddresses(){
    vector<string> res = restoreIpAddresses("172162541");
    printf("Finished\n");
}
