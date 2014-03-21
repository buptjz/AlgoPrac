//
//  LongestSubstringWithoutRepeatingCharacters.c
//  LeetCode
//
//  Created by WangJZ on 14-1-21.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_string.h"

/*
    思路：用一个字典记录遇到的字符，一直向后走，如果遇到重复的字符，将start向后移动，直到遇到与最后一个字符相等的值。（将start走过的所有字符都在map中减去）
 */

//下面这段代码通过了！
int lengthOfLongestSubstring(string s) {
    int map[256];//数组当做字典用，表示当前每一个字符出现的次数
    for (int i = 0; i < 256; i++) {
        map[i] = 0;
    }
    int retMax = 0;
    int current_length = 0;//记录当前最大长度
    int start = 0;//起始位置
    for (int end = 0;end < (int)s.length(); end++){//最后一个位置一直向后走
        if (map[s[end]] != 0) {//该字符之前出现过
            retMax = max(retMax,current_length);
            while (true) {
                map[s[start]] --;//s从start走过的字符，在字典中都减去1
                current_length --;//当前长度-1
                if(s[start] == s[end]){
                    start++;
                    break;
                }
                start++;
            }
        }
        map[s[end]] += 1;
        current_length += 1;
    }
    return max(retMax,current_length);
}

//int lengthOfLongestSubstring(string s) {
//    int length = (int)s.length();
//    if (length <= 0) return 0;
//    
//    int index;
//    int dis;
//    int *record = (int *)malloc(sizeof(int) * length);
//    //保存字符x上一次出现在那个位置，初始值默认为-1
//    int map[256] = {};
//    for (int i = 0; i < 256; i++) {
//        map[i] = -1;
//    }
//    
//    //第一个字符默认值
//    record[0] = 1;
//    map[(int)s[0]] = 0;
//    
//    for (int i = 1; i < length; i++) {
//        index = (int)s[i];
//        if (map[index] == -1) {//前面没有出现过，取值是上一个字符的串长+1
//            record[i] = record[i-1] + 1;
//        }else{//在前面出现过，取值是上一个字符的串长+1或者是和上一次出现的距离
//            dis = i - map[index];
//            record[i] = min(record[i-1]+1, dis);
//        }
//        map[index] = i;
//    }
//    int max = 1;
//    for (int i = 0; i < length; i++) {
//        if (max < record[i]) max = record[i];
//    }
//    return max;
//}




void testLengthOfLongestSubstring(){
    string s= "hchzvfrkmlnozjk";
    int ret = lengthOfLongestSubstring(s);
    printf("It's %d\n",ret);
    
}