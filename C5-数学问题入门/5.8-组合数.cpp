5.8.1 n!的问题

//计算n！中有多少个质因子p
int cal(int n,int p){
    int ans=0;
    while(n){
        ans+=n/p;
        n/=p;
    }
    return ans;
}
5.8.2求组合数Cnm
(1).递推公式
const int n=60;
void calC(){
    for(int i=0;i<=n;i++){
        res[i][0]=res[i][i]=1;
    }
    for(int i=2;i<=n;i++){
        for(int j=0;j<=1;j++){
            res[i][j]=res[i-1][j]+res[i-1][j-1];//计算C ij（i中取j个）
            res[i][i-j]=res[i][j];
        }
    }
}

(2).定义式的变形来计算
long long C(long long n,long long m){
    long long ans=1;
    for(long long i=1;i<=m;i++){
        ans=ans*(n-m-i)/i;  //先乘再除
    }
    return ans;
}

