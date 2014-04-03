//
//  PalindromeNumber.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-3.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_others.h"
#include <math.h>

static bool isPalindrome(int x) {
    if(x < 0) return false;
    int x_copy = x;
    int bits = 0;//how may bits of x (10 numbers / bit)
    while (x_copy) {
        bits ++;
        x_copy /= 10;
    }
    x_copy = x;
    for (int i = 1; i <= bits / 2; i++) {
        int divide = (int)pow(10, (bits - 2*(i -1) ) -1);//calculate how many zeros after 1
        int left = x / divide;
        int right = x % 10;
        if (left != right) return false;
        x -= left * divide;
        x -= right;
        x /= 10;
    }
    return true;
}
void testIsIsPalindrome(){
    bool res = isPalindrome(-214744742);
    printf("%d\n",res);
}


