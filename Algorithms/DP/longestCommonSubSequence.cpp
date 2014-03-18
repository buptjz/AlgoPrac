//
//  longestSubSequence.cpp
//  LeetCode
//
//  Created by WangJZ on 14-3-15.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

/*
 
 经典算法之 最长公共子序列
 
 使用DP
 
 递归的推倒公式
 
            = c[i-1,j-1]+1                      当s1[i]==s2[j]
 c[i,j]     = max(c[i-1,j],c[i,j-1])            其它情况
 
 
 用一个数组记录方向：1）→为1，↑为2，↗为3
 
 */

#include "longestCommonSubSequence.h"
#include <string>
#include <vector>

using namespace std;

void construct_sequence(vector<vector<int>>&state,
                       vector<vector<int>>&dir,
                       string &s1,
                       string &retString,
                       int i,
                       int j)
{
    if (dir[i][j] == 3) {
        retString += s1[i - 1];
        construct_sequence(state, dir, s1, retString, i - 1, j - 1);
    }else if(dir[i][j] == 2){
        construct_sequence(state, dir, s1, retString, i - 1, j);
    }else if(dir[i][j] == 1){
        construct_sequence(state, dir, s1, retString, i, j - 1);
    }else{//走到了尽头
        return;
    }

}

string longestCommonSubSequence(string s1,string s2){
    int l1 = (int)s1.length();
    int l2 = (int)s2.length();
    vector<vector<int>> state,dir;
    for (int i = 0; i <= l1; i++) {//初始化状态矩阵和方向矩阵
        vector<int> temp1 = vector<int>(l2+1,0);
        vector<int> temp2 = vector<int>(l2+1,0);
        state.push_back(temp1);
        dir.push_back(temp2);
    }
    
    //主体，自底向上依次得到每一个位置的值
    for (int i = 1;i <= l1 ; i++) {
        for (int j = 1; j <= l2; j++) {
            if (s1[i - 1] == s2[j - 1]) {//情况一，相等
                dir[i][j] = 3;
                state[i][j] = state[i - 1][j - 1] + 1;
            }else if(state[i - 1][j] > state[i][j - 1]){//情况二：不等，下方>左侧
                dir[i][j] = 2;
                state[i][j] = state[i-1][j];
            }else{//情况二：不等，左侧>下方
                dir[i][j] = 1;
                state[i][j] = state[i][j-1];
            }
        }
    }
    string retS;
    construct_sequence(state,dir,s1,retS,l1,l2);
    reverse(retS.begin(), retS.end());
    return retS;
}

void testLongestCommonSubSequence(){
    string s = "abcdefg";
    string s2 = "acdf";
    string res = longestCommonSubSequence(s, s2);
    cout << res <<endl;
}
