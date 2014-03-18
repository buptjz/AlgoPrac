//
//  leetcode_tree.h
//  Algorithms
//
//  Created by WangJZ on 14-3-18.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#ifndef Algorithms_leetcode_tree_h
#define Algorithms_leetcode_tree_h

#include <stdio.h>
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
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void testlevelOrder();
void testIsBalance();
void testPostorderTraversal();
void testPostorderTraversal();
void testPreorderTraversal();
void testZigzagLevelOrder();
void testBuildTree();
void testSortedListToBST();
void testFlattern();
void testSingleNumberIII();
void testGenerateTrees();
#endif
