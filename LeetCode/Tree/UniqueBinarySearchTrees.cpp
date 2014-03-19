//
//  UniqueBinarySearchTrees.cpp
//  Algorithms
//
//  Created by WangJZ on 14-3-18.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

/*
 n个节点能生成多少种二叉搜索树
 */

#include "leetcode_tree.h"

int numTrees(int n) {
    if (n == 0) return 0;
    int a[n];
    a[0] = 1;
    a[1] = 1;
    for (int i = 2; i <= n; i++) {
        int ithTreeNum = 0;
        if(i % 2 == 0){//偶数
            for (int j = 0; j < (i / 2); j++) {
                ithTreeNum += 2 * a[j] * a[i-j-1];
            }
        }
        else{//奇数
            for (int j = 0; j < (i / 2); j++) {
                ithTreeNum += 2 * a[j] * a[i-j-1];
            }
            ithTreeNum += a[i / 2] * a[i / 2];
        }
        
        a[i] = ithTreeNum;
    }
    
    return a[n];
}
