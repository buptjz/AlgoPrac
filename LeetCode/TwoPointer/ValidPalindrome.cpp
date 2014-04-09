//
//  ValidPalindrome.cpp
//  Algorithms
//
//  Created by WangJZ on 14-3-27.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_string.h"

bool isPalindrome(string s) {
    if (s.size() == 0) {
        return true;
    }
    int start = 0;
    int end = (int)s.size() - 1;
    while (start < end) {
        if (!isalnum(s[start])) start++;
        else if(!isalnum(s[end])) end--;
        else{
            if (tolower(s[start]) == tolower(s[end])) {
                start++;
                end--;
            }else{
                return false;
            }
        }
    }
    return true;
}
void testIsPalindrome(){
    bool res = isPalindrome(string("1%2"));
    printf("%d\n",res);
                            
}
