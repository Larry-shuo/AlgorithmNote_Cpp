int Partition(int A[],int left,int right)//一趟排序
{
    int temp=A[left];//主元
    while(left<right){
        while(left<right && A[right]>temp)
            right--;
        A[left]=A[right];
        while(left<right&&A[left]<=temp)
            left++;
        A[right]=A[left];
    }
    A[left]=temp;//此时left为相遇的下标
    return left;//返回相遇的下标
}
void QuickSort(int A[],int left,int right)
{
    if(left<right){
        int pos=Partition(A,left,right);
        QuickSort(A,left,pos-1);
        QuickSort(A,mid+1,right);
    }
}