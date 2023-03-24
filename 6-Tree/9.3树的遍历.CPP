1.静态表示
    struct node{
        typename data;
        int layer;
        vector child;
    }Node[maxn];

2.先根遍历
    void Preorder(int root){
        cout<<Node[root].data;
        for(int i=0;i<Node.child.size();i++)
            Preorder(Node[root].child[i]);
    }

3.层序遍历
    void LayerOrder(int root){
        queue<int> q;
        q.push(root);
        Node[root].layer=1;
        while(!q.empty()){
            int front=q.front();
            cout<<Node[front].data;
            q.pop();
            for(int i=0;i<Node[front].child.size();i++){
                int child=Node[front].child[i];
                Node[child].layer=Node[front].layer+1;
                q.push(child);
            }
        }
    }