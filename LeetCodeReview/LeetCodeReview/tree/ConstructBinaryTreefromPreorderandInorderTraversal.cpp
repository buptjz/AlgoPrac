//
//  ConstructBinaryTreefromPreorderandInorderTraversal.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-22.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_tree.h"

vector<int> p,q;

static TreeNode *helper(int q_s,int q_e,int p_s,int p_e){
    if(q_s > q_e) return NULL;
    int save_pe = p_e;
    int save_qe = q_e;
    int mid = 0;
    
    int target = p[p_s];
    for (int i = q_s; i <= q_e; i++) {
        if (q[i] == target) {
            mid = i;
            break;
        }
    }
    TreeNode *root = new TreeNode(q[mid]);
    
    //left side
    q_s = q_s;
    q_e = mid - 1;
    p_s = p_s + 1;
    p_e = q_e - q_s + p_s;//because p_e - p_s = q_e - q_s
    root->left = helper(q_s, q_e, p_s, p_e);
    
    //right side
    q_s = mid + 1;
    q_e = save_qe;
    p_e = save_pe;
    p_s = q_s - q_e + p_e;
    root->right = helper(q_s, q_e, p_s, p_e);
    
    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int len = (int)preorder.size();
    if (len == 0) {
        return NULL;
    }
    p = preorder;
    q = inorder;
    return helper(0,len - 1,0,len - 1);
}
