//
//  main.c
//  CiCT
//
//  Created by Wang JZ on 13-8-25.
//  Copyright (c) 2013年 Wang JZ. All rights reserved.
//

#include <stdio.h>
#include "arrayAndString.h"


int main(int argc, const char * argv[])
{
    //char a[] = "wordar";
    //int is = isUnique3(a);
    //printf("%d",is);
    char p[] = "aa";
    //stringInverse(p);
    //charReplace(p);
    //testPointer(p);
    char *a = stringCompress(p);
    //printf("%s",a);
    return 0;
}

