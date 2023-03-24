1.DFS
    DFS伪代码:
        DFS(u){//访问顶点u
            vis[u]=true;
            for(从u出发能访问到的v)
                if(vis[v]==false)
                    DFS(v);
        }
        DFSTrave(G){//遍历图G
            for(G所有的顶点u)
                if(vis[u]==false)
                    DFS(u);
        }
    const int MAXV=1000;
    const int INF=100000000;

    (1)邻接矩阵
        int n,G[MAXV][MAXV];
        bool vis[MAXV]={false};
        void DFS(int u,int depth){
            vis[u]=true;
            //操作
            for(int v=0;v<n;v++){
                if(vis[v]==false && G[u][v]!=INF)
                    DFS(v,depth+1);
            }
        }
        void DFSTrave(){
            for(int u=0;u<n;u++)
                if(vis[u]==false)
                    DFS(u,1);
        }

    (2)邻接表
        vector<int> Adj[MAXV];
        int n;
        bool vis[MAXV]={false};
        void DFS(int u,int depth){
            vis[u]=true;
            //操作
            for(int i=0;i<Adj[u].size();i++){
                int v=Adj[u][i];
                if(vis[v]==false)
                    DFS(v,depth+1);
            }
        }
        void DFSTrave(){
            for(int u=0;u<n;u++)
                if(vis[u]==false)
                    DFS(u,1);
        }

2.BFS
    (1)伪代码
        BFS(u){
            queue q;
            u入队;
            inq[u]=true;
            while(!q.empty()){当队列非空
                取q队首元素u访问
                for(从u出发可到达的所有顶点v)
                    if(inq[v]==false){
                        将v入队
                        inq[v]=true;//v已经入过队列
                    }
            }
        }
        BFSTrave(G){
            for(G的所有顶点u)
                if(inq[u]==false)
                    BFS(u);
        }
    (2)邻接矩阵
        ...
    (3)邻接表
        ... 
    (4)带层号邻接表
        struct Node{
            int v;
            int layer;
        };
        vector<Node> Adj[N];
        void BFS(int s){
            queue<int> q;
            Node start;
            start.v=s;
            start.layer=0;
            q.push(start);
            inq[start.v]=true;
            while(!q.empty()){
                Node top=q.front();
                q.pop();
                int u=top.v;
                for(int i=0;i<Adj[u].size();i++){
                    Node next=Adj[u][i];
                    next.layer=top.layer+1;
                    if(inq[next.v]==false){
                        q.push(next);
                        inq[next.v]=true;
                    }
                }
            }
        }