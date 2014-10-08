//
//  WordLadderII.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-8.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_backtrack.h"
#include <map>
#include <list>
#include <queue>

struct WordNode{
    string word;
    int distance;
    vector< WordNode*>* preNodes;
    WordNode(string word,int distance){
        this->word = word;
        //distance 相当于level，设置这个level非常有用！让每个节点分等级了，在后文判断一个节点是否是某个节点的下一个层级
        this->distance = distance;
        this->preNodes = new vector< WordNode*>();
    }
};

class Solution {
public:
    vector< vector< string>> findLadders(string start, string end, unordered_set< string> &dict){
        vector< vector< string>> result;
        list<string> temp;
        map<string ,WordNode*> used;
        WordNode* endNode = NULL;
        queue<WordNode* >que;
        if(start == end){
            vector< string> newRe;
            newRe.push_back(start);
            result.push_back(newRe);
            return result;
        }
        WordNode startNode(start,1);
        que.push(&startNode);
        used[start] = &startNode;
        int maxStep = (int)dict.size() + 2;
        while(!que.empty()){
            WordNode *keyNode = que.front();
            que.pop();
            if(keyNode->distance>maxStep) break;
            for(int i = 0; i < keyNode->word.size(); i++){
                char oldch = keyNode->word[i];
                string newstr = keyNode->word;
                for (char ch = 'a'; ch <= 'z';ch++){
                    if (oldch == ch) continue;
                    newstr[i] = ch;
                    if(newstr == end){
                        maxStep = keyNode->distance;
                        if(endNode == NULL) endNode = new WordNode(newstr,keyNode->distance+1);
                        endNode->preNodes->push_back(keyNode);
                        continue;
                    }
                    //候选字符串在字典中有
                    if(dict.find(newstr) != dict.end()){
                        //该string已经使用过，并且是当前节点下一个level的string，则设置当前节点为该字符串的前驱
                        if(used.find(newstr) != used.end() &&
                           used[newstr]->distance>keyNode->distance){
                            used[newstr]->preNodes->push_back(keyNode);
                        }else if(used.find(newstr) == used.end()){
                            //该string没有使用过，需要创建
                            WordNode*  newNode = new WordNode(newstr,keyNode->distance+1);
                            newNode->preNodes->push_back(keyNode);
                            used[newstr] = newNode;
                            que.push(newNode);
                        }
                    }
                }
            }
        }
        this->createRe(result,temp,endNode);
        return result;
    }
    
    void createRe(vector< vector< string>> &result,list< string> &temp,WordNode* endNode){
        if(endNode == NULL) return;
        temp.push_front(endNode->word);
        if(endNode->preNodes->size()==0){
            vector< string> *newRe = new vector< string>();
            list< string>::iterator it = temp.begin();
            while(it != temp.end()){
                newRe->push_back(*it);
                it++;
            }
            result.push_back(*newRe);
        }else{
            for(int i=0;i< endNode->preNodes->size();i++){
                createRe(result,temp,endNode->preNodes->at(i));
            }
        }
        temp.pop_front();
    }
};
