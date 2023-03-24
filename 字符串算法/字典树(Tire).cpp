#include <iostream>
using namespace std;

struct trie{
    int nex[100000][26],cnt;
    bool exist[100000]; //该节点结尾的字符串是否存在

    void insert(char *s,int l){
        int p=0;
        for(int i=0;i<l;i++){
            int c=s[i]-'a';
            if(!nex[p][c])
                nex[p][c]=++cnt;//如果没有就添加节点
            p=nex[p][c];    //p指向下一节点
        }
        exist[p]=1;//表示以p节点结尾的字符串存在
    }

    bool find(char *s,int l){
        int p=0;
        for(int i=0;i<l;i++){
            int c=s[i]-'a';
            if(!nex[p][c])
                p=nex[p][c]; 
        }
        return exist[p];
    }
};
