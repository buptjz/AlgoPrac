//
//  charReplace.c
//  CiCT
//
//  Created by Wang JZ on 13-9-6.
//  Copyright (c) 2013年 Wang JZ. All rights reserved.
//

#include <stdio.h>
#include "arrayAndString.h"

void charReplace(char *p);

/**
 Question Description: Given a String s,Replace the space with %20.
 Do it in place.(From CiCT 5th edition,P73,Interview Questions 1.4)
 
 Answer:Go through the string find how many spaces in it.Then go back,when find a space,move all the characters after this space to the right place.
 By WangJZ,2013_9_6
 **/
void charReplace(char *p){
    int n = 0;
    int length = 0;
    char *t,*q;
    while (*p != '\0') {
        if (*p == ' ') {
            n++;//Count how many space in this string
        }
        p++;
        length++;
    }
    *(p + 2 * n) = '\0';
    int k = 0;//Count how many characters after space
    while (length > 0) {
        p--;
        length--;
        k++;
        if (*p == ' ') {
            t = p + 1;
            q = t + 2 * n;
            for (; k > 1; k--) {
                *q = *t;
                q++;
                t++;
            }
            t = p + 1 + 2 * n - 3;
            *t = '%';
            *(t+1) = '2';
            *(t+2) = '0';
            k = 0;
            n--;
        }
    }
    printf("%s",p);
}