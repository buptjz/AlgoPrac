//
//  PopulatingNextRightPointersinEachNodeII.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-2.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_tree.h"

/*
 2014.4.9日更新，只用一次递归即可
 递归的次序是root，right，left
 这里有更简洁的方法！
 http://discuss.leetcode.com/questions/282/populating-next-right-pointers-in-each-node-ii
 
 */
void findAndSet(TreeLinkNode *nodeTobeSet,TreeLinkNode *lastLevel){
    while (nodeTobeSet->next == NULL && lastLevel->next) {
        lastLevel = lastLevel->next;
        if (lastLevel->left) {
            nodeTobeSet->next = lastLevel->left;
            nodeTobeSet = lastLevel->left;
        }else if(lastLevel->right) {
            nodeTobeSet->next = lastLevel->right;
            nodeTobeSet = lastLevel->right;
        }
    }
}
static void connect(TreeLinkNode *root) {
    if (!root|| (!root->left && !root->right)) return;
    if (root->right) {//有右孩子
        findAndSet(root->right,root);
        connect(root->right);
        if (root->left) {//既有右孩子，又有左孩子
            root->left->next = root->right;
            connect(root->left);
        }
    }else{//没有右孩子，有左孩子
        findAndSet(root->left, root);
        connect(root->left);
    }
}
/*
 代码有点ugly，需要看看别人的
 思路：第一次遍历先将左孩子的next指向其兄弟
 
 第二次遍历，优先遍历右孩子
 对每一个node，判断其左孩子还是右孩子没有next，然后使用两个指针，一个指向上一层，一个指向本层的待设置next的node，
 上一层的指针每次向后移动，一旦上层指针有左孩子或者右孩子target，就把本层node->next = target设置为它
 注意的是要将target重新设为本层的待设置节点的node，
 
 这样就优先的将右侧的所有节点都设置了next。
 */

static void firstTraverse(TreeLinkNode *root){
    if (root == NULL) return;
    if (root->left && root->right) root->left->next = root->right;
    firstTraverse(root->left);
    firstTraverse(root->right);
}

static void secondTraverse(TreeLinkNode *root){
    if (root == NULL) return;
    TreeLinkNode *needToSetNext = NULL;
    if (root->left == NULL && root->right == NULL) return;
    if (root->left) needToSetNext = root->left;
    needToSetNext = root->right;
    TreeLinkNode *lastLevel = root;
    while (needToSetNext->next == NULL && lastLevel->next) {
        lastLevel = lastLevel->next;
        if (lastLevel->left) {
            needToSetNext->next = lastLevel->left;
            needToSetNext = lastLevel->left;
        }else if(lastLevel->right) {
            needToSetNext->next = lastLevel->right;
            needToSetNext = lastLevel->right;
        }
    }
    secondTraverse(root->right);
    secondTraverse(root->left);//交换了这俩的顺序，瞬间就对了！
}

static void connect2(TreeLinkNode *root) {
    firstTraverse(root);
    secondTraverse(root);
}