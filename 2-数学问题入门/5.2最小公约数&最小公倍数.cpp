1.
gcd(a,b)来代表a和b的最大公约数
gcd(a,b)=gcd(b,a%b)

//代码1
int gcd(int a,int b){  //a>b
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
//代码2
int gcd(int a,int b){
    return !b ? a : gcd(b,a%b);
}

2.
lcm(a,b)表示a和b的最小公倍数

lam(a,b)=a*b/gcd(a,b)
lam(a,b)=a*gcd(a,b)/b//(数字a*b不会因太大而溢出)
