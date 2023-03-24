1.递归实现DFS
    const int maxn=30;
    int n,V,maxValue=0;
    int w[maxn],c[maxn];//w[maxn]为每件物品的重量,c[maxn]为每件物品的价值

    void DFS(int index,int sumW,int sumC){
        if(index==n){
            if(sumW<=V && sumC>maxValue){
                maxValue=sunC;//更新最大值
            }
            return;
        }
        DFS(index+1,sunW,sumC);//不选择index物品
        if(sumW+w[index]<=V)
            if(sumC+c[index]>ans)
                ans=sumC+c[index;]
        DFS(index+1,sumW+w[index],sumC+c[index]);//选择index物品
    }

    int main()
    {
        cin>>n>>y;
        for(int i=0;i<n;i++)
            cin>>w[i]>>c[i];
        DFS(0,0,0);
        cout<<maxValue;
    }

2.如何保存最优方案
temp数组，当选择index物品时，将A[index]加入temp中，当这个分支结束时，去除

例：选取n个数和为x，求平方和最大的序列：
    int n,k,x,maxsumsqu=-1,A[maxn];
    vector<int> temp,ans;//temp存放临时结果，ans存放最终答案

    void DFS(int index,int nowk,int nowx,int sumsqu){
        if(nowk==k && nowx==x){
            if(sumsqu>maxsumsqu){
                maxsumsqu=sumsqu;
                ans=temp;
            }
            return;
        }
        if(index==n || nowk>k || nowx>x)
            return;

        temp.push_back(A[index]);
        DFS(index+1,nowk+1,nowx+A[index],sumsqu+A[index]*A[index]);
        temp.pop_back();

        DFS(index+1,nowk,nowx,sumsqu);//不选择A[index]
    }