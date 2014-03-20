//
//  Permutations.cpp
//  LeetCode
//
//  Created by WangJZ on 14-1-25.
//  http://oj.leetcode.com/problems/permutations/
//

#include "leetcode_permutation.h"

void permuteHelper(vector<vector<int> >&retVec,vector<int> &num,vector<int> &temp,vector<bool> &isVisited){
    size_t currentLength = temp.size();
    size_t totalLength = num.size();
    if (currentLength == totalLength) {
        retVec.push_back(temp);
        return;
    }
    for (int i = 0; i < totalLength; i++) {
        if (isVisited[i]) {
            continue;
        }
        temp.push_back(num[i]);
        isVisited[i] = true;
        permuteHelper(retVec, num, temp,isVisited);
        temp.pop_back();
        isVisited[i] = false;
    }
}

vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int> > retVec;
    vector<int> temp;
    vector<bool> isVisited = vector<bool>(num.size(),false);
    permuteHelper(retVec, num, temp,isVisited);
    return retVec;
}

void testPermute(){
    vector<int> num = {1,2,3};
    vector<vector<int>> ret = permute(num);
    printf("Finished\n");
}