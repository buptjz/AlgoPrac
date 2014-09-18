//
//  WordBreak.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-18.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  https://oj.leetcode.com/problems/word-break/

#include "leetcode_backtrack.h"

static int maxL,minL;

static bool helper(const string s,int index,const unordered_set<string> &dict,vector<bool> &visited){
    for (int len = minL; len <= maxL && index+len <= s.length(); len ++) {
        int end = index + len - 1;
        if (visited[end + 1]) continue;
        if (dict.find(s.substr(index,len)) != dict.end()) {
            if (end == s.length()-1) return true;
            if( helper(s, end + 1, dict, visited))
                return true;
            else
                visited[index + len - 1] = true;
        }
    }
    return false;
}

bool wordBreak(string s, unordered_set<string> &dict) {
    if (s.length() == 0) return true;
    
    //记录当前节点是否遍历过
    vector<bool> visited = vector<bool>(s.length()+1,false);
    
    //找到最长单词长度 最短单词长度
    unordered_set<string>::iterator it = dict.begin();
    int tmp;
    maxL = 0;
    minL = (int)s.length();
    for (; it != dict.end(); it++) {
        tmp = (int)(*it).length();
        maxL = tmp > maxL ? tmp : maxL;
        minL = tmp < minL ? tmp : minL;
    }
    return helper(s,0,dict,visited);
    
}

void testWordBreak(){
    unordered_set<string> dict;
    dict.insert("lee");
    dict.insert("code");
    string s = "leetcode";
    cout<<wordBreak(s, dict);
    
}