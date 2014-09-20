//
//  Triangle.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-20.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  https://oj.leetcode.com/problems/triangle/

#include "leetcode_backtrack.h"


int minimumTotal(vector<vector<int> > &triangle) {
    int length = (int)triangle.size();
    if (length == 0) return 0;
    if (length == 1) return triangle[0][0];
    
    vector<int> result(triangle[length -1]);
    for (int layer = length - 2; layer >= 0 ; layer--) {
        for (int i = 0; i <= layer; i++) {
            result[i] = min(result[i],result[i+1]) + triangle[layer][i];
        }
    }
    return result[0];
}

void testMinimumTotal(){
    vector<vector<int>> tmp;
    vector<int> a1 = {-1};
    vector<int> a2 = {2,3};
    vector<int> a3 = {1,-1,-3};
    
    tmp.push_back(a1);
    tmp.push_back(a2);
    tmp.push_back(a3);
    cout << minimumTotal(tmp)<<endl;
    
}
////回溯法 超时！
//int min_path_length = INT_MAX;
//int total_layers;
//
//static void backtrack(int cur_length,const vector<vector<int>> &triangle,int layer,int index){
//    if (layer == total_layers) {
//        min_path_length = min(min_path_length,cur_length);
//        return;
//    }
//    vector<int> cur_layer = triangle[layer];
//    
//    for (int i = index; i <= index + 1; i++) {
//        int tmp_length = cur_length + cur_layer[i];
//        backtrack(tmp_length, triangle, layer + 1, i);
//    }
//}
//
//int minimumTotal(vector<vector<int> > &triangle) {
//    total_layers = (int)triangle.size();
//    backtrack(0, triangle, 0, 0);
//    return min_path_length;
//}
