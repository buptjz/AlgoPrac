//
//  PermutationsUnique.cpp
//  LeetCode
//  全排列：并且数字之间是有重复的！
//  Created by WangJZ on 14-2-20.
//  使用的是递归的解法，想法有点繁琐，应该回来再看，主要是1）dfs前先排序；2）isVisited的使用，它的意思是：如果俩重复的数，如果前面一个在用，那么后面这个就不能用，直到递归回去到下一个level的时候，上一个level正在使用的点才变成不用的，这个时候后面一个数才能使用，后面一个数使用的时候不影响前面重复数的使用，所以这样算来重复数只出现一次，不会出现多次！
//  http://oj.leetcode.com/problems/permutations-ii/

// 2014.2.22更新 上述解法存在一些问题，如果题目要求是从n个可重复的数中输出k个数的全排列（k!=n）那么上述会出现问题，例如{1,2,2,2}会输出10个数
//修改方案是使用一个变量记录上次本位置上的选择，例如1之后会选第2个数2，完成后会选择第三个数，是2，与上一次选择重了，就放弃这次选择，其核心思想是保证每一个位置有n个可能，其中重复的选择只选择一次，由于数组是排好顺序的，所以重复的数都挨着，不会被重复选择上。


#include "leetcode_permutation.h"

void permuteUniqueHelper(int level, vector<int>&num, vector<int>&tmp,
                         vector<vector<int> >&ret, vector<bool>&isVisited,int lenght)
{
    if(level == lenght)//递归终止条件
    {
        ret.push_back(tmp);
        return;
    }
    //依次选择该位置上得每一个候选者
    int lastNumber = -8888;
    for(int i = 0; i < num.size(); ++i)
    {
        //如果本候选者和上一个候选者重复，那么跳过这个候选者
        if(isVisited[i] || num[i] == lastNumber)continue;
        isVisited[i] = true;
        lastNumber = num[i];
        tmp.push_back(num[i]);
        permuteUniqueHelper(level + 1, num, tmp, ret, isVisited,lenght);
        isVisited[i] = false;
        tmp.pop_back();
    }
}
vector<vector<int> > permuteUnique(vector<int> &num)
{
    vector<vector<int> > retVec;
    sort(num.begin(), num.end());//原地排序
    vector<bool> isVisited(num.size(), false);
    vector<int> tmp;
    int lenght = (int)num.size();//这里的length可以取其它值k，变为n选k的全排列
    permuteUniqueHelper(0, num, tmp, retVec, isVisited,lenght);
    return retVec;
}


void testPermuteUnique(){
    vector<int> num = {1,2,2,2};
    vector<vector<int>> ret = permuteUnique(num);
    printf("Finished\n");
}
