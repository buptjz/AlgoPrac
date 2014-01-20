//
//  2Sum.cpp
//  LeetCode
//
//  Created by WangJZ on 14-1-20.
//  http://oj.leetcode.com/problems/two-sum/
//

#include "2Sum.h"
#include <vector>
#include<iostream>
using namespace std;

typedef int KeyType; //设关键字域为整形,需要修改类型时，只需修改这里就可以
const int NULLKEY=-300090; //NULLKEY表示该位置无值
int c=0; //用来统计冲突次数

struct Elemtype //数据元素类型
{
    KeyType key;
    int ord;
    // Elemtype(int x,int y) : ord(x), key(y){}
};

int hashsize[]={503,3037,60000,600010}; //hash表容量递增表
int Hash_length=0;//hash表表长


class HashTable
{
private:
    Elemtype *elem; //数据元素数组,动态申请
    int count;// 当前数据元素个数
    int size; //决定hash表的容量为第几个,hashsize[size]为当前hash容量
public:
    
    int Init_HashTable() //构造一个空hash表
    {
        int i;
        count=0;
        size=0; //初始化容量为hashsize[0]=11
        Hash_length=hashsize[0];
        elem=new Elemtype[Hash_length];
        if(!elem)
        {
            cout<<"内存申请失败"<<endl;
            exit(0);
        }
        for(i=0;i<Hash_length;i++)
            elem[i].key=NULLKEY;
        return 1;
    }
    
    
    unsigned Hash(KeyType k) //hash函数的一种(取模法)
    {
        return k%Hash_length;
    }
    
    void Collision(int &p,int d) //解决冲突
    {
        p=(p+d)%Hash_length; //采用开放地址法里的线性探测
    }
    
    bool Search_Hash(KeyType k,int &p) //查找
    {
        //在开放地址hash表中查找关键字等于k的元素
        //若找到用p表示待查数据,查找不成功时，p指向的是可插入地址
        c=0;
        p=Hash(k); //求hash地址
        while(elem[p].key!=NULLKEY && elem[p].key!=k)
        {
            c++;
            if(c<Hash_length)
                Collision(p,c);
            else
                return 0; //表示查找不成功
        }
        if(elem[p].key==k)
            return 1;
        else
            return 0;
        
    }
    
    int Insert_Hash(Elemtype e) //插入
    {
        //在查找不成功的情况下将k插入到hash表中
        int p;
        if(Search_Hash(e.key,p))
            return -1; //表示该元素已在hash表中
        else if(c<hashsize[size]/2) //冲突次数未达到上限
        {
            //插入e
            elem[p]=e;
            count++;
            return 1;
        }
        else
            ReCreate_HashTable(); // 重建hash表
        return 0; //插入失败
    }
    
    void ReCreate_HashTable() //重建hash表
    {
        int i,count2=count;
        Elemtype *p,*elem2=new Elemtype[count];
        p=elem2;
        for(i=0;i<Hash_length;i++) //将原有元素暂存到elem2中
            if(elem[i].key!=NULLKEY)
                *p++=*(elem+i);
        count=0;delete []elem;
        size++; //hash容量增大
        Hash_length=hashsize[size];
        p=new Elemtype[Hash_length];
        if(!p)
        {
            cout<<"空间申请失败"<<endl;
            exit(0);
        }
        elem=p;
        for(i=0;i<Hash_length;i++)
            elem[i].key=NULLKEY;
        for(p=elem2;p<elem2+count2;p++) //将原有元素放回新表
            Insert_Hash(*p);
    }
    
    
    int Get_Data(int p)
    {
        return elem[p].ord;
    }
    
};

vector<int> twoSum(vector<int> &numbers, int target) {
    int length = (int)numbers.size();
    HashTable H;
    int p,index1 = 0,index2 = 0;
    KeyType k;
    H.Init_HashTable();
    for (int i = 0; i < length; i++) {
        k = target - numbers[i];//我们要查找的值
        if(H.Search_Hash(k,p)) {
            index1 = H.Get_Data(p);
            index2 = i;
            break;
        }else{
            Elemtype *e = new Elemtype();
            e->key = numbers[i];//我们要插入的key
            e->ord = i;
            H.Insert_Hash(*e);
        }
    }
    vector<int> retVec = {index1+1,index2+1};
    return retVec;
}


void testTwoSum()
{;
    
    vector<int> input = {0,4,3,0};
    vector<int> ret = twoSum(input, 16021);
    printf("finished\n");
}
