//递归实现
const int maxn=100;
void merge(int A[],int L1,int L2,int R1,int R2)
{
    int i=L1,j=L2;
    int temp[maxn],index=0;//temp暂存归并结果
    while(i<=R1&&j<=R2){
        if(A[i]<=A[j]){
            temp[index++]=A[i++];
        }
        else{
            temp[index++]=A[j++];
        }
    }
    while(i<=R1)
        temp[index++]=A[i++];
    while(j<=R2)
        temp[index++]=A[j++];

    for(i=0;i<index;i++){
        A[L1+i]=temp[i];//归并后的数组返回A
    }
}
void MergeSort(int A[],int left,int right){
    if(left<right){
        int mid=(left+right)/2;
        MergeSort(A,left,mid);
        MergeSort(A,mid+1,right);
        merge(A,left,mid,mid+1,right);
    }
}

//非递归实现
void MergeSort(int A[])
{
    for(int step=2;step/2<=n;step*=2){
        for(int i=1;i<=n;i+=step){//对每一组排序
            int mid=i+step/2-1;
            if(mid+1<=n){
                merge(A,i,mid,mid+1,min(i+step-1,n));//左区间为(i,mid)，右区间为(mid+1,min(i+step-1,n))
            }
        }
    }
}
