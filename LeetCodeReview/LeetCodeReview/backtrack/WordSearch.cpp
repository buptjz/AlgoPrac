//
//  WordSearch.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-1.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_backtrack.h"

int row,col;
vector<vector<bool>> createVisited(int col,int row){
    vector<vector<bool>>ret;
    for (int i = 0; i < row; i++) {
        vector<bool> rowVec(col,false);
        ret.push_back(rowVec);
    }
    return ret;
}

vector<pair<int, int>> generateCandidates(vector<vector<bool>> &visited,vector<vector<char>> &board,
                                          string word,int index,int r,int c){
    vector<pair<int, int>> ret;
    if (r - 1 >= 0) {
        if (!visited[r-1][c] && board[r-1][c] == word[index])
            ret.push_back(make_pair(r-1, c));
    }
    if (r + 1 < row) {
        if (!visited[r+1][c] && board[r+1][c] == word[index])
            ret.push_back(make_pair(r+1, c));
    }
    if (c - 1 >= 0) {
        if (!visited[r][c-1] && board[r][c-1] == word[index])
            ret.push_back(make_pair(r, c-1));
    }
    if (c + 1 < col) {
        if (!visited[r][c+1] && board[r][c+1] == word[index])
            ret.push_back(make_pair(r, c+1));
    }
    return ret;
}


bool existHelper(vector<vector<bool>> &visited,vector<vector<char>> &board,
                 string word,int index,int r,int c){
    if (index == word.size()) return true;
    vector<pair<int, int>> candis = generateCandidates(visited, board, word, index, r, c);
    for (pair<int, int> cand : candis) {
        int tmp_r = cand.first;
        int tmp_c = cand.second;
        visited[tmp_r][tmp_c] = true;
        if (existHelper(visited, board, word, index+1, tmp_r, tmp_c)) return true;
        visited[tmp_r][tmp_c] = false;
    }
    return false;
}

bool exist(vector<vector<char> > &board, string word) {
    if (word.empty()) return false;
    row = (int)board.size();
    col = (int)board[0].size();
    
    vector<vector<bool>> visited = createVisited(col, row);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (board[i][j] == word[0]) {
                visited[i][j] = true;
                if (existHelper(visited,board,word,1,i,j)) return true;
                visited[i][j] = false;
            }
        }
    }
    return false;
}