//
//  PalindromePartitioning.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-6.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/palindrome-partitioning/

#include "leetcode_dp.h"
vector<vector<string> > ret;
static vector<string> temp;
vector<vector<bool> > table;
string str;
int length;
static vector<vector<bool> > getState(const string &s) {
    vector<vector<bool>> state(length,vector<bool>(length,false));
    for (int step = 0; step < length; step++) {
        for (int i = 0; i < length - step; i++) {
            switch (step) {
                case 0:
                    state[i][step+i] = true;
                    break;
                case 1:
                    state[i][step+i] = s[i]==s[step+i];
                    break;
                default:
                    if(state[i+1][step+i-1] && s[i] == s[step+i])
                        state[i][step+i] = true;
                    break;
            }
        }
    }
    return state;
}


static void partitionHelper(int start){
    if (start == length) {
        ret.push_back(temp);
        return;
    }
    //Find all candidates
    for (int i = start; i < length; i++) {
        if (table[start][i]) {
            temp.push_back(str.substr(start,i-start+1));//make_move
            partitionHelper(i+1);
            temp.pop_back();//unmake_move
        }
    }
}
static vector<vector<string>> partition(string s) {
    length = (int)s.size();
    table = getState(s);
    str = s;
    partitionHelper(0);
    return ret;
}

void testPP(){
    vector<vector<string> >res = partition("aabbb");
    cout<<"Finished"<<endl;
}

