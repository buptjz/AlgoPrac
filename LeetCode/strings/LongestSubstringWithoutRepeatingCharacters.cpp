//
//  LongestSubstringWithoutRepeatingCharacters.c
//  LeetCode
//
//  Created by WangJZ on 14-1-21.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_string.h"

int lengthOfLongestSubstring(string s) {
    int length = (int)s.length();
    if (length <= 0) return 0;
    
    int index;
    int dis;
    int *record = (int *)malloc(sizeof(int) * length);
    //保存字符x上一次出现在那个位置，初始值默认为-1
    int map[256] = {};
    for (int i = 0; i < 256; i++) {
        map[i] = -1;
    }
    
    //第一个字符默认值
    record[0] = 1;
    map[(int)s[0]] = 0;
    
    for (int i = 1; i < length; i++) {
        index = (int)s[i];
        if (map[index] == -1) {//前面没有出现过，取值是上一个字符的串长+1
            record[i] = record[i-1] + 1;
        }else{//在前面出现过，取值是上一个字符的串长+1或者是和上一次出现的距离
            dis = i - map[index];
            record[i] = min(record[i-1]+1, dis);
        }
        map[index] = i;
    }
    int max = 1;
    for (int i = 0; i < length; i++) {
        if (max < record[i]) max = record[i];
    }
    return max;
}

void testLengthOfLongestSubstring(){
    string s= "hchzvfrkmlnozjk";
    int ret = lengthOfLongestSubstring(s);
    printf("It's %d\n",ret);
    
}