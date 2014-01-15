//
//  trackStream.c
//  CiCT
//
//  11.8
//
//  Imagine you are reading in a stream of integers. Periodically, you wish
//  to be able to look up the rank of a number x (the number of values less
//  than or equal to x). Imple- ment the data structures and algorithms to
//  support these operations. That is,imple- mentthemethodtrack(int x),
//  whichiscalledwheneachnumberisgenerated, and themethodgetRankOf'Number (int x),
//  which returns thenumberof values less than or equal to x (not including x itself).
//
//  【思路1】Naive，用一个排序好的数组来保存输入流数据，这样可以用binary search来进行搜索，
//  插入的时间复杂度是O(N*log(N))搜索的时间复杂度是O(log(N))
//
//  【思路2】用一个二叉搜索树作为数据结构来保存输入流，插入和查找的时间为均为O(log(N))

#include <stdio.h>
#include <stdlib.h>
#include "arrayAndString.h"

typedef struct TreeNode{
    struct TreeNode *left;      //左子树
    struct TreeNode *right;     //右子树
    int key;                    //key值
    int data;                   //保存的额外数据,保存的是左子树有多少个
}TN;

TN *T;//全局变量

//插入二叉树
TN* insert(TN *T,int x){
    if (T == NULL) {//走到了路的尽头，创建新的节点，并对节点赋值
        T = malloc(sizeof(TN));
        T->key = x;
        T->data = 0;
    }else if(T->key >= x){//x插入到左子树,记录左子树加1，这里的等号非常重要
        T->left = insert(T->left, x);
        T->data ++;
    }else if(T->key < x){//x插入到右子树
        T->right = insert(T->right, x);
    }
    return T;
}

//二叉树的递归搜索
int getRankOFNumberInTree(TN *T,int x,int added){
    if (T == NULL) return -1;
    if (T->key == x) {//找到了等于x的点T，T的左子树节点数加上父节点传递过来的的值就是x的排位
        return added+T->data;
    }else if(T->key > x){//在左子树中寻找,并将added的值向下传递
        return getRankOFNumberInTree(T->left, x, added);
    }else{//在右子树中寻找,并将(T->data + added + 1)向下传递
        return getRankOFNumberInTree(T->right, x, T->data + added+1);
    }
}

//接口，给外部程序调用
void track(int x){
    T = insert(T, x);
}
int getRankOfNumber(int x){
    return getRankOFNumberInTree(T,x,0);
}
void testTrackStream(){
    int a[9] = {5,1,4,4,5,9,7,13,1};
    int length = 9;
    for (int i = 0; i < length; i++) {
        track(a[i]);
    }
    printf("Find\t%d\tExpected\t%d\tGot %d\n",8,-1,getRankOfNumber(8));
    printf("Find\t%d\tExpected\t%d\tGot %d\n",13,8,getRankOfNumber(13));
    printf("Find\t%d\tExpected\t%d\tGot %d\n",7,6,getRankOfNumber(7));
    printf("Find\t%d\tExpected\t%d\tGot %d\n",1,1,getRankOfNumber(1));
}
