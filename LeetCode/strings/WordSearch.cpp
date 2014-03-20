//
//  WordSearch.cpp
//  LeetCode
//
//  Created by WangJZ on 14-2-24.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/word-search/

/*
 思路：分别以board上得每一个点作为起始点来查找单词是否存在，只要其中某一个点存在，即为找到
 在遍历一个点的时候，使用is_visited来记录该点是否使用过，如果使用过，之后便不能使用
 
 existHelper递归的查询一个单词是否存在，需要注意的是递归的下一行要将标志位unmake
 
 */

#include "leetcode_string.h"

int m,n;
bool existHelper(vector<vector<char>> &board,
                 string word,
                 int matched_length,
                 vector<vector<bool>> &is_visited,
                 int x,
                 int y)
{
    if (matched_length == (int)word.length()) {
        return true;
    }
    //检查右边
    if (x == m-1 || is_visited[x+1][y] || board[x+1][y] != word[matched_length]) {
        
    }else{
        is_visited[x+1][y] = true;
        if(existHelper(board, word, matched_length+1, is_visited, x+1, y)) return true;
        is_visited[x+1][y] = false;
    }
    //检查左边
    if (x == 0 || is_visited[x-1][y] || board[x-1][y] != word[matched_length]) {
        
    }else{
        is_visited[x-1][y] = true;
        if(existHelper(board, word, matched_length+1, is_visited, x-1, y)) return true;
        is_visited[x-1][y] = false;
    }
    //检查上边
    if (y == n-1 || is_visited[x][y+1] || board[x][y+1] != word[matched_length]) {
        
    }else{
        is_visited[x][y+1] = true;
        if(existHelper(board, word, matched_length+1, is_visited, x, y+1)) return true;
        is_visited[x][y+1] = false;
    }
    //检查下
    if (y == 0 || is_visited[x][y-1] || board[x][y-1] != word[matched_length]) {
        
    }else{
        is_visited[x][y-1] = true;
        if(existHelper(board, word, matched_length+1, is_visited, x, y-1)) return true;
        is_visited[x][y-1] = false;
    }
    return false;
}

bool exist(vector<vector<char> > &board, string word) {
    m = (int)board.size();
    n = (int)board[0].size();
    
    //初始化标记数组
    vector<vector<bool>> is_visited;
    for (int i = 0; i < m; i++) {
        vector<bool> temp = vector<bool>(n,false);
        is_visited.push_back(temp);
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (word[0] == board[i][j]) {
                is_visited[i][j] = true;
                if (existHelper(board, word, 1, is_visited,i,j)) {
                    return true;
                }
                is_visited[i][j] = false;
            }
        }
    }
    return false;
}