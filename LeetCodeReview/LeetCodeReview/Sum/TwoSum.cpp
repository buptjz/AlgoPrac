//
//  TwoSum.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-2.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_sum.h"

vector<int> twoSum(vector<int> &numbers, int target) {
    vector<int> ans;
    map<int, int> hm;
    for (int i = 0; i < numbers.size() ; i++) {
        map<int, int>::iterator it = hm.find(target - numbers[i]);
        if (it == hm.end()) {
            hm[numbers[i]] = i+1;
        }else{
            ans.push_back((*it).second);
            ans.push_back(i+1);
            break;
        }
    }
    return ans;
}


//这种做法memory limit out了，并且明显不好！因为使用到了O(n)的空间，并且复杂度是O(nlogn)
struct index_data{
    int data;
    int index;
    index_data(int d,int i):data(d),index(i){};
};


bool compare(index_data id1,index_data id2){
    return id1.data <= id2.data;
}


vector<int> twoSumm(vector<int> &numbers, int target) {
    vector<index_data> idV;
    for (int i = 0 ; i < numbers.size(); i++) {
        index_data id(numbers[i],i+1);
        idV.push_back(id);
    }
    sort(idV.begin(), idV.end(), compare);
    
    int start = 0;
    int end = (int)numbers.size() - 1;
    
     vector<int> res;
    while (start < end) {
        if (idV[start].data + idV[end].data < target) {
            start++;
        }else if(idV[start].data + idV[end].data > target){
            end --;
        }else{
            res.push_back(idV[start].index);
            res.push_back(idV[end].index);
        }
    }
    return res;
}

void testTwoSum(){
    vector<int> a = {2,1,3,4,10,6};
    int target = 5;
    twoSum(a, target);
    
}
