//待排序数组为 a[n],从1开始
//选择排序
void selectSort()
{
    for(int i=1;i<=n;i++){
        int k=i;
        for(int j=i;j<=n;j++){
            if(a[j]<a[k])
                k=j;    //k记录最小值位置
        }
        int t=a[k];
        a[k]=a[i];
        a[i]=t;
    }
}

//插入排序(从1开始)
int insertSort()
{
    for(int i=2;i<=n;i++){
        int t=a[i],j=i;
        while(j>1&&t<a[j-1]){
            a[j]=a[j-1];
            j--;
        }
        a[j]=t;
    }
}

//sort排序用法
#include<algorithm>
using namespace std;

int main()
{
    sort(a,a+4);//默认从小到大
}

//cmp
bool cmp(int a,int b){
    return a>b;//即a>b时，把a排在前面
}

//也可以用其他数组的数据进行排序
bool cmp(int a,int b){
    return A[a]>A[b];
}

//结构体cmp
bool cmp(node a,node b){
    if(a.x!=b.x)
        return a.x>b.x;
    else
        return a.y<b.y;
}

//STL容器排序

vector<int> vi;
sort(vi.begin(),vi.end(),cmp);
sort(str,str+3);

//字符串长度排序：
    bool cmp(string st1,string st2){
        return st1.length()<st2.length();
    }
    int main(){
        string str[3]={"bbbb","zxcqas","aa"};
        sort(str,str+3,cmp);
        ...
    }