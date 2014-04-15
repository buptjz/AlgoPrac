//
//  WildcardMatching.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-1.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/wildcard-matching/
//  http://blog.csdn.net/hopeztm/article/details/8039777
#include "leetcode_others.h"
/*
 2014.4.15重新看，还是很难！
 更新，来自于http://oj.leetcode.com/discuss/2964/still-get-tle-on-aaaaaaaaaaaaa-exhausted
 其核心是：
 尽可能的向后查找，尽量让p移动，如果能够尽快的扫描通过到后面的*，那么前面的内容不在话下，都可以使用最后一个*来匹配。
 */
static bool isMatch(const char *s, const char *p) {
    if (!*p && !*s) return true; // both empty, so sad but true
    if (*p == *s) return isMatch(s + 1, p + 1); // match!
    else if (*p == '?' && *s) return isMatch(s + 1, p + 1); // weird match!
    else if (*p == '*') {
        while (*p == '*') ++p; // I only need just one starlet ;)
        if (!*p) return true; // ends with star, the Universe can fit into it now!
        while (*s) { // brute force match
            const char *ts = s, *tp = p;
            while ((*ts == *tp || *tp == '?') && *ts) {
                if (*tp == '*') break;
                ++ts; ++tp;
            }
            if (!*ts && !*tp) return true; // both empty
            // *tp is * then ok, otherwise no exact match :(
            //【亮点、难点】能够大大加快进展
            if (*tp == '*') {
                // we don't need to concern ourself with more exact matches as the * would take care of it,
                // and for rest brute force matching will be done
                return isMatch(ts, tp);
            }
            if (!*ts) return false; // search exhausted yo! p has more than s can handle :O
            ++s;
        }
        return false;
    } else return false; // WAT
}

/*
 '?' Matches any single character.
 '*' Matches any sequence of characters (including the empty sequence).
 
 Some examples:
 isMatch("aa","a") → false
 isMatch("aa","aa") → true
 isMatch("aaa","aa") → false
 isMatch("aa", "*") → true
 isMatch("aa", "a*") → true
 isMatch("ab", "?*") → true
 isMatch("aab", "c*a*b") → false
 
 */


//static bool isMatchHelper(const char *s, const char *p) {
//    if (*s == '\0' && *p == '\0') {
//        return true;
//    }
//    if (*s == '\0') {
//        while (*p == '*') p++;
//        return !*p;
//    }
//    if (*p ==  '?') {//?
//        return isMatchHelper(s+1,p+1);
//    }
//    if(*p == '*'){//*
//        while (*p=='*') p++;
//        if (*p == '\0') return true;
//        p = p - 1;
//        return isMatchHelper(s+1,p) || isMatchHelper(s, p+1);
//    }else if(*p == *s){//相等的字符
//        return isMatchHelper(s+1,p+1);
//    }else{//不相等的字符
//        return false;
//    }
//}
//static bool isMatch(const char *s, const char *p) {
//    return isMatchHelper(s, p);
//}

void testIsMatch2(){
    bool res = isMatch("aba","*a");
    printf("Finished %d \n",res);
}

