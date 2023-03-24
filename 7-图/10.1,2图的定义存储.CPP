定义
    ...
存储
1.邻接矩阵(适合顶点数不太多的图(1000以内))
    G[][];

2.邻接表(使用vector变长数组，存储边)

    (1)无权值
        vector<int> Adj[N];//N个结点
    (2)有权值(结构体node)
        struct node{
            int v;//边的终点编号
            int w;//权值
        }
        vector<node> Adj[N];

        新增有向边：(1指向3,权值为4)
        a.赋值
            node temp;
            temp.v=3;
            temp.w=4;
            Adj[1].push_back(temp);
        
        b.定义构造函数
            struct node{
                int v,w;
                node(int_v,int_w):v(_v),w(_w){}
            }
            Adj[1].push_back(node(3,4));

3.