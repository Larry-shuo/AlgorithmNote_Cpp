
/*实现栈的清空：
(1)
while(!st.empty()){
    st.pop();
}//也可用作初始化栈

(2)重新定义一个栈代替*/


//Codeup 1918 简单计算器

#include<iostream>
#include<stack>
#include<string>
#include<queue>
#include<map>
using namespace std;

struct node{
    double num;
    char op;
    bool flag;
};

string str;
stack <node> s;//操作符栈
queue<node> q;//后缀表达式序列
map<char,int>op;//记录操作符的优先级

void Change(){
    double num;
    node temp;
    for(int i=0;i<str.length();){
        if(str[i]>='0'&&str[i]<='9'){//若是数字
            temp.flag=true;
            temp.num=str[i++]-'0';
            while(i<str.length()&&str[i]>='0'&&str[i]<='9'){//该数字可能不止一位
                temp.num=temp.num*10+(str[i]-'0');
                i++;
            }
            q.push(temp);//压入后缀表达式的队列
        }
        else{
            temp.flag=false;
            //若操作符栈顶的操作符的优先级高于该操作符，就将栈顶元素弹出压入后缀队列中
            while(!s.empty()&& op[s.top().op]>=op[str[i]]){
                q.push(s.top());
                s.pop();
            }
            temp.op=str[i];
            s.push(temp);
            i++;
        }
    }
    while(!s.empty()){//若操作符栈还有元素
        q.push(s.top());
        s.pop();
    }
}

double Cal(){//此时s为运算结果栈
    double temp1,temp2;
    node cur,temp;
    while(!q.empty()){
        cur=q.front();//cur记录队首元素
        q.pop();
        if(cur.flag==true)//若是数字，压入栈
            s.push(cur);
        else{//若是操作符
            temp2=s.top().num;//第二操作数
            s.pop();
            temp1=s.top().num;//第一操作数
            s.pop();

            temp.flag=true;
            if(cur.op=='+')
                temp.num=temp1+temp2;
            else if(cur.op=='-')
                temp.num=temp1-temp2;
            else if(cur.op=='*')
                temp.num=temp1*temp2;
            else
                temp.num=temp1/temp2;
            
            s.push(temp);
        }
    }
    return s.top().num;
}
int main()
{
    op['+']=op['-']=1;//设置优先级
    op['*']=op['/']=2;

    while(getline(cin,str),str!="0"){
        for(string::iterator it=str.end();it!=str.begin();it--){
            if(*it==' ')
                str.erase(it);//去掉表达式中的空格
        }
        while(!s.empty())//初始化栈
            s.pop();
        Change();
        cout<<Cal()<<endl;
    }
    system("pause");
    return 0;
}