//
//  SpiralMatrix.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-5.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  ugly Spiral Matrix 

#include "leetcode_others.h"

vector<int> spiralOrder(vector<vector<int> > &matrix) {
    vector<int> retVec;
    
    int row = (int)matrix.size();
    if (row == 0) return retVec;
    int col = (int)matrix[0].size();
    
    int cycle = min(row / 2,col / 2);
    
    
    for (int c = 0; c < cycle; c++) {
        
        //from left to right
        for (int j = c; j <= col - c -2; j++) {
            int i = c;
            retVec.push_back(matrix[i][j]);
        }
        //from top to bottom
        for (int i = c; i <= row-c-2; i++) {
            int j = col - c - 1;
            retVec.push_back(matrix[i][j]);
        }
        //from right to left
        for (int j = col - c - 1; j >= c+1; j--) {
            int i = row - c - 1;
            retVec.push_back(matrix[i][j]);
        }
        //from bottom to up
        for (int i = row -c -1; i >=c+1; i--) {
            int j = c;
            retVec.push_back(matrix[i][j]);
        }
    }
    if (row % 2 == 1 && col % 2 == 1) {
        if (row > col) {
            //from top to bottom
            for (int i = cycle; i <= row-cycle-1; i++) {
                int j = cycle;
                retVec.push_back(matrix[i][j]);
            }
        }else{
            for (int j = cycle; j <= col - cycle -1; j++) {
                int i = cycle;
                retVec.push_back(matrix[i][j]);
            }
        }
    }else if (row % 2 == 1) {
        for (int j = cycle; j <= col - cycle -1; j++) {
            int i = cycle;
            retVec.push_back(matrix[i][j]);
        }
    }else if(col % 2 == 1){
        //from top to bottom
        for (int i = cycle; i <= row-cycle-1; i++) {
            int j = cycle;
            retVec.push_back(matrix[i][j]);
        }
    }
    return retVec;
}
