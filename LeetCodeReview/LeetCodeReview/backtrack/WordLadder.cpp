//
//  WordLadder.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-8.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_backtrack.h"

//这个方法超时了
static int ret_len = INT_MAX;

static bool isNext(string a,string b){
    char dic[128] = {0};
    for (int i = 0; i < a.size(); i++) {
        dic[a[i]] += 1;
        dic[b[i]] -= 1;
    }
    int dif_num = 0;
    for (int i = 0; i < 128; i++) {
        if (dic[i] < -1 || dic[i] > 1) return false;
        if (dic[i] == 0) continue;
        dif_num++;
        if (dif_num > 2) return false;
    }
    if(dif_num == 2) return true;
    else return false;
}

static void helper(int len,string last,string end, unordered_set<string> &dict){
    if (len != 0 && isNext(last, end)) {
        ret_len = min(len,ret_len);
        return;
    }
    
    vector<string> candidates;
    unordered_set<string >::iterator it = dict.begin();
    for (; it != dict.end(); it++)
        if (isNext(last, *it)) candidates.push_back(*it);
    
    for (string s : candidates) {
        dict.erase(s);
        helper(len+1, s, end, dict);
        dict.insert(s);
    }
}


int ladderLength(string start, string end, unordered_set<string> &dict) {
    helper(0, start, end, dict);
    if (ret_len == INT_MAX) ret_len = 0;
    
    return ret_len;
}


