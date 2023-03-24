#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;

struct inteval{
    int x,y;
}i[100];

bool cmp(inteval a,inteval b){
    if(a.x!=b.x)
        return a.x>b.x;
    else{
        return a.y<b.y;
    }
}

int main()
{
    int n=4;
    i[0].x=1,i[0].y=3;
    i[1].x=2,i[1].y=4;
    i[2].x=3,i[2].y=5;
    i[3].x=6,i[3].y=7;

    sort(i,i+n,cmp);
    int ans=1,lastx=i[0].x;
    for(int j=0;j<n;j++){
        if(i[j].y<=lastx){
            lastx=i[j].x;
            ans++;
        }
    }
    cout<<ans<<endl;

    system("pause");
    return 0;
}