//
//  stringCompress.c
//  CiCT
//
//  Created by Wang JZ on 13-9-9.
//  Copyright (c) 2013年 Wang JZ. All rights reserved.
//
/**
 
 CiCT P73 1.5
 Implement a method to perform basic string compression using the counts of repeated
 characters.For example,the string aabccccaaa would become a2b1c5a.If the compressed
 string would not become smaller than the original string, your method should return
 the original string.
 
 WangJZ 2013—9-9
 
 **/

#include <stdio.h>
char* stringCompress(char *p);
char* stringCompress(char *p){
    char q[100];
    char *com = q;
    char *compress = q;
    char *ori = p;
    int comlen = 0;
    int len = 1;
    int repeat = 1;
    char rechar = p[0];
    p++;
    while (*p != '\0') {
        len +=1;
        if (*p == rechar) {
            repeat ++;
        }
        else{
            *com = rechar;
            com++;
            *com = '0' + repeat;
            com++;
            repeat = 1;
            rechar = *p;
            comlen += 2;
        }
        p++;
    }
    *com = rechar;
    com++;
    *com = '0' + repeat;
    com++;
    *com = '\0';
    comlen += 2;
    
    if (comlen >= len) {
        return ori;
    }
    else return compress;
}
