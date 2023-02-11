1.先序遍历
    void preorder(node* root){
        if(root==NULL)
            return;
        cout<<root->data;
        preorder(root->lchild);
        preorder(root->rchild);
    }
2.中序遍历

3.后序遍历

4.层序遍历
    void layorder(node* root){
        queue<node*> q;
        root->layer=1;
        q.push(root);
        while(!q.empty()){
            node* t=q.front();
            q.pop();
            cout<<t->data;
            if(t->lchild!=NULL){
                t->lchild->layer=t->layer+1;
                q.push(t->lchild);
            }
            if(t->rchild!=NULL){
                t->rchild->layer=t->layer+1;
                q.push(t->rchild);
            }
        }

    }
5.由先序和中序复原
//当前先序区间为[preL,preR]，中序区间为[inL,inR],返回根节点地址
node* create(int preL,int preR,int inL,int inR){
    if(preL>preR)
        return NULL;
    node* root=new node;
    root->data=pre[preL];
    int k;
    for(int k=inL;k<=inR;k++){
        if(in[k]==pre[preL])//在中序中找到先序第一个节点的位置,即根节点
            break;
    }

    int numleft=k-inL;//根节点左孩子区间的节点个数

    root->lchild=create(preL+1,preL+numleft,inL,k-1);

    root->rchild=create(preL+numleft+1,preR,k+1,inR);

    return root;
}

6.二叉树的静态实现
    (1)定义
    struct node{
        int data;
        int lchild;
        int rchild;
    }Node[101];

    (2)新结点，值为v，编号为index
    int index=0;
    int newNode(int v){
        Node[index].data=v;
        Node[index].lchild=-1;
        Node[index].rchild=-1;
    }

    (3)建立
    int Create(int data[],int n){
        int root=-1;
        for(int i=0;i<n;i++){
            insert(root,data[i]);
        }
        return root;
    }
