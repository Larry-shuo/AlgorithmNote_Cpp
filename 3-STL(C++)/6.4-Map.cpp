#include<map>
using namespace std;

映射，从任何类型映射到任何类型,内部自动排序(红黑树)
默认自动排序，按键值从小到大

!!map是一个集合容器,并非序列容器(如vector等),所以不能用sort给map排序!!

1.定义
    map<typeneme,typeneme> mp;
        例：map<string,int> mp;
        map<set<int>,string> mp;

2.访问
    (1) 下标
        mp['a'](map中键是唯一的)

    (2) 迭代器
        map<,>::iterator it;
        例子:
            map<char,int> mp;
            mp['m']=20; //若'm'不存在于mp中，则自动添加这一对数据
            mp['r']=30;
            mp['a']=40;
            for(map<char,int>::iterator it=mp.begin(),it!=mp.end();it++)
                cout << it->first << it->second;//->first访问键，->second访问值

3.函数
    (1) mp.find(key)//返回键为ke y的迭代器
    
        if(mp.find(key)!=mp.end()){}

    (2) mp.erase(it)
        mp.erase(key);
        mp.erase(first,last);//[first,last) 是迭代器

    (3) mp.size();

    (4) mp.clear();

4.用途
    (1) 建立字符串（字符）与数字之间的映射
    (2) 判断大整数或其他数据类型是否存在,当作bool型使用
    (3) 字符串到字符串的映射

    #include<unordered_map>  /*unordered_map,不排序的map
    //map内部使用红黑树排序存放，unordered_map内部使用hash值存储，部分数据结构没有对应的hash值，例如vector,pair等


//5
map的键与值是唯一的，若需要一键对多值，使用multimap

//使用 insert() 添加元素
    multimap1.insert({1, "hello"});
    multimap1.insert(pair<int, string>(3, "scott"));
    multimap1.insert(pair(2, "C++17 wirte"));   //C++17 的写法s

    