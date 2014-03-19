//
//  BinaryTreeMaximumPathSum.cpp
//  LeetCode
//
//  Created by WangJZ on 3/9/14.
//  Copyright (c) 2014 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/binary-tree-maximum-path-sum/



#include "leetcode_tree.h"
/*------------2014.3.19更新---------*/

/*
DFS返回的是当前节点可用情况下的最大值    ---》当前节点可用意味着:1)当前节点是path中的一端 2）左孩子或者右孩子最多有一个在path中（可以都不在）
全局变量res保存的是当前最大值
 
 每次递归调用的时候，在递归的最后重新计算res（将纳入本节点之后的最大值和没有纳入本节点前的path最大路径作比较）

 【注意】1）res要有初值，是根节点的值 2）递归的base case 返回的是最小整数值

 该解法是目前看到的最简答的形式，虽然理解上依然不是很容易。
 */

static int res;

int DFS(TreeNode *root) {
    if(root == NULL) return INT_MIN;
    int suml = DFS(root->left);
    int sumr = DFS(root->right);
    int tp = root->val;
    if(suml > 0) tp += suml;
    if(sumr > 0) tp += sumr;
    res = max(tp, res);//比较的依据是当前节点加入到Path中（tp）和当前节点没加入Path中（res）的最大值
    return max(max(suml, sumr), 0) + root->val;
}

int maxPathSum2(TreeNode *root) {
    if(root == NULL) return 0;
    res = root->val;
    DFS(root);
    return res;
}


/*------------原来的解法---------*/
/*
 递归set value
 1）本节点可用时候的最大值（包含本节点&&只包含一支）
 2）本节点不可用时候的最大值（不包含本节点||左中右三个节点都用到了||包含本节点）
 上述第二点的第三个条件不好想到，其实意思是在左节点仍然可用的情况下，不用左节点
 我们的前提假设 cannotUse >= canUse
 3） 递归返回的是当前最大的sum
 */
void maxPathSumHelper(TreeNode *root,int &canUse,int &cannotUse) {
    int leftCanUse,rightCanUse;//左单最大值，右单最大值
    int leftCannotUse,rightCannotUse;
    if (root == NULL) {
        canUse = -1000;
        cannotUse = -1000;
        return;
    }
    maxPathSumHelper(root->left,leftCanUse,leftCannotUse);
    maxPathSumHelper(root->right,rightCanUse,rightCannotUse);
    int larger = max(leftCanUse,rightCanUse);
    canUse = larger > 0 ? root->val+larger : root->val;
    cannotUse = max(max(leftCannotUse,rightCannotUse),max(leftCanUse+rightCanUse+root->val,root->val));
}

int maxPathSum(TreeNode *root) {
    if (root ->left == NULL && root->right == NULL) return root->val;
    int canUse,cannotUse;
    maxPathSumHelper(root,canUse,cannotUse);
    return max(cannotUse,cannotUse);
}

void testMaxPathSum(){
    TreeNode *a = new TreeNode(-1);
    TreeNode *b = new TreeNode(-3);
    a->left = b;
    int res = maxPathSum2(a);
    printf("Finished %d\n",res);
 }