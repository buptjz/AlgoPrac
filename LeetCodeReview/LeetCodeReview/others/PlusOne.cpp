//
//  PlusOne.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-2.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_others.h"

vector<int> plusOne(vector<int> &digits) {
    int len = (int) digits.size();
    int index = len - 1;
    for (; index >= 0; index--)
        if (digits[index] != 9)
            break;
    
    if (index == -1) {
        vector<int> res(len+1,0);
        res[0] = 1;
        return res;
    }else{
        vector<int> res(len,0);
        for (int i = 0; i < index; i++) {
            res[i] = digits[i];
        }
        res[index] = digits[index] + 1;
        return res;
    }
}

void testPlusOne(){
    vector<int> a = {};
    vector<int> ans = plusOne(a);
    cout << "yes"<<endl;
}


