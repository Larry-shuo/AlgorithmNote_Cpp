1.定义
    排序二叉树
2.基本操作
    (1)查找
        void search(node* rot,int x){
            if(root==NULL){
                cout<<"Failed";
                return;
            }
            if(root->data==x)
                cout<<root->data;
            else if(root->data>x)
                search(root->lchild,x);
            else(root->data<x)
                search(root->rchild,x);
        }
    
    (2)插入
        void insert(node* &root,int x){
            if(root==NULL){
                root=newNode(x);
                return;
            }
            if(x==root->data)
                return;
            else if(x<root->data)
                insert(root->lchild,x);
            else(x>root->data)
                insert(root->rchild,x);
        }

    (3)建立
        node* Create(int data[],int n){
            node* root=NULL;
            for(int i=0;i<n;i++){
                insert(root,data[i]);
            }
            return root;
        }
    (4)删除
        //寻找以root为根节点的树中的最右结点
        node* findMax(node* root){
            while(root->rchild!=NULL)
                root=root->rchild;
            return root;
        }
        node* findMin(node* root){}

        //删除以root为根的树中权值为x的结点
        void deleteNode(node* root,int x){
            if(root==NULL)
                return;
            if(root->data==x){//该点即为需要删除的点
                if(root->lchild==NULL && root->rchild==NULL)
                    root=NULL;//把root设置为NULL，即等于删除
                else if(root->lchild!=NULL){
                    node* pre=findMax(root->lchild);
                    root->data=pre->data;
                    deleteNode(root->lchild,pre->data);//在左子树中删除pre
                }
                else{
                    node* next=findMin(root->rchild);
                    root->data=next->data;
                    deleteNode(root->rchild,next->data);
                }
            }
            else if(root->data>x)
                deleteNode(root->lchild,x);
            else(root->data<x)
                deleteNode(root->rchild,x);
        }



3.性质
