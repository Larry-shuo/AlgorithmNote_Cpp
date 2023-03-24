#include<cstdio>
#include<cstdlib>
#include<string.h>
#include<string>
#include<iostream>
#include<cmath>
using namespace std;

/*全排列
int n,p[11],hasht[11]={0};

void generatep(int index){
    if(index==n+1){
        for(int i=1;i<=n;i++){
            cout<<p[i];
        }
        cout<<endl;
    }
    else{
        for(int i=1;i<=n;i++){
            if(hasht[i]==0){
                p[index]=i;
                hasht[i]=1;
                generatep(index+1);
                hasht[i]=0;//已处理完index为i的情况，复原！！！
            }
        }
    }
}

int main(){
    cin>>n;
    generatep(1);
    system("pause");
    return 0;
}
*/

//n皇后问题
int n,p[11],hasht[11]={0},count=0;

void generatequeen(int index){
    if(index==n+1){
        for(int i=1;i<=n;i++){
            cout<<p[i];
        }
        count++;
        cout<<endl;
    }
    else{
        for(int i=1;i<=n;i++){
            if(hasht[i]==0){    //数字i还未被填写
                bool flag=true;
                for(int pre=1;pre<index;pre++){
                    if(abs(pre-index)==abs(p[pre]-i)){//数字位置之差与数字之差相等,在某一条对角线上
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    p[index]=i;
                    hasht[i]=1;
                    generatequeen(index+1);
                    hasht[i]=0;//已处理完index为i的情况，复原！！！
                }
            }
        }
    }
}

int main(){
    cin>>n;
    generatequeen(1);
    cout<<count<<"个解"<<endl;
    system("pause");
    return 0;
}

