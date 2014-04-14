//
//  JumpGameII.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-2.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/jump-game-ii/

#include "leetcode_dp.h"

/*网友的解法，我靠太巧妙了！
 http://www.cnblogs.com/lichen782/p/leetcode_Jump_Game_II.html
 */
static int jump2(int A[], int n) {
    int cover = 0;
    int ret = 0;
    int last = 0;
    for (int i = 0; i < n; i++) {
        if (i > last) {
            ret++;
            last = cover;
        }
        cover = max(cover,i+A[i]);
    }
    return ret;
}

/*以下代码不能通过大集合，wtf*/
static int jump(int A[], int n) {
    vector<int>record(n,n);
    record[n-1] = 0;
    int index = n-2;
    while (index >= 0) {
        if (A[index] == 0) record[index] = -1;
        else{
            int minSteps = n;
            int maxIndex = min(A[index] + index,n-1);
            int cur = index + 1;
            while (cur <= maxIndex) {
                if (record[cur] != -1 && record[cur] < minSteps) minSteps = record[cur];
                cur++;
            }
            record[index] = minSteps + 1;
        }
        index--;
    }
    return record[0];
}

void testJump(){
    int A[] = {4,1,1,1,2};
    int res = jump2(A, 5);
    printf("%d\n",res);
    
}