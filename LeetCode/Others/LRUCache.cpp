//
//  LRUCache.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-6.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/lru-cache/

/*
 参考了http://fisherlei.blogspot.com/2013/11/leetcode-lru-cache-solution.html
 几个要点：
 1）保存iterator，删除其他的项，不改变本项目的iterator
 
 2）要能通过key直接找到value，需要用map
 3）全程的难点在于如何set，因为set涉及到删除最遥远调用的item，这个item就要保存在线性结构中，所以综合2、3点需要用到两个数据结构，map和list（因为list可以很快的找到back和pushfront）
 */


#include "leetcode_others.h"
#include <list>
class LRUCache{
private:
    struct LRUCacheItem{
        int key;
        int value;
        LRUCacheItem(int k,int v):key(k),value(v){};
    };
    
    map<int, list<LRUCacheItem>::iterator> m_map;
    list<LRUCacheItem> m_list;
    int m_capacity;
    
public:
    void MoveToHead(int key){
        LRUCacheItem updateEntry = *(m_map[key]);
        m_list.erase(m_map[key]);
        m_list.push_front(updateEntry);
        m_map[key] = m_list.begin();
    }
    
    LRUCache(int capacity) {
        m_capacity = capacity;
    }
    
    int get(int key) {
        if (m_map.find(key) == m_map.end()) return -1;
        else{
            MoveToHead(key);
            return m_map[key]->value;
        }
    }
    
    void set(int key, int value) {
        if (m_map.find(key) == m_map.end()) {//do not exist
            if (m_map.size() >= m_capacity) {
                m_map.erase(m_list.back().key);
                m_list.pop_back();
            }
            LRUCacheItem newItem(key,value);
            m_list.push_front(newItem);
            m_map[key] = m_list.begin();
        }else{
            m_map[key]->value = value;
            MoveToHead(key);
        }
    }
};