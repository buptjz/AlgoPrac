//
//  LetterCombinationsofaPhoneNumber.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-1.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/letter-combinations-of-a-phone-number/

#include "leetcode_permutation.h"

//2014.4.21日改进，用数组代替了很多switch
string candidatesArray[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

static void helper(string &digits,int level,vector<string> &retVec,string &temp){
    if (level == (int) digits.size()) {
        retVec.push_back(temp);
        return;
    }
    string candidates = candidatesArray[digits[level] - '0'];
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
    if (digits.empty()){
        retVec.push_back(temp);
        return retVec;
    }
    helper(digits, 0, retVec, temp);
    return retVec;
}
void testLetterCombinations(){
    vector<string> res = letterCombinations("23");
    printf("Finished\n");
}




