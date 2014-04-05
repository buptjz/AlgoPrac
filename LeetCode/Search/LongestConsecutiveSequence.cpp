//
//  LongestConsecutiveSequence.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-5.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/longest-consecutive-sequence/

/*
使用了map记录信息，不知道算不算违规
*/

#include "leetcode_others.h"


int longestConsecutive(vector<int> &num) {
    if (num.size() == 0) return 0;
    map<int, bool> dic;
    for (int i = 0; i < num.size(); i++) {
        dic[num[i]] = false;
    }
    int max_consec = 1;
    for (map<int, bool>::iterator it = dic.begin(); it != dic.end(); it++) {
        if (dic[it->first] == true)
            continue;//searched thie one before
        //search previous ones
        int count = 1;
        map<int, bool>::iterator temp = it;
        while (true) {
            int prev = temp->first - 1;// prev = key - 1(3 = 4 - 1)
            temp = dic.find(prev);
            if (temp == dic.end()) break;//one more prev
            dic[temp->first] = true;//set flag  "searched"
            count += 1;
        }
        //search next ones
        temp = it;
        while (true) {
            int next = temp->first + 1;// next = key + 1(5 = 4 + 1)
            temp = dic.find(next);
            if (temp == dic.end()) break;//one more prev
            dic[temp->first] = true;//set flag  "searched"
            count += 1;
        }
        max_consec = max(max_consec,count);
    }
    return max_consec;
}

void testLongestConsecutive(){
    vector<int > a = {300,200,2,3,1,5};
    int res = longestConsecutive(a);
    cout<<res<<endl;
}
