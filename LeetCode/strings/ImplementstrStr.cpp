//
//  ImplementstrStr.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-15.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//


#include <string.h>
#include <iostream>
char *mystrStr(char *haystack, char *needle){
    int m = (int)strlen(haystack);
    int n = (int)strlen(needle);
    if(n == 0) return haystack;
    for(int i = 0; i <= m-n; i++){//尾部至少剩余n个数
        int j = 0;
        while(j < n){
            if(haystack[i+j]!=needle[j])
                break;
            j++;
        }
        if(j == n) return haystack+i;
    }
    return NULL;
}

void testStrStr(){
    char *hay = "a";
    char *needle = "a";
    char *x = mystrStr(hay, needle);
    printf("Finished\n");
    
}