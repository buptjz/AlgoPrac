//
//  ConvertSortedArraytoBinarySearchTree.cpp
//  LeetCode
//
//  Created by WangJZ on 14-1-20.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_tree.h"
#include <vector>



void helper(TreeNode*T,vector<int> &num,int start,int end,int where){
    if (start > end || T== NULL) return;
    int mid = (start + end) >> 1;
    TreeNode *tt = new TreeNode(num[mid]);
    if (where == -1) T->left = tt;
    else T->right = tt;
    helper(tt, num, start, mid-1, -1);
    helper(tt, num, mid+1, end, 1);
}

TreeNode *sortedArrayToBST(vector<int> &num) {
    if (num.size() == 0) return NULL;
    int n = (int)num.size();//一共有多少个数
    
    int mid = (0+n-1)>>1;
    TreeNode *ret = new TreeNode(num[mid]);
    
    helper(ret, num, 0, mid-1 ,-1);//构建左子树
    helper(ret, num, mid+1, n-1 ,1);//构建右子树
    return ret;
}

void testSortedArrayToBST(){
    vector<int> vc = {1,3};

    TreeNode *t = sortedArrayToBST(vc);
    printf("Finished\n");
}

