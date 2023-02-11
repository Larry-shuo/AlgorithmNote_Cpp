1.何为DP
    (1)斐波那契数列
        int dp[maxn];

        int F(int n){
            if(n==0||n==1)
                return 1;
            if(dp[n]!==-1)
                return dp[n];
            else{
                dp[n]=F(n-1)+F(n-2);
                return dp[n];
            }
        }
    (2)数塔最大和
    #include<iostream>
    #include<algorithm>
    using namespace std;
    const int maxn=1000;
    int f[maxn][maxn],dp[maxn][maxn];//f存储结点数字
    int main(){
        ...输入部分
        //边界
        for(int j=1;j<=n;j++)
            dp[n][j]=f[n][j];
        //从n-1层开始往上不断计算
        for(int i=n-1;i>=1;i--){
            for(int j=1;j<=i;j++){
                //状态转移方程
                dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+f[i][j];
            }
        }
        cout<<dp[1][1];
    }