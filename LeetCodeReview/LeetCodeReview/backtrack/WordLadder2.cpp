//
//  WordLadder2.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-8.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_backtrack.h"

vector<string> getCandidates(string s, unordered_set<string> &dict){
    vector<string> ret;
    for (int i = 0; i < s.length(); i++) {
        char tmp = s[i];
        for (char alpha = 'a'; alpha <='z'; alpha++) {
            s[i] = alpha;
            unordered_set<string> ::iterator it = dict.find(s);
            if (it != dict.end()) {
                ret.push_back(*it);
                dict.erase(it);
            }
        }
        s[i] = tmp;
    }
    return ret;
}

int ladderLength(string start, string end, unordered_set<string> &dict) {
    dict.insert(end);
    vector<string> currentLevel,lastLevel;
    currentLevel.push_back(start);
    int retVal = 1;
    while (!currentLevel.empty()) {
        lastLevel = currentLevel;
        currentLevel.clear();
        for (string s : lastLevel) {
            if (s == end) return retVal;
            vector<string > tmp = getCandidates(s,dict);
            currentLevel.insert(currentLevel.end(),tmp.begin(), tmp.end());
        }
        retVal++;
    }
    return 0;
}
