//
//  AddBinary.cpp
//  Algorithms
//
//  Created by WangJZ on 14-3-31.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/add-binary/

#include "leetcode_others.h"

string addBinary(string a, string b) {
    string retS;
    char add = 0;
    size_t a_length = a.size();
    size_t b_length = b.size();
    
    for (size_t i = 0; i < max(a_length,b_length) ; i++) {
        char temp = add;
        if (i < a_length) temp += a[a_length - i - 1] - '0';
        if (i < b_length) temp += b[b_length - i - 1] - '0';
        if (temp >= 2) {
            retS += temp + '0' - 2;
            add = 1;
        }else{
            retS += temp + '0';
            add = 0;
        }
    }
    if (add == 1) {
        retS += '1';
    }
    reverse(retS.begin() ,retS.end());
    return retS;
}
void testAddBinary(){
    string a("1010");
    string b("1011");
    string res = addBinary(a, b);
    cout << res<<endl;
    
}