Union 合并 Find 查找 Set 集合
int father[N];

1.并查集基本操作
    (1)初始化
        for(int i=0;i<=N;i++){
            father[i]=i;
        }
    (2)查找//一个集合只存在一个根节点
        int find_father(int x){
            while(father[x]!=x)
                x=father[x];
            
            return x;
        }

    (3)合并
        a.先判断两个元素是否属于同一集合
        b.若是，将一个根节点认另一个为父
        void Union(int a,int b){
            int faa=find_father(a);
            int fab=find_father(b);
            if(faa!=fbb)
                father[faa]=fbb;//farther[fbb]=faa 也一样
        }

2.路径压缩
    //把当前查询的结点的路径上所有的节点的父亲都指向根节点
    int find_fathrt2(int x){
        int a=x;
        while(x!=fathrt[x]){
            x=father[x];
        }//循环结束时找到了根节点
        while(a!=father[a]){
            a=father[a];//得到该节点的父节点，以便继续压缩
            int t=a;
            father[t]=x;//其父节点为根节点
        }
        return x;

    }

3.例题《好朋友》

const int N=110;
int father[N];
bool isRoot[N];
int findF(int x){}//查找+压缩

void Union(int a,int b);

void init(int n){
    for(int i=1;i<=n;i++){
        father[i]=i;
        isRoot[i]=false;
    }
}
int main()
{
    int n,m,a,b;
    cin>>n>>m;
    init(n);
    for(int i=0;i<m;i++){
        cin>>a>>b;
        Union(a,b);
    }
    for(int i=1;i<=n;i++){
        isRoot[findF(i)]=true;//统计根结点个数
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        ans+=isRoot[i];
    cout<<ans;
    return 0;
}
