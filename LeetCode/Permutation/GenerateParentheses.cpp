//
//  GenerateParentheses.cpp
//  Algorithms
//
//  Created by WangJZ on 14-3-31.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_permutation.h"

void generateParenthesisHelper(int left,int right,int numbersOfLeft,
                                         vector<bool>&temp,vector<string>&retVec)
{
    if (left + right == 0) {
        string ans;
        for (size_t i = 0; i < temp.size(); i++) {
            ans += temp[i] ? '(' : ')';
        }
        retVec.push_back(ans);
        return;
    }
    if (left > 0) {
        temp.push_back(true);
        generateParenthesisHelper(left-1,right,numbersOfLeft+1,temp,retVec);
        temp.pop_back();
    }
    if (right > 0 && numbersOfLeft > 0) {
        temp.push_back(false);
        generateParenthesisHelper(left,right-1,numbersOfLeft-1,temp,retVec);
        temp.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    vector<string>retVec;
    vector<bool> temp;
    if (n == 0) return retVec;
    generateParenthesisHelper(n, n, 0, temp, retVec);
    return retVec;
}

void testGenerateParenthesis(){
    vector<string>res = generateParenthesis(0);
    printf("finished\n");
}

