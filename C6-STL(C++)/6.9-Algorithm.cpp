#include<algorithm>
using namespace std;

1.  max(x,y),min(x,y);//参数必须是两个，(三个参数可以max(x,max(y,z)))
    abs(x)//整数
    fabs(x);//浮点型(<cmath>)

2.  swap(x,y);

3.  reverse(it1,it2);
    将数组指针在 [it1,it2) 之间的元素或容器的迭代器在范围 [it1,it2) 内的元素进行反转
    例：
    string str="abcdefg";
    reverse(str.begin()+2,str.begin()+6);
    //str->"abfedcg"

4.  next_permutation();//返给出一个序列在全排列中的下一个序列
    例：
        int a[10]={1,2,3};
        do{
            cout<<a[0]<<a[1]<<a[2];
        }while(next_permutation(a,a+3));
        //在达到全排列的最后一个时会返回false

5.  fill();对数组或容器内某一区间赋值
    例：
        int a[5]={1,2,3,4,5};
        fill(a,a+5,23333);
        ...

6.  sort()不再赘述

7.  lower_bound(first,last,val)
    //寻找数组或容器中[first,last)范围内第一个大于等于val的位置，若为数组返回其指针，若为容器，返回其迭代器
    //（若不存在，返回可以插入该元素的位置）
    upper_bound(first,last,val)
    //......第一个大于val的位置......
