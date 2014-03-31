//
//  main.c
//  LeetCode
//
//  Created by WangJZ on 14-1-12.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include <stdio.h>
#include "other_sort.h"
#include "leetcode_tree.h"
#include "leetcode_list.h"
#include "leetcode_string.h"
#include "longestCommonSubstring.h"

#include "longestCommonSubSequence.h"
#include "cict_c++.h"
#include "leetcode_permutation.h"
#include "leetcode_string.h"
#include "BigNumber.h"
#include "leetcode_others.h"
#include "conquerOffer.h"
#include "leetcode_sort.h"
#include "leetcode_dp.h"

int f(int x){
    int s = 0;
    while (x-- > 0) s+=f(x);
    return max(s,1);
}

int main(int argc, const char * argv[])
{
    int *p = (int *)malloc(sizeof(int *) * 8000000000000);
    if(p == NULL){
        printf("fuck\n");
    }
    printf("ok\n");
    return 0;
}


