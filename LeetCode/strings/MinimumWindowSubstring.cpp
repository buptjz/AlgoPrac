//
//  MinimumWindowSubstring.cpp
//  LeetCode
//
//  Created by WangJZ on 14-3-1.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/minimum-window-substring/

/*
 思路与http://oj.leetcode.com/problems/substring-with-concatenation-of-all-words/一致
 要点
 1）使用两个字典来记录S中已出现的字符的次数和T中字符的次数
 2）使用NRecords来记录已经匹配上多少个
 3）使用start_point来记录从哪一个点开始
 
 剩下的就相当于end向后走，找到NRcords相等时，说明匹配上了，匹配上之后就比较一下长度，
 然后start_point向前走一位
 
 注意各种条件下各种辅助变量的数值
 例如NRecords的增减、start_point的前进、S_dic的增减
 */

#include "leetcode_string.h"

string minWindow(string S, string T) {
    int min_length = -1;//当前最小匹配的长度
    int min_index = -1;
    int start_point = 0;//当前寻找的起始点
    int S_dic[128],T_dic[128];//S字典和T字典
    int NChars = (int)T.length();//需要匹配的数量
    int NRecords = 0;//已经匹配的数量
    for (int i = 0; i < 128; i++) {
        S_dic[i] = 0;
        T_dic[i] = 0;
    }
    //初始化T字典
    for (int i = 0; i < NChars; i++) {
        T_dic[T[i]] += 1;
    }
    //O(n)遍历开始
    char cur;
    for (int end = 0; end < (int)S.length(); end++) {
        cur = S[end];
        if (T_dic[cur] == 0) {//情况1：当前字符在T中没有，略过
            S_dic[cur] ++;
            continue;
        }else if(S_dic[cur] < T_dic[cur]){//情况2：当前字符在T中有，并且在S_dic中出现的次数小于T中，命中！多了一个匹配
            NRecords ++;
            S_dic[cur] ++;
        }else{//情况3：在T中有，但是已经匹配完了，当前字符没有多一个匹配
            S_dic[cur] ++;
        }
        if (NRecords == NChars) {//全都匹配上了
            while (start_point <= end) {
                if (S_dic[S[start_point]] > T_dic[S[start_point]]) {//如果起始点字符在S中出现次数多，说明该字符可以减去
                    S_dic[S[start_point]] --;
                    start_point++;
                }else{//否则情况一定是相等，相等说明整好用上了，不能减去
                    //如果是最短的，则记录下来
                    if(min_length > end - start_point + 1 || min_length == -1){
                        min_length = end - start_point + 1;
                        min_index = start_point;
                    }
//                    //重新计算起始点
//                    if (start_point < (int)S.length() - 1) {
//                        NRecords --;
//                        S_dic[S[start_point]] --;
//                        start_point ++;
//                    }
                    break;
                }
            }
        }
    }
    return (min_index == -1)? "":S.substr(min_index,min_length);
}

void testMinWindow(){
    string S = "bdab";
    string T = "ab";
    string res = minWindow(S, T);
    printf("Finished");
}



