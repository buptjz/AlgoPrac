//
//  WordBreakII.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-18.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  https://oj.leetcode.com/problems/word-break-ii/

#include "leetcode_backtrack.h"


static int maxL,minL;

static void dealSuccess(vector<string> &retString,vector<string> &cur){
    string s;
    for (int i = 0; i < cur.size(); i++) {
        s += cur[i];
        if (i != cur.size() - 1) {
            s += " ";
        }
    }
    retString.push_back(s);
}

static bool helper(const string s,int index,const unordered_set<string> &dict,vector<bool> &visited,vector<string> &retString,vector<string> &cur){
    if (index == s.length()) {
        dealSuccess(retString,cur);
        return true;
    }
    
    bool success = false;
    int total_length  = (int)s.length();
    for (int len = minL; len <= maxL && index+len <= total_length; len ++) {
        int end = index + len - 1;
        if (visited[end + 1]) continue;
        if (dict.find(s.substr(index,len)) != dict.end()) {
            cur.push_back(s.substr(index,len));//make move
            
            if( helper(s, end + 1, dict, visited,retString,cur))
                success = true;
            else
                visited[end + 1] = true;
            cur.pop_back(); //unmove
        }
    }
    return success;
}

vector<string> wordBreakII(string s, unordered_set<string> &dict) {
    vector<string> retString;
    vector<string> cur;
    if (s.length() == 0) return retString;
    
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
    helper(s,0,dict,visited,retString,cur);
    return retString;
}


void testWordBreakII(){
    unordered_set<string> dict;
    dict.insert("aaaa");
    dict.insert("aaa");
    dict.insert("aa");
//    dict.insert("code");
    string s = "aaaaaaaa";
    vector<string> ret = wordBreakII(s, dict);
    cout<<"Finished"<<endl;
}

