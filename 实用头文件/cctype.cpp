#include <cctype>
//字符处理功能,这个头函数声明了一组函数来分类和转换单个字符。
using namespace std;


int isalnum(int c);
//如果c是字母、数字，返回true ; 否则返回false

int isalpha(int c);
//检查字符是否为字母。如果是字母则返回true

int isblank(int c);
//检查参数c是否为空格

int isdigit(int c);
//检查参数c是否为十进制数字。

int islower(int c);
int isupper(int c);
//检查字符是否为：小写字符字母/大写字符字母

int tolower(int c);
//大写转小写
int toupper(int c);
//小写转大写