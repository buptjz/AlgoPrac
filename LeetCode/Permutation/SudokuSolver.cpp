//
//  SudokuSolver.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-2.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/sudoku-solver/

//使用backtrack方式完成数独问题！O(∩_∩)O~

#include "leetcode_permutation.h"

static bool finished = false;

void generateCandidates(vector<int>&candidates,vector<vector<char> > &board,int x,int y){
    bool table[10] = {false};
    for (int i = 0; i < 9; i++) {
        if (board[x][i] != '.') table[board[x][i] - '0'] = true;
        if (board[i][y] != '.') table[board[i][y] - '0'] = true;
    }
    x = x / 3;
    y = y / 3;
    for (int i = 3 * x; i < 3 * x + 3; i++) {
        for (int j = 3 * y; j < 3 * y + 3; j++) {
            if (board[i][j] != '.') table[board[i][j] - '0'] = true;
        }
    }
    for (int i = 1; i < 10; i++)
        if (table[i] == false) candidates.push_back(i + '0');
}

/*
 根据棋盘的情况找到最大束缚的点，如果所有的点都填充好了，那么返回(-1,-1)
 */
void getInputPosition(int &x,int &y,vector<vector<char> > &board){
    x = -1;
    y = -1;
    int x_count[9] = {0,0,0,0,0,0,0,0,0};
    int y_count[9] = {0,0,0,0,0,0,0,0,0};
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (board[i][j] != '.') {
                x_count[i] += 1;
                y_count[j] += 1;
            }
        }
    }
    int max_constraint = 0;
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (board[i][j] == '.') {
                if (max_constraint < x_count[i] + y_count[j]) {
                    max_constraint = x_count[i] + y_count[j];
                    x = i;
                    y = j;
                }
            }
        }
    }
}

void solveSudoku(vector<vector<char> > &board) {
    int x,y;
    getInputPosition(x,y,board);
    //如果找不到一个可以输入的点，说明完成了，将完成标志位置为true
    if (x == -1){
        finished = true;
        return;
    }
    vector<int>candidates;
    generateCandidates(candidates, board, x, y);
    if (candidates.size() == 0) return;//该点找不到合法的输入，说明这种情况是错误的，返回上一级
    for (int i = 0; i < (int)candidates.size(); i++) {
        board[x][y] = candidates[i];
        solveSudoku(board);
        if (finished) return;//如果完成，就不继续了，保持board的最后状态即可！
        board[x][y] = '.';
    }
}
//[".....7..9",".4..812..","...9...1.","..53...72","293....5.",".....53..","8...23...","7...5..4.","531.7...."]
void testSolveSudoku(){
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
    solveSudoku(vec);
    printf("Finished\n");
}
