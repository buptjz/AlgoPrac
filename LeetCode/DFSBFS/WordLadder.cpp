//
//  WordLadder.cpp
//  Algorithms
//
//  Created by WangJZ on 14-3-27.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/word-ladder/

/*
 【思路】看做是一个图的问题，每个单词是一个节点，如果单词之间能够通过一个字符的改变互相转换，那么这两个单词之间有一条边
 问题一：怎样找到一个word的下一个word？
 网上很多人的思路是通过循环word的每一个位置，通过改变每一个位置上的字符（从a-z），生成一个新的word，在set中查看是否有这个word，有的话就可以作为候选者之一。
 这个显然经过了两次遍历，我的想法是能不能用一个map，key是word本身，value是一个vector，保存它所有下个节点（没有去实现这种思路）
 
 问题二：搜索策略
 这道题是为数不多的用BFS策略的题目，使用BFS更快，但是费空间，需要记录
 
 问题三：可以优化的地方
word A 找到一个候选word B之后，word B就可以从set删除了，因为和A在同一层上的单词，即便下一个是B,那么因为我们计算的是最短路径，这两种路径是一样长的，能达到就都能达到（并且一样长度），不能达到就都不能达。

 问题四：特别注意的语言技巧
 vector的合并（或者说是追加）
 将B追加大A上。用A.insert(A.end(), B.begin(), B.end());
 */

#include "leetcode_others.h"
#include <unordered_set>

//根据一个word在字典中找到所有和该string只差一个字符的words
vector<string> getCandidates(unordered_set<string> &dict,const string &target){
    vector<string> retStrings;
    string temp;
    //遍历单词的每一个位置
    for (int i = 0; i < (int)target.size(); i++) {
        //遍历每一个字母
        temp = target;
        for (char j = 'a';j <='z'; j++) {
            temp[i] = j;
            unordered_set<string>::iterator it = dict.find(temp);
            if (it != dict.end()) {
                retStrings.push_back((*it));
                dict.erase(it);//找到后即删除
            }
        }
    }
    return retStrings;
}

int ladderLength(string start, string end, unordered_set<string> &dict) {
    dict.insert(end);
    vector<string> currentVec,eachCandisCandidates,temp;

    currentVec.push_back(start);
    int retValue = 1;
    //BFS
    while (currentVec.size() != 0) {
        temp = currentVec;
        currentVec.erase(currentVec.begin(),currentVec.end());
        for (int i = 0; i < (int)temp.size(); i++) {
            if(temp[i] == end) return retValue;
            eachCandisCandidates = getCandidates(dict, temp[i]);
            currentVec.insert(currentVec.end(), eachCandisCandidates.begin(), eachCandisCandidates.end());
        }
        retValue ++;
    }
    return 0;
}