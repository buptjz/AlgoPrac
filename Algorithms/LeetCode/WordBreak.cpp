//
//  WordBreak.cpp
//  LeetCode
//
//  Created by WangJZ on 3/6/14.
//  Copyright (c) 2014 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/word-break/

/*
 思路：有点像backtrack
 每到一个位置，从能构成的最大单词的字母数开始找，一个向下找到最小的
 过程中isVisited记录某个位置已经找过了。
 */

#include "WordBreak.h"
#include <unordered_set>
#include <vector>
using namespace std;

bool wordBreakHelper(string &s,unordered_set<string> &dict,int position,int max,int min,vector<bool> &isVisited){
    //没到一个新的位置,从最大的能匹配到的，使用backtracking技术
    //记录第x个位置开始是否可以匹配到
    if (position == (int)s.length()) {
        return true;
    }
    if (position+min >(int)s.length()) {
        return false;
    }
    if (isVisited[position]) {
        return false;
    }
    if (max > (int)s.length() - position) {
        max = (int)s.length() - position;
    }
    for (int i = max; i >=min ;i-- ) {
        string curWord =  s.substr(position,i);//从第position个位置开始，取长度是i的字串
        unordered_set<string>::const_iterator got = dict.find(curWord);
        if (got != dict.end()) {//找到了！
            if(wordBreakHelper(s, dict, position+i, max, min, isVisited)){
                return true;
            }else{
                isVisited[position+i] = true;
            }
        }
    }
    return false;
}
bool wordBreak(string s, unordered_set<string> &dict) {
    int max = 0;
    int min = (int)s.length();
    int cur_long;
    
    //找到字典中最大的单词数和最小的单词数
    for ( auto it = dict.begin(); it != dict.end(); ++it ){
        cur_long = (int)(*it).size();
        if (cur_long > max) {
            max = cur_long;
        }
        if (cur_long < min) {
            min = cur_long;
        }
    }
    vector<bool>isVisited = vector<bool>(s.length(),false);
    return wordBreakHelper(s, dict, 0,max,min,isVisited);
}

void testWordBreak(){
    string s = "leetcode";
    unordered_set<string> dict = {"leet","c"};
    bool ret = wordBreak(s, dict);
    printf("Finished\n");
}