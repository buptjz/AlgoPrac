//
//  numTrees.c
//  LeetCode
//
//  Created by WangJZ on 14-1-22.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include <stdio.h>
#include "Header.h"


//动态规划使用自顶向下的算法，时间复杂度高
int numTreesHelper(int n){
    if (n == 0 || n == 1) return 1;
    
    int retValue = 0;
    for (int i = 1;i <= n; i++) {
        retValue += numTreesHelper(n - i) * numTreesHelper(i - 1);
    }
    return retValue;
}

int numTrees(int n) {
    if (n == 0) {
        return 0;
    }
    return numTreesHelper(n);
}


//动态规划使用自顶向下的算法，时间复杂度低
int numTrees2(int n) {
    if (n == 0) return 0;
    int a[n];
    a[0] = 1;
    a[1] = 1;
    for (int i = 2; i <= n; i++) {
        int ithTreeNum = 0;
        for (int j = 0; j < i; j++) {
            ithTreeNum += a[j] * a[i-j-1];
        }
        a[i] = ithTreeNum;
    }

    return a[n];
}


void testNumTrees(){
    int num = 5;
    printf("Answer is %d\n",numTrees(num));
    printf("Answer is %d\n",numTrees2(num));
}