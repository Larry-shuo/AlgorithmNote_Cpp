1.
    (1) 二叉树的存储
        struct node{
            int data;
            node* lchild;
            node* rchild;
        } 
        node* root=NULL;

        node* newNode(int v){//新建结点
            node* Node=new node;
            Node->data=v;
            Node->lchild=Node->rchild=NULL;
            return Node;
        }

    (2) 查找，修改
    //修改改变了指针指向的内容，没改变指针本身，不需要引用
        void search(node* root,int x,int newdata){
            if(root==NULL)
                return;
            if(root->data==x)//找到数据域为x的节点
                root->data=newdata;

            search(root->lchild,x,newdata);
            search(root->rchild,x,newdata);
        }

    (3) 插入
    //插入改变了指针本身，根节点指针要使用引用，否则会插入失败
        void insert(node* &root,int x){
            if(root==NULL){
                root=newNode(x);
                return;
            }
            if{
                insert(root->lchild,x);
            }
            else{
                insert(root->rchild,x);
            }
        }
    //新建结点之后，务必将其左右孩子结点设置为NULL

    (4)二叉树的创建
        node* CReate(int data[],int n){
            node* root=NULL;
            for(int i-0;i<n;i++){
                insert(root,data[i]);
            }
        }
        return root;
    
    (5)