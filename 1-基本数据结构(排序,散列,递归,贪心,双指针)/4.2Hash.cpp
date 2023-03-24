#include<cstdlib>
#include<string.h>
#include<string>
#include<iostream>
using namespace std;

char s[100][5],temp[100][5];
int HashTable[26*26*26+10]={0};

int hashFunc(char S[]){
    int id=0;
    for(int i=0;i<3;i++){
        id=id*26+(S[i]-'A');
    }
    return id;
}

int main()
{
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i];
        int id=hashFunc(s[i]);
        HashTable[id]++;
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>temp[i];
        int id=hashFunc(temp[i]);
        cout<<HashTable[id]<<"´Î"<<endl;
    }
    
    system("pause");
    return 0;
}
