1.Dijkstra算法
    a).bool型数组vis[],记录是否已经访问
    b).d[]表示起点s到顶点Vi的最短距离,初始时赋很大的值,不断更新

    (1)伪代码：
    Dijkstra(G,d[],s){
        初始化;
        for(循环n次){
            u=使d[u]最小的还未访问的顶点标号;
            记u已被访问;
            for(从u出发能到达的v){
                if(v未被访问&&以u为中介点,使s到v的距离d[v]更短){
                    优化d[v];
                }
            }
        }
    }
    const int MAXV=1000;
    const int INF=1000000;
    (2)邻接矩阵
        int n,G[MAXV][MAXV];    //记录图节点以及边权
        int d[MAXV];            //记录从s出发的距离
        bool vis[MAXV]={false};

        void Dijkstra(int s){//s为起点
            fill(d,d+MAXV,INF);
            d[s]=0;     //s到它自身的距离为0,在第一次循环时将会选取s

            for(int i=0;i<n;i++){
                int u=-1,MIN=INF;
                for(int j=0;j<n;j++){//找到未访问结点中距离最小的
                    if(vis[j]==false && d[j]<MIN){
                        u=j;
                        MIN=d[j];
                    }
                }

                if(u==-1)//若找不到小于INF的d[u],说明剩下的顶点与s都不相通
                    return;

                vis[u]=true;
                //更新以u为中介点的最短距离
                for(int v=0;v<n;v++){
                    // 还未访问 && 可到达 && 通过u距离更短
                    if(vis[v]==false && G[u][v]!=INF && d[u]+G[u][v]<d[v])
                        d[v]=d[u]+G[u][v];//优化d[v]
                }
            }
        }
    (3)邻接表
        struct Node{
            int v,dis;
        };
        vector<Node> Adj[MAXV];
        int n;
        int d[MAXV];
        bool vis[MAXV]={false};

        void Dijkstra(int s){
            fill(d,d+MAXV,INF);
            d[s]=0;
            for(int i=0;i<n;i++){
                if(vis[j]==false && d[j]<MIN){
                    u=j;
                    MIN=d[j];
                }
            }

            if(u==-1)//若找不到小于INF的d[u],说明剩下的顶点与s都不相同
                return;

            vis[u]=true;
            for(int j=0;j<Adj[u].size();j++){
                int v=Adj[u][j].v;
                if(vis[v]==false && d[u]+A[u][v].dis<d[v])
                    d[v]=d[u]+Adj[u][v].dis;
            }
        }

    (4)利用前驱数组记录所有的最短路径!!!!!!!!!!!!!!!!!!
        vectro<int> pre[MAXV];
        void Dijkstra(int s){
            fill(d,d+maxv,INF);
            d[s]=0;
            for(int i=0;i<n;i++){

                int u=-1,MIN=INF;
                for(int j=0;j<n;j++){
                    if(vis[j]==false && d[j]<MIN){
                        u=j;
                        MIN=d[j];
                    }
                }
                if(u==-1)
                    return;
                vis[u]=true;

                for(int v=0;v<n;v++){
                    if(vis[v]==false && G[u][v]!=INF){
                        if(d[u]+G[u][v]<d[v]){
                            d[v]=d[u]+G[u][v];
                            pre[v].clear();!!!!!!!!!!!!!
                            pre[v].push_back(u);!!!!!!!!!!!!
                        }
                        else if(d[u]+G[u][v]==d[v]){
                            pre[v].push_back(u);!!!!!!!!!!!
                        }
                    }
                }
            }
        }
        
2.记录最短路径
    设置pre[v]记录每个v的前驱结点,最后通过递归的方式输出:
        void DFSpath(int s,int v){
            if(v==s){//若到达起点
                cout<<s;
                return;
            }
            DFSpath(s,pre[v]);//递归访问v的前驱结点pre[v]
            cout<<v;
        }
        
3.第二标尺
    a)新增边权，以花费为代表
        cost[u][v] 表示点u到v的花费
        c[u] 表示起点到u的最少花费(初始全为INF,c[s]=0)
            for(int v=0;v<n;v++){
                if(vis[v]==false && G[u][v]!=INF){//以u为中介点可以使d[v]更优
                    if(d[u]+G[u][v]<d[v]){
                        d[v]=d[u]+G[u][v];
                        c[v]=c[u]+cost[u][v];
                    }
                    else if(d[u]+G[u][v]==d[v] && c[u]+cost[u][v]<c[v])//最短距离相同时,能否使c[v]更优
                        c[v]=c[u]+cost[u][v];
                }
            }

    (b)新增点权,weight[u]表示城市u的物资数目,w[u]为从起点s到城市u可收集到的最大物资,
            //初始化
                w[s]=weight[s],w[u]=0;
                for(int v=0;v<n;v++){
                    if(vis[v]==false && G[u][v]!=INF){
                        if(d[u]+G[u][v]<d[v]){
                            d[v]=d[u]+G[u][v];
                            w[v]=w[u]+weight[v];
                        }
                        else if(d[u]+G[u][v]==d[v] && w[u]+weight[v]>w[v]){
                            w[v]=w[u]+weight[v];
                        }
                    }
                }

    (c)最短路径条数,新增数组num[ ]，令s到u的最短路径数目为num[u],
            //初始化
            num[s]=1,num[u]=0;
            for(int v=0;v<n;v++){
                if(vis[v]==false && G[u][v]!=INF){
                    if(d[u]+G[u][v]<d[v]){
                        d[v]=d[u]+G[u][v];
                        num[v]=num[u];
                    }
                    else if(d[u]+G[u][v]==d[v]){
                        num[v]+=num[u];
                    }
                }
            }
4.
    (1)利用前驱数组记录所有的最短路径
        vectro<int> pre[MAXV];
        void Dijkstra(int s){
            fill(d,d+maxv,INF);
            d[s]=0;
            for(int i=0;i<n;i++){
                int u=-1,MIN=INF;
                for(int j=0;j<n;j++){
                    if(vis[j]==false && d[j]<MIN){
                        u=j;
                        MIN=d[j];
                    }
                }
                if(u==-1)
                    return;
                vis[u]=true;
                for(int v=0;v<n;v++){
                    if(vis[v]==false && G[u][v]!=INF){
                        if(d[u]+G[u][v]<d[v]){
                            d[v]=d[u]+G[u][v];
                            pre[v].clear();
                            pre[v].push_back(u);
                        }
                        else if(d[u]+G[u][v]==d[v]){
                            pre[v].push_back(u);
                        }
                    }
                }
            }
        }
        再对pre数组进行DFS操作,得到路径

    (2) 寻找使第二标尺最优的最短路径(边权,点权)
        int optvalue;
        vector<int> pre[maxv];
        vector<int> path,temppath;//temppath中的结点使逆序存放的,即从end到start
        void DFS(int v){
            if(v==start){
                temppath.push_back(v);//将起点加入至临时路径中
                int value;
                计算当前路径temppath上的value的值

                if(value优于optvalue){
                    optvalue=value;
                    path=temppath;
                }
                temppath.pop_back();//并不更优,弹出start元素
                return;
            }
            temppath.push_back(v);
            for(int i=0;i<pre[v].size();i++){
                DFS(pre[v][i]);
            }
            temppath.pop_back();//遍历结束后弹出结点
        }
    (3)若需要统计最短路径的个数,可以开一个全局变量来记录,(当DFS到叶子结点(起点)时,+1)
