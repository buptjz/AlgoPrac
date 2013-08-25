//
//  main.c
//  CiCT
//
//  Created by Wang JZ on 13-8-25.
//  Copyright (c) 2013年 Wang JZ. All rights reserved.
//

#include <stdio.h>

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

int main(int argc, const char * argv[])
{

    // insert code here...
    printf("Hello, World!\n");
    char a[] = "abcdefge";
    int is = isUnique(a);
    printf("%d",is);
    return 0;
}

