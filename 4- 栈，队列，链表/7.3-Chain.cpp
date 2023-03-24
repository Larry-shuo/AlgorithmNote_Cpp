1.定义

2.（新建节点）分配内存空间
    (1)new 基本用法
    typename* p=new typename

        int* p=new int;
        node* p=new node;
        int* p=new int[100000];//可能会出错
    
    (2)内存泄漏
        delete(p);
        //new 和 delete 必须成对出现
    
3.基本操作
    (1)创建链表
    例：
        struct node{
            int datd;
            node* next;
        };
        node* Create(int Array[]){
            node* p,*pre,*head;
            head->next=NULL;
            pre=head;
            for(int i=0;i<5;i++){
                p=new node;
                p->data=Array[i];
                p->next=NULL;
                pre->next=p;
                pre=p;
            }
            return head;
        }
        int main(){
            int Array[5]={5,4,3,2,1};
            node* L=Create(Array);//此时L为头节点
            L=L->next;//从第一个节点开始有数据
            while(L->next!=NULL){
                cout<<L->data<<'';
                L=L->next;
            }
            return 0;
        }
    (2)查找元素
        顺序查找并判断
    (3)插入元素
        在第i个位置插入x，意为插入后第i个位置就是x
        void insert(node* head, int pos, int x){
            node* p=head;
            for(int i=0;i<pos-1;i++)
                p=p->next;
            
            node* q=new node;
            q->data=x;
            q->next=p->next;
            p->next=q;
        }

    (4)删除元素
        void del(node* head,int x){//删除值为x的节点
            node* p=head->next;
            node* pre=head;
            while(p!=NULL){
                if(p->data==x){
                    pre->next=p->next;
                    delete(p);//使用 new() 与 delete()
                }
                else{
                    pre=p;
                    p=p->next;
                }
            }
        }
    
4.静态链表
    直接令数组的下标直接表示节点的地址，不需要头节点；
    例：
        struct Node{
            typename data;
            int next;
        }node[size];//数组名与结构体名不要重

        node[11111]=22222;
        node[22222]=33333;
        node[33333]=-1; //表示没有后继结点

PAT题目：
A-1032
A-1052
