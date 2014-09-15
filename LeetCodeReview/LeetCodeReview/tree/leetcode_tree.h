//
//  leetcode_tree.h
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-15.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#ifndef LeetCodeReview_leetcode_tree_h
#define LeetCodeReview_leetcode_tree_h

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif