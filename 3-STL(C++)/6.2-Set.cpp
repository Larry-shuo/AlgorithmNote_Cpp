//内部自动 递增 有序，不含重复元素
#include<set>
#include<unordered_set>
using namespace std;

1.定义
    set<typename> name;
    set<int> st;
    set<set<int> > stt;
    set<int> a[100];

    //多重集
    multiset<int> S;

    //无序集,内部以散列代替红黑树，速度更快，内部元素顺序与添加元素顺序无关!!
    unordered_set<int> S;

2.元素访问
    //只能通过迭代器访问
    set<char>::iterator it=st.begin(); 

    for(set<int>::iterator it=st.begin() ; it!=st.end() ; it++){}//不能用it<st.end()的写法！

    //访问最后一个元素
    st.rbegin();
    //不能使用sort排序

3.常见函数
    (1) st.insert();
    (2) st.find(x);//返回 对应值为x的迭代器
    (3) st.erase(it);
            例：st.erase(st.find(200));
        st.erase(value);

        st.erase(first,last);
            例：
            set<int>::iterator it=st.find(5);
            st.erase(it,st.end());
    (4) st.size();
    (5) st.clear();

4.用途
    自动去重并排序
    //另有unordered_set，以散列代替红黑树，速度更快，适用于只需要去重的情形
    !!unordered_set内部元素顺序与添加元素顺序无关!!
