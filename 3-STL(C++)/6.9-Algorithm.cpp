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

8. iterator unique(iterator it_1,iterator it_2);//先对容器排序，“删除”序列中所有相邻的重复元素(只保留一个)
    //返回一个迭代器，指向去重后的容器中不重复序列的最后一个元素的下一位

//寻找容器中最大值与最小值,返回一个迭代器
    iterator max_element(iterator begin,iterator end,compare cmp);//cmp为比较函数
    iterator min_element(A.begin(),A.end(),cmp);


//统计出现次数
    //count()返回值为target的元素个数
    int num1=count(vector.begin(),vector.begin(),target);

    //count_if()返回满足pred条件的值的个数
    int num2=count_if(iterator it1,iterator it2,pred);//pred为一元谓词，接受一个参数并返回bool，(即一个cmp函数)

