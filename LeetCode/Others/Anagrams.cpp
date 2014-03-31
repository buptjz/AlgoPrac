//
//  Anagrams.cpp
//  Algorithms
//
//  Created by WangJZ on 14-3-31.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://oj.leetcode.com/problems/anagrams/

/*思路：
依次处理每一个string， 对string排序，在字典中查找，如果找到一样的，说明有anagrams，放在返回数组中，如果没有，添加到字典中，
 字典中的value是string的在原数组中的索引。
 [注意]怎样将在被匹配的string放入返回数组中，并且只放一次
 */
#include "leetcode_others.h"


vector<string> anagrams(vector<string> &strs) {
    vector<string> retVec;
    int length = (int)strs.size();
    map<string, int> ourMap;
    for (int i = 0; i < length; i++) {
        string current = strs[i];
        sort(current.begin(), current.end());
        map<string, int>::iterator it = ourMap.find(current);
        if ( it == ourMap.end()) {
            ourMap.insert(make_pair(current, i));
        }else{
            retVec.push_back(strs[i]);
            if (it->second != -1) {
                retVec.push_back(strs[it->second]);
                it->second = -1;
            }
        }
    }
    return retVec;
}

void testAnagrams(){
    vector<string> s = {"abc","cba","cab","aaa"};
    vector<string> rest = anagrams(s);
    printf("Finished\n");
}