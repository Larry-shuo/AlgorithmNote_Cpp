#include<iostream>
#include<algorithm>


11.3 最长不下降子序列(LIS)
using namespace std;
#define N 110

int A[N],dp[N];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>A[i];

    int ans=-1;
    for(int i=1;i<=n;i++){
        dp[i]=1;
        for(int j=1;j<i;j++){
            if(A[i]>=A[j] && dp[j]+1>dp[i])
            dp[i]=dp[j]+1;
        }
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}


11.4最长公共子序列(LCS)

#include<cstring>
char A[N],B[N];
inr dp[N][N];
int main()
{
    int n;
    gets(A+1);
    gets(B+1);
    int lenA=strlen(A+1);
    int lenB=strlen(B+1);
    for(int i=0;i<=lenA;i++)
        dp[i][0]=0;
    for(int i=0;i<=lenA;i++)
        dp[0][i]=0;

    for(int i=1;i<=lenA;i++){
        for(int j=1;j<lenB;j++){
            if(A[i]==B[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[lenA][lenB];
    return 0;
}