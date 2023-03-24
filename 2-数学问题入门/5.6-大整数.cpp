1.定义
struct bign{
    int d[1000];
    int len;
    bign(){
        memset(d,0,sizeof(d));
        len=0;
    }
}

2.字符串转化为数字
bign change(char str[]){
    bign a;
    a.len=strlen(str);
    for(int i=0;i<a.len;i++){
        a.d[i]=str[a.len-1-i]-'0';
    }
    return a;
}

3.比较大小
int compare(bign a,bign b){
    if(a.len>b.len)
        return 1;//a>b
    else if(a.len<b.len)
        return -1;
    else{
        for(int i=a.len-1;i>=0;i--){
            if(a.d[i]>b.d[i])
                return 1;
            else if(a.d[i]<b.d[i])
                return -1;//a<b
        }
    }
    return 0;//a=b
}

4.加法
bign add(bign a,bign b){
    bign c;
    int carry=0;//进位
    for(int i=0;i<a.len||i<b.len;i++){//以较长的为界限
        int temp=a.d[i]+b.d[i]+carry;
        c.d[c.len++]=temp%10;
        carry=temp/10;
    }
    if(carry!=0)
        c.d[c.len++]=carry;//若最后的进位不是0，直接赋给最高位
    return c;
}//记得倒序输出！
5.减法
bign sub(bign a,bign b){
    bign c;
    for(int i=0;i<a.len||i<b.len;i++){
        if(a.d[i]<b.d[i]){
            a.d[i+1]--;
            a.d[i]+=10;
        }
        c.d[c.len++]=a.d[i]-b.d[i];
    }
    while(c.len-1>=1 && c.d[len-1]==0){
        c.len--;
    }
    return c;
}//使用前比较a，b的大小，若a<b,交换两变量，计算后输出符号

6.乘法(int型*大整数)
bign multi(bign a,bign b){
    bign c;
    int carry=0;
    for(int i=0;i<a.len;i++){
        int temp=a.d[i]*b+carry;
        c.d[c.len++]=temp%10;
        carry=temp/10;
    }
    while(carry!=0){
        c.d[c.lem++]=carry%10;
        carry/=10;
    }
    return c;
}

7.除法(高精度与低精度的)
bign divide(bign a,bign b,int& r){//r为余数
    bign c;
    c.len=a.len;//被除数的每一位是相对应的，先令长度相等
    for(int i=a.len-1;i>=0;i--){//从高位开始
        r=r*10+a.d[i];
        if(r<b)//不够除
            c.d[i]=0;
        else{//够除
            c.d[i]=r/b;//商
            r=r % b;//新的余数
        }
    }
    while(c.len-1>=1 && c.d[len-1]==0)
        c.len--;
        
    return c;
}