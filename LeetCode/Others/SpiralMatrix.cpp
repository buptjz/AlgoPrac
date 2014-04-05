//
//  SpiralMatrix.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-5.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/spiral-matrix/

#include "leetcode_others.h"


vector<int> spiralOrder(vector<vector<int> > &matrix) {
    vector<int>ret;
    if (matrix.size() == 0) return ret;
    int rows = (int)matrix.size();
    int cols = (int)matrix[0].size();
    for (int i = 0; i < min(rows,cols) / 2; i++) {
        for (int index = 0; index <= cols - 2 * i - 2; index++) {
            ret.push_back(matrix[i][i+index]);
        }
        for (int index = 0; index <= rows - 2 * i - 2; index++) {
            ret.push_back(matrix[i+index][cols - i - 1]);
        }
        for (int index = 0; index <= cols - 2 * i - 2; index++) {
            ret.push_back(matrix[rows - i - 1][cols - i - 1 -index]);
        }
        for (int index = 0; index <= rows - 2 * i - 2; index++) {
            ret.push_back(matrix[rows - i - 1 - index][i]);
        }
    }
    if (min(rows, cols) % 2 != 0) {//odd
        if (rows == cols) {
            ret.push_back(matrix[rows/2][rows/2]);
        }else if(rows > cols){
            for (int i = (cols-1)/2; i < rows - (cols-1)/2; i++) {
                ret.push_back(matrix[i][cols/2]);
            }
        }else{
            for (int i = (rows-1)/2; i < cols - (rows-1)/2; i++) {
                ret.push_back(matrix[rows/2][i]);
            }
        }
    }
    return ret;
}

void testSopralOrder(){
//    vector<vector<int> >matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<vector<int> >matrix = {{1,2},{3,4}};
    vector<int >a = spiralOrder(matrix);
    cout<<"Finished"<<endl;
}