//
//  SimplifyPath.cpp
//  LeetCodeReview
//
//  Created by WangJZ on 14-10-2.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_others.h"


string simplifyPath(string path) {
    vector<string> vec;
    
    int index = 0;
    int start = 0;
    while (index <= path.length()) {
        if (index == path.length() || path[index] == '/') {
            if (start <= index - 1) {
                string tmp = path.substr(start,index - start);
                if (tmp == "..") {
                    if (!vec.empty()) vec.pop_back();
                }else if(tmp == "."){
                
                }else{
                    vec.push_back(tmp);
                }
            }
            start = index + 1;
        }
        index++;
    }
    
    if (vec.empty()) return "/";
    
    string ret;
    for (string s : vec){
        ret += "/";
        ret += s;
    }
    return ret;
}

void testSimplifyPath(){
    string path = " ";
    string ans = simplifyPath(path);
    cout<<ans<<endl;
}