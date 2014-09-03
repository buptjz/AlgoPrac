//
//  longestCommonSubstring.cpp
//  Algorithms
//
//  Created by WangJZ on 14-3-18.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

/*
 
 经典算法之 最长公共子串
 
 使用DP
 
 递归的推倒公式
 
            = c[i-1,j-1]+1                      当s1[i]==s2[j]
 c[i,j]     = 0                                 其它情况
 
 
 用一个Index来记录当前最大值在s1中的位置
 
 从递推公式能够看出来，公共子串比最长公共子序列要简单一些
 
 */

#include "longestCommonSubstring.h"
#include <string>
#include <vector>

using namespace std;
string longestCommonSubstring(string s1,string s2){
    int max = 0;//记录当前找到的最长公共子串的长度
    int maxIndex = 0;//记录当前找到的最长公共子串在s1中的位置（结束位置）
    string retString;//返回值
    int s1_length = (int)s1.length();
    int s2_length = (int)s2.length();
    if (s1_length == 0 || s2_length == 0) return retString;
    vector<vector<int>> state;//记录DP过程的状态
    
    for (int i = 0; i <= s2_length; i++) {
        vector<int> temp = vector<int>(s1_length+1,0);
        state.push_back(temp);
    }
    
    for (int i = 1; i <= s2_length; i ++) {
        for (int j = 1; j <= s1_length; j++) {
            if (s1[j-1] == s2[i-1]) {
                if ((state[i][j] = state[i-1][j-1]+1) > max) {
                    max = state[i][j];
                    maxIndex = j - 1;
                }
            }else{
                state[i][j] = 0;
            }
            
        }
    }
    while (max > 0) {
        retString += s1[maxIndex--];
        max--;
    }
    reverse(retString.begin(), retString.end());
    return retString;
}

void testLongestCommonSubstring(){
    string s1 = "abbdefg";
    string s2 = " bbd";
    string res = longestCommonSubstring(s1, s2);
    cout << res << endl;œœœ
}