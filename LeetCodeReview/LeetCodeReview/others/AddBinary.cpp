//
//  AddBinary.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-4.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_others.h"

string addBinary(string a, string b) {
    int len_a = (int)a.size();
    int len_b = (int)b.size();
    if (len_a == 0) return b;
    if (len_b == 0) return a;
    
    int a_end = len_a - 1;
    int b_end = len_b - 1;
    
    string res;
    int last = 0;
    while (a_end >=0 || b_end >=0) {
        int cur = last;
        if (a_end >= 0) cur += (a[a_end] - '0');
        if (b_end >= 0) cur += (b[b_end] - '0');
        if (cur == 2) {
            last = 1;
            res = "0" + res;
        }else if(cur == 3){
            last = 1;
            res = "1" + res;
        }else if(cur == 1){
            last = 0;
            res = "1" + res;
        }else{
            last = 0;
            res = "0" + res;
        }
        a_end--;
        b_end--;
    }
    if (last == 1) res = "1" + res;
    return res;
}

void testAddBinary(){
    string a = "1101";
    string b = "10";
    string res = addBinary(a, b);
    cout << res << endl;
}




