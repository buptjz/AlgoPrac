//
//  InterleavingString.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-7.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

#include "leetcode_string.h"

string a1,a2,a3;

bool helper(int index1,int index2,int index3){
    if (index3 == a3.size()) return true;
    if (a3[index3] == a1[index1])
        if (helper(index1 + 1, index2, index3 + 1))
            return true;
    if (a2[index2] == a3[index3])
        if (helper(index1, index2 + 1, index3 + 1))
            return true;
    
    return false;
}

bool isInterleave(string s1, string s2, string s3) {
    a1 = s1;
    a2 = s2;
    a3 = s3;
//    int aa = s1.size();
//    int bb = s2.size();
//    int cc = s3.size();
    return helper(0, 0, 0);
}

void testIsInterleave(){
    bool res = isInterleave("bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa", "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab", "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab");
    cout<<res<<endl;
}
