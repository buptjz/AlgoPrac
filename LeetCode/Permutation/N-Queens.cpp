//
//  N-Queens.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-1.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/n-queens/

#include "leetcode_others.h"

vector<vector<bool>> setQueue(int x,int y,const vector<vector<bool>> &cur_state,int total){
    //横向、纵向
    int saveX = x,saveY = y;
    vector<vector<bool>>retState(cur_state);
    for (int i = 0; i < total; i++) {
        retState[x][i] = true;
        retState[i][y] = true;
    }
    while (x < total && y < total ) retState[x++][y++] = true;//右下
    x = saveX;
    y = saveY;
    while (x >=0 && y >= 0) retState[x--][y--] = true;//左上
    x = saveX;
    y = saveY;
    while (x >=0 && y < total ) retState[x--][y++] = true;//右上
    x = saveX;
    y = saveY;
    while (x < total && y >= 0) retState[x++][y--] = true;//左下
    return retState;
}

void backtrack(int n,vector<vector<bool> > state,
               vector<string>&temp,int total,
               vector<vector<string> >&retVec)
{
    if ( n == 0) {//递归终止条件，所有的Q都摆在了棋盘上
        retVec.push_back(temp);
        return;
    }
    
    for (int j = 0; j < total; j++) {
        if (state[n-1][j] == true) continue;
        vector<vector<bool> > newState = setQueue(n-1, j, state,total);
        temp[n-1][j] = 'Q';//make_move
        backtrack(n-1, newState, temp, total,retVec);
        temp[n-1][j] = '.';//unmake_move
    }
}

vector<vector<string> > solveNQueens(int n) {
    vector<vector<bool> >state(n,vector<bool>(n,false));
    vector<string> temp(n,string(n,'.'));
    vector<vector<string> >retVec;
    backtrack(n, state, temp, n,retVec);
    return retVec;
}

void testSolveNQueens(){
    vector<vector<string> >res = solveNQueens(4);
    printf("Finished\n");
}




