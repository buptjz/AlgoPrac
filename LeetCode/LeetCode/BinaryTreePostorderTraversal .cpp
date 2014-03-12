//
//  BinaryTreePostorderTraversal .cpp
//  LeetCode
//
//  Created by WangJZ on 14-3-12.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/binary-tree-postorder-traversal/

/*
 使用栈来进行后续遍历（而不适用递归的方式）
 */



#include "BinaryTreePostorderTraversal .h"
#include <vector>
#include <stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
struct TagTreeNode{
    TreeNode *treeNode;
    bool tag;
    TagTreeNode(int x,TreeNode *t):tag(x),treeNode(t){}
};


vector<int> postorderTraversal2(TreeNode *root) {
    vector<int> retVec;
    if (root == NULL) {
        return retVec;
    }
    stack<TagTreeNode *> myStack;
    myStack.push(new TagTreeNode(false, root));
    while (!myStack.empty()) {
        TagTreeNode *cur = myStack.top();
        myStack.pop();
        if (cur->tag == true) {//已经是第二次出栈
            retVec.push_back(cur->treeNode->val);
        }else{//首次出栈
            cur->tag = true;
            TreeNode *curTree = cur->treeNode;
            myStack.push(cur);
            if (curTree->right) myStack.push(new TagTreeNode(false,curTree->right));
            if (curTree->left) myStack.push(new TagTreeNode(false,curTree->left));
        }
    }
    return retVec;
}