//
//  LongestConsecutiveSequence.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-5.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/longest-consecutive-sequence/

#include "leetcode_others.h"
#include <unordered_set>
//2014.4.9日更新，使用了unorder_set
int longestConsecutive(vector<int> &num) {
    if (num.size() == 0) return 0;
    unordered_set<int> table;
    
    for (int i = 0; i < num.size(); i++)
        table.insert(num[i]);
    
    int max_consec = 1;
    for (int e : num){
        int count = 1;
        int left = e - 1,right = e + 1;
        while (table.find(left) != table.end()){
            count++;
            table.erase(left);
            left--;
        }
        while (table.find(right) != table.end()){
            count++;
            table.erase(right);
            right++;
        }
        max_consec = max(max_consec,count);
    }
    return max_consec;
}

/*
使用了map记录信息，不知道算不算违规
*/



int longestConsecutive2(vector<int> &num) {
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
    vector<int > a = {1,0,-1};
    int res = longestConsecutive(a);
    cout<<res<<endl;
}
