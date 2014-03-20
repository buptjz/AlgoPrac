//
//  longestNonDecreasingSequence.c
//  CiCT
//
//  11.7题
//
//  A circus is designing a tower routine consisting of people standing atop one another's shoulders.
//  For practical and aesthetic reasons, each person must be both shorter and lighter than the person
//  low him or her. Given the heights and weights of each person in the circus, write a method to
//  compute the largest possible number of people in such a tower.

#include <stdio.h>
#include <stdlib.h>
#include "arrayAndString.h"

typedef struct {
    int x;
    int y;
    int extra;
}TowerNode;

void sortTower(TowerNode **tower,int num){
    //To Do:应该根据x对其进行排序，这里就不排序了
    //需要注意的是，如果x相同，那么把y小的排在前面
}

TowerNode ** longestTower(TowerNode **tower,int num,int* theLength){
    if (tower == NULL) return NULL;
    int latestIndex = 0;//记录最后一个元素的位置
    int maxlength = 0;//用来记录最长非降序列的元素数量
    TowerNode *latest;//用来记录最长非降序列的最后一个item
    sortTower(tower,num);//根据x进行排序
    
    tower[0]->extra = 1;//设置第一个，后面循环从第二个数开始
    
    /******************遍历标记每个元素（包含本元素的最长非降序列的元素个数）O(N2)******************/
    for (int i = 1; i < num; i++) {
        for (int j = 0; j < i; j++) {
            //后面的tower高，而且后面的tower元素数比较少
            if (tower[i]->y >= tower[j]->y && tower[i]->extra < tower[j]->extra){
                tower[i]->extra = tower[j]->extra;
            }
        }
        tower[i]->extra++;
        if (tower[i]->extra >= maxlength) {
            maxlength = tower[i]->extra;
            latest = tower[i];
            latestIndex = i;
        }
    }//至此，已经标记了所有包含本元素的最长非降序列的元素数量
    
    //theLength的作用是返回给调用的函数，告诉它找到的非降序列有多长
    *theLength = maxlength;
    
    /****************开始拼合返回数组，O(N)，从latestIndex-1的位置依次向前找********************/
    TowerNode **res = malloc(sizeof(TowerNode*)*maxlength);
    res[--maxlength] = latest;
    for (int i = latestIndex-1; i >= 0; i--) {//从子序列的最后一个元素的前一个元素找起
        if (maxlength == 0) break;
        //如果前一个元素的y比序列中的元素y小(等于也可以)，并且其extra整好小1，那么判定它是属于我们的最长非降序列中的
        if (tower[i]->extra == maxlength && tower[i]->y <= res[maxlength]->y) {
            res[--maxlength] = tower[i];
        }
    }
    return res;
}

void testLongestTower(){
    int a[6] = {1,2,3,4,5,6};
    int b[6] = {1,1,1,1,1,1};
    TowerNode ** tower = malloc(sizeof(TowerNode*)*6);
    for (int i = 0; i < 6; i++) {
        TowerNode *temp = malloc(sizeof(TowerNode*));
        temp->x = a[i];
        temp->y = b[i];
        temp->extra = 0;
        tower[i] = temp;
    }
    int theLength;
    TowerNode **res = longestTower(tower, 6,&theLength);
    for (int i = 0; i<theLength; i++) {
        printf("%d\t%d\n",res[i]->x,res[i]->y);
    }
    printf("Finished\n");
}




