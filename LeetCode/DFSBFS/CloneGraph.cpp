//
//  CloneGraph.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-4.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_others.h"

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

map<UndirectedGraphNode*, UndirectedGraphNode *> dic;
void helper(UndirectedGraphNode *node){
    if (dic.find(node) == dic.end()) {
        dic[node] = new UndirectedGraphNode(node->label);
    }
    for (int i = 0; i < node->neighbors.size(); i++) {
        if (dic.find(node->neighbors[i]) == dic.end()) {
            dic[node->neighbors[i]] = new UndirectedGraphNode(node->neighbors[i]->label);
            dic[node]->neighbors.push_back(dic[node->neighbors[i]]);
            helper(node->neighbors[i]);
        }else{
            dic[node]->neighbors.push_back(dic[node->neighbors[i]]);
        }
    }
}
UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if (node == nullptr) return nullptr;
    UndirectedGraphNode *root = new UndirectedGraphNode(node->label);
    dic[node] = root;
    helper(node);
    return root;
}
