//
//  CloneGraph.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-18.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_others.h"

static void traverse(UndirectedGraphNode *node,map<UndirectedGraphNode *, UndirectedGraphNode *> &map){
    vector<UndirectedGraphNode *> neighbors = node->neighbors;
    for (int i = 0; i < neighbors.size(); i ++){
        if (map.find(neighbors[i]) != map.end()) {//neighbor 访问过
            map[node]->neighbors.push_back(map[neighbors[i]]);
        }else{//neighbor 没有访问过
            UndirectedGraphNode *copyNeighbor = new UndirectedGraphNode(neighbors[i]->label);
            map[node]->neighbors.push_back(copyNeighbor);
            map[neighbors[i]] = copyNeighbor;
            traverse(neighbors[i], map);
        }
    }
}
UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if (node == NULL) return NULL;
    map<UndirectedGraphNode *, UndirectedGraphNode *> n2n_map;
    n2n_map[node] = new UndirectedGraphNode(node->label);
    traverse(node, n2n_map);
    return n2n_map[node];
}
