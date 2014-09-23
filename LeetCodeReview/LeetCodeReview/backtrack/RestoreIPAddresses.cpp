//
//  RestoreIPAddresses.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-23.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_backtrack.h"

int s_len;

vector<string> generateCandidates(string s,int index){
    vector<string> res;
    if (index == s_len ) return res;
    if (s[index] == '0'){
        res.push_back(s.substr(index,1));
        return res;
    }
    
    //1st
    res.push_back(s.substr(index,1));
    
    //2nd any 2 digits
    if ((index+1) == s_len) return res;
    res.push_back(s.substr(index,2));
    
    //3rd  should be < 255
    if ((index+2) == s_len) return res;
    int num = 100 * (s[index] - '0') + 10 * (s[index+1] - '0') + (s[index+2] - '0');
    if (num <= 255) res.push_back(s.substr(index,3));
    
    return res;
}

void addResult(const vector<string> &cur,vector<string> &res){
    string final;
    
    for (int i = 0; i < (int)cur.size(); i ++) {
        final += cur[i];
        if (i != ((int)cur.size() - 1)) final += ".";
    }
    
    res.push_back(final);
}

void helper(const string s,int index,vector<string>&cur,vector<string> &res){
    if (cur.size() == 4) {
        if (index == s_len)
            addResult(cur, res);
        return;
    }
    if (index == s.length()) return;
    
    vector<string> candis = generateCandidates(s,index);
    for (string c : candis){
        cur.push_back(c);
        helper(s, index + (int)c.length(), cur, res);
        cur.pop_back();
    }
}


vector<string> restoreIpAddresses(string s) {
    s_len = (int)s.length();
    vector<string> cur,res;
    helper(s, 0, cur, res);
    return res;
}

void testRestoreIpAddresses(){
    string s = "0000";
    vector<string>  ss = restoreIpAddresses(s);
}

