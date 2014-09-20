//
//  struct_head.h
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-17.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#ifndef LeetCodeReview_struct_head_h
#define LeetCodeReview_struct_head_h

#include <vector>
using namespace std;

struct TreeLinkNode {
      int val;
      TreeLinkNode *left, *right, *next;
      TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
    };

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


struct UndirectedGraphNode {
         int label;
         vector<UndirectedGraphNode *> neighbors;
         UndirectedGraphNode(int x) : label(x) {};
     };

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x),next(NULL){}
};
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

struct RandomListNode {
        int label;
        RandomListNode *next, *random;
       RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

#endif
