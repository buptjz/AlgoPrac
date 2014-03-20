//
//  PermutationSequence.cpp
//  LeetCode
//
//  Created by WangJZ on 14-2-21.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/permutation-sequence/

/*
 找到n个数所有排列情况中排在第x个位置上的数，当然，可以用字典发将所有的数字列出来，但是没有必要
 我用的方法是按从左到右的顺位按位去求取每一位的值，由于前t-1位置上都确定了，第t位置上有n-t+1个取值，每个取值后面都带有(n-t)!个数，由此可以找到我们应该取哪一个区间上的数
 
 发现int转string没有直接的方法
 */

#include "leetcode_permutation.h"

string int2str(int num)
{
    if (num == 0 )return " 0 " ;
    string str = "" ;
    int num_ = num > 0 ? num : - 1 * num;
    while (num_)
    {
        str = ( char )(num_ % 10 + 48 ) + str;
        num_ /= 10 ;
    }
    if (num < 0 )
        str = " - " + str;
    return str;
}

int* get_factorial_number(int n){
    if (n < 1) {
        return NULL;
    }
    int *ret = (int *)malloc(sizeof(int) * (n + 1));
    ret[0] = 1;
    for (int i = 1; i < n; i++) {
        ret[i] = ret[i - 1] * i;
    }
    return ret;
}
string getPermutation(int n, int k) {
    int final = 0;
    vector<bool> hasUsed = vector<bool>(n+1,false);
    int *fac = get_factorial_number(n);
    
    int partition_no;
    for (int i = 0; i < n; i++) {
        partition_no = (k-1) / fac[n - i - 1] + 1;
        
        //Find the proper number for this position
        int number = 0;
        int total = 0;
        for (int index = 1; index <= n; index++) {
            if (!hasUsed[index]) {
                total++;
            }
            if (total == partition_no) {
                number = index;
                break;
            }
        }
        if (number == 0) return NULL;
        final = final * 10 + number;
        hasUsed[number] = true;
        k -= (partition_no-1) * fac[n-1-i];
    }

    return int2str(final);
}

void testGetPermutation(){
    string s = getPermutation(3, 5);
    printf("Finished");
}