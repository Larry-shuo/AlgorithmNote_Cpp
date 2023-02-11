#include<algorithm>

1.表示分数：使用结构体
struct Fraction{
    int up,down;//分子与分母
}

Fraction reduction(Fraction result){
    //1.若分母为负
    if(result.down<0){
        retult.up=-retult.up;
        retult.down=-retult.down;
    }
    //2.若分子为0
    if(retult.up==0)
        retult.down=1;
    else{//3.分子不为0，约分
        int d=gcd(abs(retult.up),abs(retult.down));//<algorithm>
        retult.up/=d;
        retult.down/=d;
    }
    return result;
}
2.运算
Fraction add(Fraction f1,Fraction f2){//加法
    Fraction result;
    result.up=f1.up*f2.down+f2.up*f1.down;
    result.down=f1.down*f2.down;
    return reduction(result);
}
//减法...乘法...除法