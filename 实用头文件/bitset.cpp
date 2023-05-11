#include <bitset>
using std::bitset;
//bitset提供了一种数据结构，每个元素只能是０或１，每个元素仅用１bit空间
//方便处理二进制位的有序集，或者每个位可能包含的是0（关）或1（开）的值


//1.定义与初始化
    bitset<4> b;                //b有4位，每位都为0
    bitset<10> b(u);	        //b是unsigned long型u的一个副本,长度为10
    bitset<10> b(s);	        //b是string对象s中含有的位串的副本
    bitset<120> b(s, pos, n);	//b是s中从位置pos开始的n个位的副本

    //给出的长度值必须是常量表达式

//2.初始化与赋值

    //若长度多余，高位补0
    //若长度不足，高位舍弃

//3.成员函数
    b.to_ulong()    //返回一个unsigned long 值
    b.any()         //b是否存在1?
    b.count()       //b中1的个数
    b[pos]          //b在pos位置的二进制位
    b.set()         //把b所有位 置为1
    b.set(pos)      //把b pos位 置为1
    b.reset()       //把b所有位 置为0