//
//  main.c
//  LeetCode
//
//  Created by WangJZ on 14-1-12.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include <stdio.h>
#include "functions.h"

int main(int argc, const char * argv[])
{

    // insert code here...
//    int a[1] = {3,4,1,2};
//    int b[2] = {1,2};
//    int result = findMedianSortedArrays(a, 1, b, 2);
    int a[12] = {1,1,1,1,2,1,1,1,1,1,1,1};
    int result = search(a, 12, 2);
    printf("Result is %d\n",result);
    return 0;
}
