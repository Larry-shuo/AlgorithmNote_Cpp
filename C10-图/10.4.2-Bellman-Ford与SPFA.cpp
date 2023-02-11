1.Bellman-Ford 邻接表版
    struct Node{
        int v,dis;//v为邻接边的顶点,dis为距离
    }；
    vector <Node> Adj[maxv];
    int n;
    int d[maxv];

    bool Bellman(int s){
        fill(d,d+maxv,INF);
        d[s]=0;

        for(int i=0;i<n-1;i++){
            for(int u=0;u<n;u++){
                for(int j=0;j<Adj[u].size();j++){
                    int v=Adj[u][j].v;
                    int dis=Adj[u][j].dis;
                    if(d[u]+dis<d[v])
                        d[v]=d[u]+dis;
                }
            }
        }
        //以下为判断负环的代码
        for(int u=0;u<n;u++){
            for(int j=0;j<Adj[u].size();j++){
                int v=Adj[u][j].v;
                int dis=Adj[u][j].dis;
                if(d[u]+dis<d[v])
                    return false;//说明有负环
            }
        }
        return true;
    }

2.SPFA
    vector<Node> Adj[maxv];
    int n,d[maxv],num[maxv];
    bool inq[maxv];//记录顶点是否在队列中

    bool SPFA(int s){
        memset(inq,false,sizeof(inq));
        memset(num,0,sizeof(num));//num记录入队的次数
        fill(d,d+maxv,INF);
        //源点入队
        queue<int> q;
        q.push(s);
        inq[s]=true;
        num[s]++;
        d[s]=0;
        //主体部分
        while(!q.empty()){
            int u=q.front();
            q.pop();
            inq[u]=false;
            //遍历u的所有临边v
            for(int j=0;j<Adj[u].size();j++){
                int v=Adj[u][j].v;
                int dis=Adj[u][j].dis;
                //松弛操作
                if(d[u]+dis<d[v]){
                    d[v]=d[u]+dis;
                    if(!inq[v]){
                        q.push(v);
                        inq[v]=true;
                        num[v]++;
                        if(num[v]>=n)
                            return false;
                    }
                }
            }
        }
        return true;
    }

3.Floyd算法(顶点数在200以内)
    (1)伪代码
        枚举顶点k[1,n]
            以顶点k为中介,枚举所有顶点对(i,j)
                if(dis[i][k]+dis[k][j]<dis[i][j]成立)
                    赋值dis[i][j]=dis[i][k]+dis[k][j];
    
    (2)代码
    int dis[maxv][maxv];

    void Floyd(){
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dis[i][k]!=INF  &&  dis[k][j]!=INF  &&  dis[i][k]+dis[k][j]<dis[i][j]){
                        dis[i][j]=dis[i][k]+dis[k][j];
                    }
                }
            }
    }
    int main()
    {
        ...
        fill(dis[0],dis[0]+maxv*maxv,INF);
        ...读取数据
        Floyd();
        for(int i=0;i<N;i++){
            for(int j=0;j<n;j++){
                cout<<dis[i][j];
            }
        }
        ...
    }

