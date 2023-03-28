#include<string>
using namespace std;

1.定义
    string str;
    //直接赋值进行初始化
    string str="abcd";

    1.输入输出用cin，cout

    2.若用printf,scanf：
    用c_str()转化为字符数组:printf("%s".s.c_str())
    
    3.读取一整行(包含空格)
    getline(cin,s);

2.访问
    (1) 下标
        str[i];
    (2) 迭代器
        string::iterator it;
        printf("%c",*it);
        支持 str.begin()+3;

        //反向迭代器
        auto it=s.rbegin();
        
        //获取最后一个字符
        char c=s.back();

3.常用函数
    (1) +=//字符串拼接
        str3=str1+str2;
    (2) compare operator : == , != , < , <= , > , >= //通过字典序比较符号
    
    (3) str.length() , str.size();

    (4) str.insert(pos,string);//在pos(int)位置插入string字符串，名字或直接给出皆可

        str.insert(it,it2,it3);//it2,it3为待插字符串的首尾迭代器[it2,it3)
            例：
            string str="abcxyz",str2="opq";
            str.insert(str.begin()+3,str2.begin(),str2.end());
            //得到 abcopqxy
    
    (5) str.erase();//删除后自动补上
        str.erase(it);//删除单个元素

        str.erase(first,last);

        str.erase(pos,length);
    
    (6) str.clear();
    (7) str.substr(pos,len);//返回从 pos 开始，长度为 length 的子串

    (8) string::npos//一个常数，作为find函数失配时的返回值，值为-1或4295967295

    (9) str.find(str2);//当 str2 为 str 的子串时，返回其第一次出现的位置;不是则返回 string::npos   
        str.find(str2,pos);//从pos位置开始找
        例：
        string str="Thank you for your smile.";
        string str2="you";
        string str3="me";
        if(str.find(str2)!=string::npos){}//输出6
        if(str.find(str2,7)!=string::npos){}//输出14

    (10) str.replace(pos,len,str2);//从 pos 位置开始，长度为 len 的子串替换为str2
         str.replace(it1,it2,str2);// [it1,it2) 范围的子串替换为str2

    (11) //返回字符串对应的数字
        int stoi()      
        long long stoll()
        double stod()

    (12) string s = to_string(i); //将数字 i 转换为字符串表示形式


