//
//  ValidSudoku.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-2.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/valid-sudoku/

#include "leetcode_others.h"

bool isValidSudoku(vector<vector<char> > &board) {
    for (int i = 0; i < 9; i++) {
        //处理一行
        bool table[10] = {false};
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') continue;
            if (table[board[i][j] - '0'] == false) table[board[i][j] - '0'] = true;
            else return false;
        }
    }
    for (int j = 0; j < 9; j++) {
        //处理一列
        bool table[10] = {false};
        for (int i = 0; i < 9; i++) {
            if (board[i][j] == '.') continue;
            if (table[board[i][j] - '0'] == false) table[board[i][j] - '0'] = true;
            else return false;
        }
    }
    //处理每一个方块
    for (int blockx = 0; blockx < 3; blockx++) {
        for (int blocky = 0; blocky < 3; blocky ++) {
            bool table[10] = {false};
            for (int i = 3 * blockx; i < 3 * blockx + 3; i++) {
                for (int j = 3 * blocky; j < 3 * blocky + 3; j++) {
                    if (board[i][j] == '.') continue;
                    if (table[board[i][j] - '0'] == false) table[board[i][j] - '0'] = true;
                    else return false;
                }
            }
        }
    }
    return true;
}

void testIsValidSudoku(){
    vector<char> x1 = {'.','.','.','.','.','7','.','.','9'};
    vector<char> x2 = {'.','4','.','.','8','1','2','.','.'};
    vector<char> x3 = {'.','.','.','9','.','.','.','1','.'};
    vector<char> x4 = {'.','.','5','3','.','.','.','7','2'};
    vector<char> x5 = {'2','9','3','.','.','.','.','5','.'};
    vector<char> x6 = {'.','.','.','.','.','5','3','.','.'};
    vector<char> x7 = {'8','.','.','.','2','3','.','.','.'};
    vector<char> x8 = {'7','.','.','.','5','.','.','4','.'};
    vector<char> x9 = {'5','3','1','.','7','.','.','.','.'};
    vector<vector<char> > vec;
    vec.push_back(x1);
    vec.push_back(x2);
    vec.push_back(x3);
    vec.push_back(x4);
    vec.push_back(x5);
    vec.push_back(x6);
    vec.push_back(x7);
    vec.push_back(x8);
    vec.push_back(x9);
    bool res = isValidSudoku(vec);
    printf("Finished %d\n",res);
}


