//
//  ConstructBinaryTreefromInorderandPostorderTraversal.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-22.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_tree.h"

static vector<int> p,q;

static TreeNode *helper(int q_s,int q_e,int p_s,int p_e){
    if (q_s > q_e) return NULL;
    
    int save_q_s = q_s;
    int save_p_s = p_s;
    
    int target = p[p_e];
    int mid = 0;
    for (int i = q_e; i >= q_s; i--) {
        if (q[i] == target) {
            mid = i;
            break;
        }
    }
    TreeNode *root = new TreeNode(q[mid]);
    //right side
    q_s = mid + 1;//1
    q_e = q_e;//1
    p_e = p_e - 1;//0
    p_s = q_s - q_e + p_e; //p_s - p_e = q_s - q_e
    root->right = helper(q_s,q_e,p_s,p_e);
    
    //left side
    q_s = save_q_s;
    q_e = mid - 1;
    p_s = save_p_s;
    p_e = p_s + q_e - q_s;
    root->left = helper(q_s,q_e,p_s,p_e);
    
    return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    int len = (int)inorder.size();
    if (len == 0) return NULL;
    q = inorder;
    p = postorder;
    return helper(0, len - 1, 0, len - 1);
}

void testBuildTree(){
    vector<int> pp = {2,1};
    vector<int> qq = {1,2};
    buildTree(qq, pp);
}




