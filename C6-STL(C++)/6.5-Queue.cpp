#include<queue>
队列，先进先出

1.定义
    queue<typename> name;

2.访问//queue是一种限制进出的数据结构
    只能通过q.front()访问队首元素，通过q.back()访问队尾元素
    
    队列中元素不能修改
    例如：
        q.push(a[1]);
        q.front().data=100;无效！
        a[1].data=100;队列中的数据不变，无效！

3.函数
    (1) q.push(x);//入队
 
    (2) q.front(),q.back();

    (3) q.pop();//队首元素出队

    (4) q.empty();//检测是否为空，是则返回true
        在front()和back()之前，必须用empty()检查队列是否为空

    (5) q.size();

4.用途
    (1)实现广度优先搜索时，使用队列
    
