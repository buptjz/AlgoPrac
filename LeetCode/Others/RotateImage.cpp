//
//  RotateImage.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-3.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/rotate-image/

/*
 出现的挺频繁的，注意的是几个下标画图画准确！
 */

#include "leetcode_others.h"

void rotate(vector<vector<int> > &matrix) {
    int n = (int)matrix.size();
    for (int i = 0; i < n /2; i++) {
        for (int j = i; j < n-1-i; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[n-1-j][i];
            matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
            matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
            matrix[j][n-1-i] = temp;
        }
    }
}

void testRotate(){
    vector<int> a = {1,2};
    vector<vector<int> > mat(2,a);
    rotate(mat);
    cout<<"Finished"<<endl;
}