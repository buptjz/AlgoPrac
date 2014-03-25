//
//  WordBreak.cpp
//  LeetCode
//
//  Created by WangJZ on 3/6/14.
//  Copyright (c) 2014 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/word-break/

#include "leetcode_string.h"
/*
-----------------2014.3.25更新-----------------
 采用动态规划的思想，从前往后找，dp[]是一个数组，记录的是是否能够走到第i个位置上
 比如说leetcode和['le','leet']
 dp[1] = 0;表示第一个位置l是找不到的，
 dp[2] = 1;表示第2个位置能够走到(因为有le)

 dp[i] = true的条件是：存在任意一个j<i,dp[j]是true，并且s[j,i]这个子串在字典中有。
 
 【注】这个思路更简洁，比下面的回溯法更清晰
 */

bool wordBreaku(string s, unordered_set<string> &dict) {
    int length = (int)s.length();
    vector<bool> dp = vector<bool>(length+1,false);
    dp[0] = true;
    for (int i = 1; i <= length; i++) {
        for (int j = i-1; j >= 0; j--) {
            if (dp[j] == false) continue;//本位置不能查找
            string temp = string(s.begin()+j,s.begin()+i);
            if (dict.find(temp)!= dict.end()){//如果找到了
                dp[i] = true;
                break;
            }
        }
    }
    return dp[length];
}
/*
 思路：有点像backtrack
 每到一个位置，从能构成的最大单词的字母数开始找，一个向下找到最小的
 过程中isVisited记录某个位置已经找过了。
 */

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
    unordered_set<string> dict = {"leet","code"};
    bool ret = wordBreaku(s, dict);
    printf("Finishe %d\n",ret);
}