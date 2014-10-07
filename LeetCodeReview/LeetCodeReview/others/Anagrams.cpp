//
//  Anagrams.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-7.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_others.h"

vector<string> anagrams(vector<string> &strs) {
    vector<string> ret;
    map<string, int> dic;
    
    for (int i = 0; i < strs.size(); i++) {
        string s = strs[i];
        
        sort(s.begin(), s.end());
        
        if (dic.find(s) == dic.end()) {
            dic[s] = i;
        }else{
            if (dic[s] == -1) {
                ret.push_back(strs[i]);
            }else{
                ret.push_back(strs[dic[s]]);
                ret.push_back(strs[i]);
                dic[s] = -1;
            }
        }
    }
    return ret;
}
