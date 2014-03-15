//
//  BinaryTreeZigzagLevelOrderTraversal.cpp
//  LeetCode
//
//  Created by WangJZ on 14-3-10.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

/*
 思路：
 分别对不同层做不同的处理，认为root是第一层，奇数层从左向右遍历，偶数层从右向左遍历
分别用两个栈来存放不同的层，奇栈存放奇数层待处理的节点，偶栈存放偶数层待处理节点；
 奇数层节点处理的时候，从左向右，左孩子先入栈偶栈（保证偶栈出栈的时候先遍历右边的）
 偶数层与此相反
 */

#include "BinaryTreeZigzagLevelOrderTraversal.h"
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void oddProcess(stack<TreeNode*> &evenStack,stack<TreeNode*> &oddStack,vector<vector<int> > &retVec);
void evenProcess(stack<TreeNode*> &evenStack,stack<TreeNode*> &oddStack,vector<vector<int> > &retVec);


void evenProcess(stack<TreeNode*> &evenStack,stack<TreeNode*> &oddStack,vector<vector<int> > &retVec) {
    TreeNode *temp;
    vector<int> currentVec;
    while (!evenStack.empty()) {
        
        temp = evenStack.top();
        currentVec.push_back(temp->val);
        if (temp->right != NULL) oddStack.push(temp->right);
        if (temp->left != NULL) oddStack.push(temp->left);
        evenStack.pop();
    }
    retVec.push_back(currentVec);
    
    if (oddStack.empty()) {
        return;
    }else{
        oddProcess(evenStack, oddStack, retVec);
    }
}

void oddProcess(stack<TreeNode*> &evenStack,stack<TreeNode*> &oddStack,vector<vector<int> > &retVec) {
    TreeNode *temp;
    vector<int> currentVec;
    while (!oddStack.empty()) {
        temp = oddStack.top();
        oddStack.pop();
        currentVec.push_back(temp->val);
        //进even层的栈，左先
        if (temp->left != NULL) evenStack.push(temp->left);
        if (temp->right != NULL) evenStack.push(temp->right);
    }
    retVec.push_back(currentVec);
    
    if (evenStack.empty()) {
        return;
    }else{
        evenProcess(evenStack, oddStack, retVec);
    }

}

vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    
    vector<vector<int> > retVec;
    if (root == NULL) {
        return retVec;
    }
    stack<TreeNode*> evenStack;
    stack<TreeNode*> oddStack;
    oddStack.push(root);
    oddProcess(evenStack, oddStack, retVec);
    return retVec;
}

void testZigzagLevelOrder(){
    TreeNode *root = new TreeNode(0);
    TreeNode *l = new TreeNode(1);
    TreeNode *r = new TreeNode(2);
    TreeNode *ll = new TreeNode(3);
    TreeNode *lr = new TreeNode(4);
    TreeNode *lrr = new TreeNode(5);
    root->left = l;
    root->right = r;
    l->right = lr;
    l->right->right = lrr;
    l->left = ll;
    vector<vector<int>> res = zigzagLevelOrder(root);
    printf("Finished");
}