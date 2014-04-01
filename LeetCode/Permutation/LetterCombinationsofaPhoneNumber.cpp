//
//  LetterCombinationsofaPhoneNumber.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-1.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/letter-combinations-of-a-phone-number/

#include "leetcode_permutation.h"

static string getCandidates(char number){
    string retString;
    switch (number) {
        case '2':
            retString = "abc";
            break;
        case '3':
            retString = "def";
            break;
        case '4':
            retString = "ghi";
            break;
        case '5':
            retString = "jkl";
            break;
        case '6':
            retString = "mno";
            break;
        case '7':
            retString = "pqrs";
            break;
        case '8':
            retString = "tuv";
            break;
        case '9':
            retString = "wxyz";
            break;
            
        default:
            break;
    }
    return retString;
}
static void helper(string &digits,int level,vector<string> &retVec,string &temp){
    if (level == (int) digits.size()) {
        retVec.push_back(temp);
        return;
    }
    string candidates = getCandidates(digits[level]);
    level++;
    for (int i = 0; i < (int)candidates.size(); i++) {
        temp += candidates[i];
        helper(digits, level, retVec, temp);
        temp.erase(temp.end()-1);
    }
}
vector<string> letterCombinations(string digits) {
    string temp;
    vector<string>retVec;
    if (digits.empty()) return retVec;
    helper(digits, 0, retVec, temp);
    return retVec;
}
void testLetterCombinations(){
    vector<string> res = letterCombinations("23");
    printf("Finished\n");
}




