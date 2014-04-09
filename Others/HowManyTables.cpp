//
//  HowManyTables.cpp
//  Algorithms
//
//  Created by WangJZ on 14-4-9.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//  http://acm.hdu.edu.cn/showproblem.php?pid=1213

/*
 并查集的练习题
 */

#include <stdio.h>

int father[1005];
int find(int x){
    //压缩法：回溯的时候压缩树的高度
    if (father[x] != x){
        father[x] = find(father[x]);
    }
    return father[x];
}
void build(int n){
    for (int i = 0; i <= n; i++)
        father[i] = i;
}

void Union(int x,int y){
    x = find(x);
    y = find(y);
    if (x == y) return;
    father[x] = y;
}

int howManyTables()
{
    int T,n,m,i,x,y;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        build(n);
        while(m--)
        {
            scanf("%d%d",&x,&y);
            Union(x,y);
        }
        int ans = 0;
        for(i = 1 ; i <= n ; i ++)
            if(father[i] == i) ans ++;
        printf("%d\n",ans);
    }
    return 0;
}
