//
//  twoStacksQueue.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-15.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  用两个栈来模拟队列

#include "twoStacksQueue.h"
#include <stack>
#include <assert.h>
using namespace std;

class CQueue{
public:
    void enqueue(int val){
        st1.push(val);
    }
    int dequeue(){
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        assert(!st2.empty());
        int ret = st2.top();
        st2.pop();
        return ret;
    }
private:
    stack<int> st1,st2;
};

void testCQueue(){
    CQueue cq;
    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    int x = cq.dequeue();
    cq.enqueue(4);
    cq.enqueue(5);
    int y = cq.dequeue();
    
}
