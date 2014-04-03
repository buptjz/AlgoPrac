//
//  PlusOne.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-3.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/plus-one/

//未免太简单。。

#include "leetcode_others.h"

vector<int> plusOne(vector<int> &digits) {
    vector<int > retVec(digits);
    if (digits.size() == 0) return vector<int>(1,1);
    int add = 1;
    for (int i = (int)digits.size() - 1; i >= 0; i--) {
        retVec[i] += 1;
        if (retVec[i] >= 10) {
            retVec[i] -= 10;
            add = 1;
        }else{
            add = 0;
            break;
        }
    }
    if (add == 1) {
        retVec.insert(retVec.begin(), 1);
    }
    return retVec;
}

void testPlusOne(){
    vector<int> x = {};
    vector<int> res = plusOne(x);
    cout<<"Finished"<<endl;
}