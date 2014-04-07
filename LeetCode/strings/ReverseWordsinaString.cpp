//
//  ReverseWordsinaString.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-7.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/reverse-words-in-a-string/

/*
 苦练基本功，细心+复盘
 */

#include "leetcode_string.h"

void reverseWords(string &s) {
    if (s.size() == 0) return;
    vector<string>ret;
    int start = -1;
    for (int i = 0; i < s.size(); i++) {
        if (start == -1) {//case 1 : no start yet
            if(s[i] == ' ') continue;
            else start = i;
        }else{//case 2 : start yet
            if (s[i] != ' ') continue;
            else{
                ret.push_back(s.substr(start,i-start));
                start = -1;
            }
        }
    }
    if (start != -1) ret.push_back(s.substr(start,s.size() - start));
    if (ret.size() == 0) {
        s = "";
        return;
    }
    s = ret[ret.size() - 1];
    
    for (int i = (int)ret.size() - 2; i >= 0; i--) {
        s = s + " " + ret[i];
    }
}

void testReverseWords(){
    string s("a   ");
    reverseWords(s);
    cout<<s<<endl;
}
