//
//  SubstringwithConcatenationofAllWords.cpp
//  LeetCode
//
//  Created by WangJZ on 14-2-28.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/substring-with-concatenation-of-all-words/

#include "SubstringwithConcatenationofAllWords.h"
#include <vector>
#include <string>
using namespace std;

/*解法一,自己的方案，时间复杂度太高，有朋友给出了解法二，请参看下面的解法二*/
void findSubstringHelper(string S, vector<string> L,vector<int>&retVec,int start,int word_length){
    int current_index = start;
    while (true) {
        bool find = false;
        string cur(S,start,word_length);
        for (int i = 0; i < (int)L.size(); i++) {
            if (cur == L[i]) {
                find = true;
                start += word_length;
                L.erase(L.begin()+i);//删除第i个元素
                break;
            }

        }
        if (!find) {
            return;
        }
        if (((int)L.size()) == 0) {//如果L用完了，说明成功了！
            retVec.push_back(current_index);
        }
    }
}

vector<int> findSubstring2(string S, vector<string> &L) {
    vector<int> retVec;
    int NWords = (int)L.size();//单词个数
    if (NWords == 0) {
        return retVec;
    }
    
    int wordLen = (int)L[0].length();//每个单词都是一样的长度
    
    int stringLen = (int)S.length();
    for (int i = 0; i <= stringLen - NWords * wordLen; i++) {//如果后边的字母数量不足以找到所有的词，就不再继续了
        findSubstringHelper(S,L,retVec,i,wordLen);
    }
    return retVec;
}

/*
 解法二，来自这里
 http://oj.leetcode.com/discuss/366/better-solution-than-brute-force
 注意map的使用
 */

#include <map>
vector<int> res;
map<string,int> string_split_dic;
map<string,int> given_word_dic;
int string_len;

vector<int> findSubstring(string S, vector<string> &L){
    string_len = (int)S.length();
    int NWords = (int)L.size();
    int wordLen = (int)L[0].length();
    
    //构建给定单词的字典
    for(int i = 0; i < NWords ; i++){
        if(given_word_dic.count(L[i]) == 0){
            given_word_dic[L[i]] = 1;
        }else{
            given_word_dic[L[i]] += 1;
        }
    }
    
    string temp ,du;
    int NRecords = 0;
    int start_point = 0;
    
    for(int j = 0 ; j < wordLen ; j++){
        NRecords = 0;
        start_point = j;
        for(int i = j; i < string_len; i += wordLen){
            temp = S.substr(i,wordLen);
            if( given_word_dic.count(temp) == 0 || given_word_dic[temp] == 0 ){//当前单词在given words中没出现,一切重头来过
                string_split_dic.clear();
                NRecords = 0;
                start_point = i + wordLen;
            }else if(string_split_dic[temp] < given_word_dic[temp]){//当前单词在given words中出现，并且存在的次数大于已经出现的次数
                string_split_dic[temp] += 1;
                NRecords++;
            }else{//最复杂的一种情况，给定单词不够用了，从起点开始寻找，直到找到temp,并且中间的所有单词都作废,重新寻找起点
                du = S.substr(start_point,wordLen);
                while(du != temp){
                    string_split_dic[du]--;
                    NRecords--;
                    start_point += wordLen;
                    du = S.substr(start_point,wordLen);
                }
                start_point += wordLen;
            }
            if(NRecords == NWords){//如果找到记录数整好和单词数量吻合，那么是一种答案，从起点开始的下一个单词找起
                res.push_back(start_point);
                du = S.substr(start_point,wordLen);
                string_split_dic[du]--;
                NRecords--;
                start_point += wordLen;
            }
            
        }
        string_split_dic.clear();
    }
    sort(res.begin(),res.end());
    return res ;    
}

void testFindSubstring(){
    string S = "foobar";
    vector<string> L= {"foo","bar"};
    
    vector<int> x = findSubstring(S, L);
    printf("Finished");
}

