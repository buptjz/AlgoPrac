//
//  N-Queens.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-6.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_dp.h"

vector<int> getCandidates(vector<string> &tmp,int index){
    vector<int> res;
    for (int i = 0 ; i < tmp.size(); i++) {
        //向找上
        bool can = true;
        int col = i;
        int row = index-1;
        while (col >= 0 && row>=0) {
            if(tmp[row][col] == 'Q') {
                can = false;
                break;
            }
            row--;
        }
        
        //向左上
        if (can == false) continue;
        
        row = index-1;
        col = i -1;
        while (col >= 0 && row>=0) {
            if(tmp[row][col] == 'Q') {
                can = false;
                break;
            }
            row--;
            col--;
        }
        
        //向右上
        if (can == false) continue;
        
        row = index-1;
        col = i + 1;
        while (col < tmp.size() && row>=0) {
            if(tmp[row][col] == 'Q') {
                can = false;
                break;
            }
            row--;
            col++;
        }
        if (can == false) continue;
        res.push_back(i);
    }
    return res;
}

void solveNQueensHelper(vector<vector<string>> &result,int index,int n,vector<string> &tmp){
    if (index == n) {
        result.push_back(tmp);
        return;
    }
    
    vector<int> candis = getCandidates(tmp,index);
    for (int c : candis) {
        tmp[index][c] = 'Q';
        solveNQueensHelper(result, index+1, n, tmp);
        tmp[index][c] = '.';
    }
}


vector<vector<string> > solveNQueens(int n) {
    vector<vector<string >> res;
    if (n == 0) return res;
    vector<string> tmp;
    for (int i =0; i < n; i++) {
        string s(n,'.');
        tmp.push_back(s);
    }
    solveNQueensHelper(res, 0, n, tmp);
    return res;
}

void testSolveNQueens(){
    vector<vector<string >> a = solveNQueens(4);
    cout<<"r"<<endl;
}




