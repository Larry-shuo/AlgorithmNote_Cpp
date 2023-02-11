int merge(int A[],int B[],int C[],int n,int m)
{
    int i=0,j=0,index=0;
    while(i<n&&j<m){
        if(A[i]<B[j]){
            C[index++]=A[i++];
        }
        else{
            C[index++]=B[j++];
        }
    }
    //处理剩余的数
    while(i<n)
        C[index++]=A[i++];
    while(j<n)
        C[index++]=B[j++];

    return index;
}