#include<vector>
using namespace std;

//1.定义
    vector<int> name;
    vector<vector<int> > name; // > >之间有一个空格，防止被认为是>>移位操作
    //vector数组
    vector<int> vi[100];

    //自定义vector大小与初值
    vector<int> vi(n,1); //大小为n（可以为变量），值全为1
    vector<vector<int> > name(n, vector<int>(m, 1)); //大小为n*m，初值为1
    vector A(n, vector(m,vector<int>(k)));//三维 n * m * k

2.访问
    (1) 下标
        vi[0],vi[vi.size()-1]
    (2) 迭代器  例子：
        int main()
        {
            vector<int> vi;
            for(int i=1;i<=5;i++){
                vi.push_back(i);
            }

            写法1：
            vector<int>::iterator it=vi.begin();
            for(int i=0;i<5;i++){
                cout<<*(it+i);
            }

            写法2：
            for(vector<int>::iterator it=vi.begin();it!=vi.end();it++){}
            for(auto it=vi.begin();it!=vi.end();it++){}
        }
    vi.end()为尾元素的下一位地址//习惯左开右闭  [ , )

    //只有vector和string允许 vi.begin()+1 这种写法

3.函数实例
    (1) vi.push_back(x);//尾部添加元素
    (2) vi.pop_back();//删除尾部元素
    (3) vi.size();//返回一个unsigned元素
    (4) vi.clear();
    (5) vi.insert(it,x);//it位置上插入x元素
    (6) vi.erase(it);
        vi.erase(first,last);//[first,last);
    (7) //两个vector之间可以判断是否相等
        if(vi1==vi2){}

    (8)截取vector
        1. 直接构造 vector<int> v2(v.begin(),v.begin()+j);
        
        2. assign() Arr.assign(First,Second);   //First和Second是迭代器, [First,Second)


4.用途
    (1).储存不确定个数的数据
    (2).存储邻接表

