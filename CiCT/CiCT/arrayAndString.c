//
//  arrayAndString.c
//  CiCT
//
//  Created by Wang JZ on 13-8-25.
//  Copyright (c) 2013年 Wang JZ. All rights reserved.
//

#include <stdio.h>
#include "arrayAndString.h"
#include <string.h>

int isUnique(char a[]);
int isUnique2(char a[]);
int isUnique3(char a[]);
void stringInverse(char *p);
/*O(n2)*/
int isUnique(char a[]){
    int i = 0;
    while (a[i]!='\0') {
        for (int j = 0; j<i; j++) {
            if (a[j] == a[i]) {
                return 0;
            }
        }
        i++;
    }
    return 1;
}

/*Using list,less Complexity,O(n)*/
int isUnique2(char a[]){
    int check[256] = {0};
    int i = 0;
    while (a[i] != '\0') {
        if (check[i] == 1) {
            return 0;
        }
        check[i] = 1;
        i++;
    }
    return 1;
}

/*Using bit vector,less space*/
int isUnique3(char a[]){
    int checker = 0;
    int i = 0;
    while (a[i]!='\0') {
        int index = a[i] - 'a';
        if (((1<<index) & checker) != 0) {
            return 0;
        }
        checker |= (1<<index);
        i++;
    }
    return 1;
}

void stringInverse(char *p){
    int length = (int)strlen(p);
    int half = (int)length / 2 - 1;
    char temp;
    for (int i = 0; i <= half; i++) {
        temp = p[i];
        p[i] = p[length - i - 1];
        p[length - i - 1] = temp;
    }
}
