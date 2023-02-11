1.素数的判定
bool isPrime(int n){
    if(n<=1)
        return false;
    
    int sqr=(int)sqrt(1.0*n);//将int型n转化为double型
    for(int i=0;i<sqr;i++){
    //for(int i=0;i*i<n;i++)也可行，前提是i*i不会溢出!
        if(n%i==0)
            return false;
    }
    return true;
}

2.素数表
（1）.循环打表，在10^5范围内可以接受
（2）.埃氏筛法，Eratosthenes

代码如下：
const int maxn=101;
int prime[maxn],pnum=0;
bool p[maxn]={0};//默认素数为0
void Find_Prime(){
    for(int i=2;i<maxn;i++){
        if(p[i]==false){//若i是素数
            prime[pnum++]=i;
            for(int j=2*i;j<maxn;j+=i){//筛去i的倍数
                p[j]=true;
            }
        }
    }
}

