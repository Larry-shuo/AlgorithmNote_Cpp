#include<queue>
优先队列，内部按优先级排序（堆排序实现）

1.定义
    poiority_queue<typename> name;
2.访问
    只能通过q.top()访问队首元素(堆顶元素),也就是优先级最高的元素

3.函数
    (1) q.push(x);

    (2) q.top();

    (3) q.pop();堆顶元素出队

    (4) q.empry();//top()前检查

    (5)q.size();

4.优先级设置
    (1)基本数据结构的优先级设置
        poiority_queue<int> q = poiority_queue<int,vector<int>,less<int> >q 
        //两种定义方式相同，默认从大到小排序

        poiority_queue<double, vector<double>, greater<double> >q //数字越小优先级越高,

    (2)结构体的优先级设置
        struct fruit{
            string name;
            int price;
            friend bool operator < (fruit f1,fruit f2){
                return f1.price<f2.price;//可以记住，其符号与cmp函数中的相反
            }
        }
        priority_queue<fruit> q;//这样其内部就是以价格高的水果为高优先级

        或
        struct cmp{
            bool operator()(fruit f1,fruit f2){
                return f1.price>f2.price;//这里符号与cmp函数中的相同
            }
        }
        priority_queue<fruit,vector<fruit>,cmp> q;

5.用途
    (1)解决贪心问题，或优化Dijkstra算法
    

