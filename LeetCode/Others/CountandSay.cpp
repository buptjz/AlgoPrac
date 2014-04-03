//
//  CountandSay.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-3.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/count-and-say/

/*
 这个题目的题干描述不太清楚，http://blog.csdn.net/fightforyourdream/article/details/12901505这里描述的清晰
 */
#include "leetcode_others.h"

string countAndSay(int n) {
    if (n == 0) return string("");
    string last_string,cur_string;
    int prev_index,cur_index;
    int length;
    last_string ="1";
    for (int i = 1; i < n; i++) {
        length = (int)last_string.size();
        cur_index = prev_index = 0;
        while (prev_index < length) {
            if (cur_index == length || last_string[prev_index] != last_string[cur_index]) {
                char no = cur_index - prev_index + '0';
                cur_string += no;
                cur_string += last_string[prev_index];
                prev_index = cur_index;
            }else{
                cur_index++;
            }
        }
        last_string = cur_string;
        cur_string = "";
    }
    return last_string;
}

void testCountAndSay(){
    string res = countAndSay(0);
    cout<< res << endl;
}