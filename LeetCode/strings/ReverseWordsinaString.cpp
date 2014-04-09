//
//  ReverseWordsinaString.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-7.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/reverse-words-in-a-string/

/*
 这个方法没有问题，用到了一个额外的数组
 如果需要原地进行，可以用如下这个技巧：
 
 原字符串是“i like this program very much”
 1) Reverse the individual words, we get the below string.
 "i ekil siht margorp yrev hcum"
 2) Reverse the whole string from start to end and you get the desired output.
 "much very program this like i"
 ref：http://www.geeksforgeeks.org/reverse-words-in-a-given-string/
 
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
