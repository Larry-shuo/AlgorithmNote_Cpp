//P149 拆分集合为两部分，元素个数之差尽量小，元素和之差尽量大
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;

const int maxn=10010;
int A[maxn],n;

int randPartition(int A[],int left,int right)
{
    int p=round(1.0*rand()/RAND_MAX*(right-left)+left);//生成left到right范围内的随机数
    swap(A[p],A[left]); //交换主元
    int temp=A[left];
    //快速排序
    while(left<right){
        while(left<right && A[right]>temp)
            right--;
        A[left]=A[right];
        while(left<right && A[left]<temp)
            left++;
        A[right]=A[left];
    }
    A[left]=temp;
    return left;//返回中心点
}

void RandSelsct(int A[],int left,int right,int K)
{
    if(left==right)
        return;
    int p=randPartition(A,left,right);
    int M=p-left+1; //A[p]是(left,right)中第M大
    if(M==K)
        return;//找到满足条件的点
    if(M<K)
        RandSelsct(A,p+1,right,K-M);
    else
        RandSelsct(A,left,p-1,K);
}

int main()
{
    srand((unsigned)time(NULL));

    int sum=0,sum1=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>A[i];
        sum+=A[i];//总和
    }
    RandSelsct(A,0,n-1,n/2);
    for(int i=0;i<n/2;i++)
        sum1+=A[i]; //其一集合的元素和
    cout<<((sum-sum1)-sum1);
    return 0;
}