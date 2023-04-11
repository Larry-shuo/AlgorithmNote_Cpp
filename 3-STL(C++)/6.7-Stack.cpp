#include<bits/stdc++.h>
using namespace std;

//1.定义
    stack<typename> st;
//2.访问
    后进后出的数据结构，只能访问栈顶元素
    st.top();
3.函数
    (1) st.push(x);

    (2) st.top();

    (3) st.pop();

    (4) st.empty();

    (5) st.size();


    st.emplace();//构造元素并插入
    //例如：
    stack<pair<string,int> >st;
    st.emplace("abc",3)


4.用途
    模拟递归等