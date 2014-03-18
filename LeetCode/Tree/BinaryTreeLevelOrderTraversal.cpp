//
//  BinaryTreeLevelOrderTraversal.cpp
//  LeetCode
//
//  Created by WangJZ on 14-1-23.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_tree.h"

void levelOrderHelper(vector<vector<int> > &vc,TreeNode *root,int level){
    if(root == NULL) return;
    if (level + 1 > (int)vc.size()) {
        vc.push_back(vector<int>());
    }
    vc[level].push_back(root->val);
    level++;
    levelOrderHelper(vc, root->left, level);
    levelOrderHelper(vc, root->right, level);
}

vector<vector<int> > levelOrder(TreeNode *root) {
    vector<vector<int> > a;
    levelOrderHelper(a, root, 0);
    return a;
}

void testlevelOrder(){
    TreeNode *temp = new TreeNode(1);
    vector<vector<int> > ret = levelOrder(temp);
    printf("finished\n");
}