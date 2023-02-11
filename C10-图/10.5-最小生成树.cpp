1.Prime算法
    (1)伪代码:
        Prim(G,d[]){
            初始化;
            for(n次){
                u=使d[u]最小的还未访问的顶点
                标记u已访问
                for(从u出发能到达的所有v){
                    if(v未被访问 && 以u为中介点使得v到达集合s距离更短)
                        d[v]=G[u][v]
                }
            }
        }
    (2)邻接矩阵版
        int n,G[][];
        int d[];
        bool vis[]={false};
        int Prim(){
            fill(d,d=maxv,INF);
            d[0]=0;//初始点为0
            int ans=0;//权值和
            for(int i=0;i<n;i++){
                int u=-1,MIN=INF;
                for(int j=0;j<n;j++){
                    if(vis[j]==false && d[j]<MIN){
                        u=j;
                        MIN=d[j];
                    }
                }
                if(u==-1)//找不到相通的点了,剩下的顶点与S不连通
                    return -1;
                vis[u]=true;
                ans+=d[u];//加上权值
                for(int v=0;v<n;v++){
                    if(vis[v]==false && G[u][v]!=INF && G[u][v]<d[v])
                        d[v]=G[u][v];
                }
            }
            return ans;
        }

    (3)邻接表版
        struct Node{
            int v,dis;
        };
        vector<int> Adj[];
        int n;
        int d[];
        bool vis[]={false};

        int Prim(){
            fill(d,d=maxv,INF);
            d[0]=0;//初始点为0
            int ans=0;//权值和
            for(int i=0;i<n;i++){
                int u=-1,MIN=INF;
                for(int j=0;j<n;j++){
                    if(vis[j]==false && d[j]<MIN){
                        u=j;
                        MIN=d[j];
                    }
                }
            }
            if(u==-1)//找不到相通的点了,剩下的顶点与S不连通
                return -1;
            vis[u]=true;
            ans+=d[u];//加上权值
            for(int j=0;j<Adj[u].size();j++){
                int v=Adj[u][j].v;
                if(vis[v]==false && Adj[u][j].dis<d[v])
                    d[v]=Adj[u][j].dis;
            }
            return ans;
        }

2.Kruskal算法
    struct Node{
        int u,v;
        int cost;
    }E[maxe];
    int farther[N];
    int findFarther(){...}
    int Kruskal(int n,int m){//n为顶点个数,m为边数
        int ans=0,num_edge=0;
        for(int i=1;i<=n;i++)//顶点从1到n
            farther[i]=i;//初始化并查集
        sort(E,E+m,cmp);//从小到大排序
        for(int i=0;i<m;i++){
            int fau=findFarther(E[i].u);
            int fav=findFarther(E[i].v);
            if(fau!=fav){//若不在一个连通分量里,加入
                farther[fau]=fav;
                ans+=E[i].cost;
                num_edge++;
                if(num_edge==n-1)//边数到达点数n-1时退出
                    break;
            }
        }
        if(num_edge!=n-1)//说明该图无法联通
            return -1;
        else
            return ans;
    }