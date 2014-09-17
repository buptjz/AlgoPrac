//
//  LRUCache.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-9-15.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  https://oj.leetcode.com/problems/lru-cache/

/*
 [Description]
 
 Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.
 
 get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
 
 */

/*
 LRU 和我想的LRU不太一样：
 1. 新数据插入到链表头部；
 2. 每当缓存命中（即缓存数据被访问），则将数据移到链表头部；
 3. 当链表满的时候，将链表尾部的数据丢弃。
 */

#include "leetcode_others.h"

struct LRUCacheItem{
    int key;
    int value;
    LRUCacheItem(int key,int value):key(key),value(value){}
};

class LRUCache{
public:
    int m_capacity;
    map<int,list<LRUCacheItem>::iterator> m_map;
    list<LRUCacheItem> m_list;
    
    LRUCache(int capacity) {
        m_capacity = capacity;
    }
    
    int get(int key) {//get the value from the key,add 1 to the use times.
        if (m_map.find(key) == m_map.end()) {
            return -1;
        }else{
            moveToHead(key);
            return m_map[key]->value;
        }
    }
    
    void set(int key, int value) {
        //if space enough, set the key for the value,set the current capacity + 1
        //if not , delete the least recently used one and then
        if (m_map.find(key) != m_map.end()) {
            m_map[key]->value = value;
            moveToHead(key);
        }else{
            if (m_list.size() == m_capacity) {
                m_map.erase(m_list.back().key);
                m_list.pop_back();
            }
            m_list.push_front(LRUCacheItem(key,value));
            m_map[key] = m_list.begin();
        }
    }
    
private:
    void moveToHead(int key){
        int value = m_map[key]->value;
        m_list.erase(m_map[key]);
        m_list.push_front(LRUCacheItem(key,value));
        m_map[key] = m_list.begin();
    }
};

