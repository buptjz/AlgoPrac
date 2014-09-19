//
//  LongestConsecutiveSequence.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-19.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_search.h"

/*
更新，参考 http://siqi43.wordpress.com/2014/03/13/longest-consecutive-sequence/
 */

int longestConsecutive2(vector<int> &num) {
    if (num.empty()) return 0;
    unordered_set<int> mySet;
    
    for(int e:num)
        mySet.insert(e);
    
    int longest = 1;
    
    for (int e:num) {
        int c = 1;
        int left = e - 1;
        int right = e + 1;
        while (mySet.find(left) != mySet.end()) {
            mySet.erase(left);
            c++;
            left--;
        }
        while (mySet.find(right) != mySet.end()) {
            mySet.erase(right);
            c++;
            right++;
        }
        
        longest = max(longest,c);
    }
    return longest;
}

/*-------------------------原始解法------------------------*/

int longestConsecutive(vector<int> &num) {
    int longest = 1;
    int cur_long = 1;
    int len = (int )num.size();
    
    if (len == 0) return 0;
    
    map<int, int>visited;
    map<int, int>consec;
    
    for (int i = 0; i < len; i++) {
        visited[num[i]] = false;
        consec[num[i]] = 1;
    }
    
    for (int i = 0; i < len; i++) {
        int cur_num = num[i];
        if (visited[cur_num] == true) continue;
        
        cur_long = 1;
        visited[cur_num] = true;
        cur_num++;
        
        while (visited.find(cur_num) != visited.end()) {
            if (visited[cur_num] == true) {
                cur_long += consec[cur_num];
                break;
            }else{
                visited[cur_num] = true;
                cur_long++;
            }
            cur_num++;
        }
        
        consec[num[i]] = cur_long;
        longest  = longest < cur_long ? cur_long : longest;
    }
    return longest;
}

void testLongestConsecutive(){
    
    vector<int> num = {};
    int res = longestConsecutive(num);
    cout<< res << endl;
}


