//
//  2Sum.cpp
//  LeetCode
//
//  Created by WangJZ on 14-1-20.
//  http://oj.leetcode.com/problems/two-sum/
//

#include "2Sum.h"
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target) {
    int length = (int)numbers.size();
    vector<int> retVec;
    map<int, int> dic;
    for (int i = 0; i < length; i++) {
        map<int, int>::iterator it = dic.find(target - numbers[i]);
        if (it == dic.end()) {
            dic[numbers[i]] = i + 1;
        }else{
            retVec.push_back((*it).second);
            retVec.push_back(i+1);
            break;
        }
    }
    return retVec;
}


void testTwoSum()
{
    vector<int> input = {0,4,3,1};
    vector<int> ret = twoSum(input, 4);
    printf("finished\n");
}
