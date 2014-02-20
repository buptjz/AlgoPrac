//
//  PermutationsUnique.cpp
//  LeetCode
//  全排列：并且数字之间是有重复的！
//  Created by WangJZ on 14-2-20.
//  使用的是递归的解法，想法有点繁琐，应该回来再看，主要是1）dfs前先排序；2）isVisited的使用，它的意思是：如果俩重复的数，如果前面一个在用，那么后面这个就不能用，直到递归回去到下一个level的时候，上一个level正在使用的点才变成不用的，这个时候后面一个数才能使用，后面一个数使用的时候不影响前面重复数的使用，所以这样算来重复数只出现一次，不会出现多次！
//  http://oj.leetcode.com/problems/permutations-ii/

#include "PermutationsUnique.h"
#include <vector>
#include <stdlib.h>

using namespace std;

void permuteUniqueHelper(int index, vector<int>&num, vector<int>&tmp, vector<vector<int> >&ret, vector<bool>&isVisited)
{
    if(index == num.size())
    {
        ret.push_back(tmp);
        return;
    }
    for(int i = 0; i < num.size(); ++i)
    {
        if(isVisited[i] || (i != 0 && num[i] == num[i - 1] && isVisited[i - 1]))continue;
        isVisited[i] = true;
        tmp.push_back(num[i]);
        permuteUniqueHelper(index + 1, num, tmp, ret, isVisited);
        isVisited[i] = false;
        tmp.pop_back();
    }
}

vector<vector<int> > permuteUnique2(vector<int> &num)
{
    vector<vector<int> > ret;
    if(num.size() == 0)
        return ret;
    sort(num.begin(), num.end());
    vector<bool> isVisited(num.size(), false);
    vector<int> tmp;
    permuteUniqueHelper(0, num, tmp, ret, isVisited);
    return ret;
}


void testPermuteUnique(){
    vector<int> num = {2,2};
    vector<vector<int>> ret = permuteUnique2(num);
    
    printf("Finished\n");
}
