1.拓扑排序
    vector<int> G[maxv];//邻接表
    int n,m,inDegree[maxv];
    bool topologicalSort(){
        int num=0;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(inDegree[i]==0)
                q.push(i);//入度为0的结点入队
        }
        while(!q.empty()){
            int u=q.front();
            //此处可以输出u
            q.pop();
            for(int i=0;i<G[u].size();i++){
                int v=G[u][i];
                inDegree[v]--;
                if(inDegree[v]==0)
                    q.push(v);
            }
            //G[u].clear();可以清空u的所有出边
            num++;//顶点数+1
        }
        if(num==n)
            return true;
        else
            return false;
    }
2.关键路径
    (1)拓扑序列并求ve
        stack<int> toporder;//栈存储拓扑排序
        bool topologicalsort(){
            queue<int> q;
            for(int i=0;i<n;i++){
                if(inDegree[i]==0)
                    q.push(i);
            }
            while(!q.empty()){
                int u=q.front();
                q.pop();
                toporder.push(u);
                for(int i=0;i<G[u].size();i++){
                    int v=G[u][i].v;
                    inDegree[v]--;
                    if(inDegree[v]==0)
                        q.push(v);
                    if(ve[u]+G[u][i].w>ve[v])
                    ve[v]=ve[u]+G[u][i].w;
                }
            }
            if(toporder.size()==n)
                return true;
            else
                return false;
        }

    (2)求vl(求事件的最长发生时间)
        //输出栈以得到逆拓扑排序
        fill(vl,vl+n,ve[n-1]);//初始值为终点的ve值(事件的最早发生时间)
        while(!toporder.empty()){
            int u=toporder.top();
            toporder.pop();
            for(int i=0;i<G[u].size();i++){
                int v=G[u][i].v;
                if(vl[v]-G[u][i].w<vl[u])
                    vl[u]=vl[v]-G[u][i].w;
            }
        }
    (3)完整代码
        int CriticalPath(){
            memset(ve,0,sizeof(ve));
            if(topologicalSort()==false)
                return -1;

            fill(vl,vl+n,ve[n-1]);//初始值为终点的ve值(事件的最早发生时间)
            while(!toporder.empty()){
                int u=toporder.top();
                toporder.pop();
                for(int i=0;i<G[u].size();i++){
                    int v=G[u][i].v;
                    if(vl[v]-G[u][i].w<vl[u])
                        vl[u]=vl[v]-G[u][i].w;
                }
            }

            for(int u=0;u<n;u++){
                for(int i=0;i<G[u].sizwe();i++){
                    int v=G[u][i].v,w=G[u][i].w;
                    int e=ve[u],l=vl[v]-w;
                    if(e==l){//二者相等,为关键路径
                        cout<<u<<"->"<<v;
                    }
                }
            }
            return ve[n-1];//返回关键路径长度
        }

