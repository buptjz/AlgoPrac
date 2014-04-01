//
//  LengthofLastWord.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-1.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/length-of-last-word/

//注意细节，细节决定成败

#include "leetcode_string.h"

int lengthOfLastWord(const char *s) {
    if (*s == '\0') return 0;
    int length = 0;
    while (s[++length])
        ;
    
    bool alphaAppear = false;
    for (int i = length - 1; i >= 0; i--) {
        if (alphaAppear) {
            if (s[i] == ' ') return length - i - 1;
        }else{
            if (isalpha(s[i])) alphaAppear = true;
            else length--;
        }
    }
    return length;
}

void testLengthOfLastWord(){
    int res = lengthOfLastWord("  av   ");
    printf("%d\n",res);
}
