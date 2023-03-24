#include<utility> 
或 
#include<map>//map中包含pair元素

1.定义
    pair<typename1,typename2> name;
    例：
        pair<string,int> p;p.first="abc";p.second=1;

        pair<string,int> p("haha",5);//定义时初始化

        p=pair<string,int>("haha",55);

        p=make_pair("haha",555);


2.访问
    pair中只有两个元素，first 和 second 两个元素
    p.first,p.second;
3.函数
    比较操作数：== , != , < , <= , > , >=
    先比较 first，相等的话比较 second


4.用途
    (1) 代替二元结构体及其构造函数
    (2) 作为map的键值对来进行插入数据
        例：
        map<string,int> mp;
        mp.insert(make_pair("assdfg",1223));
        mp.insert(pair<string,int>("asd",12));