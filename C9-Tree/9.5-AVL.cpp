1.定义
    struct node{
        添加 int height;
    };
    //新建结点
    node* newNode(int x){
        node* Node=new node;
        Node->data=x;
        Node->height=1;
        Node->lchild=Node->rchild=NULL;
        return Node;
    }

    //获取高度
    int get_height(node* root){
        if(root==NULL) return 0;
        return root->height;
    }

    //计算平衡因子
    int get_balacefactor(node* root){
        return get_height(root->lchild) - get_height(root->rchild);
    }
    //更新height=左子树的高度与右子树的高度的最大值+1
    void update_height(node* root){
        root->height=max(get_height(root->lchild)+1,get_height(root->rchild)+1);//<algorithm>
    }

2.操作
    (1)查找
        //与二叉查找树相同
    (2)插入
        //左旋
            void L(node* &root){//记得&
                node* temp=root->rchild;
                root->rchild=temp->lchild;
                temp->lchild=root;
                update_height(root);
                update_height(temp);
                root=temp;
            }
        //右旋
            void R(node* &root){
                node* temp=root->lchild;
                root->lchild=temp->rchild;
                temp->rchild=root;
                update_height(root);
                update_height(temp);
                root=temp;
            }

        //插入情况汇总
        树型                判定条件                        调整方法
        LL      BF(root)=2,BF(root->lchild)=1             对root右旋

        LR      BF(root)=2,BF(root->lchild)=-1  先对root->lchild左旋,再对root右旋

        RR      BF(root)=-2,BF(root->rchild)=-1           对root左旋

        RL      BF(root)=-2,BF(root->rchild)=1  先对root->rchild右旋,再对root左旋

        void insert(node* &root,int v){//勿忘&
            if(root==NULL){
                root=newNode(v);
                return;
            }
            if(v<root->data){
                insert(root->lchild,v);
                update_height(root);
                if(get_balacefactor(root)==2){//RR or RL
                    if(get_balacefactor(root->lchild)==1)//RR
                        R(root);
                    else if(get_balacefactor(root->lchild)==-1){//RL
                        L(root->lchild);
                        R(root);
                    }
                }
            }else{
                insert(root->rchild);
                update_height(root);
                if(get_balacefactor(root->rchild)=-1)
                    L(root);
                else if(get_balacefactor(root->rchild)==1){
                    R(root->rchild);
                    L(root);
                }
            }
        }
    (3)建立
        node* Create(int data[],int n){
            node* root=NULL;
            for(int i=0;i<n;i++)
                insert(root,data[i]);
            return root;
        }