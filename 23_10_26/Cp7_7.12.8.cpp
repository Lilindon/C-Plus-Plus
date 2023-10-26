#include<iostream>
using namespace std;
 
int replace(char* str, char c1, char c2); // 替换字符串中c1字符为c2字符

int main()
{
    char a[15] = "ha ha ha ha ha";
    cout<<a<<endl;
    int result = replace(a,'a','b');
    cout<<a<<endl;
    cout<<result<<endl;
    system("pause");
    return 0;
}

int replace(char* str, char c1, char c2)
{
    int count = 0;
    while(*str)
    {
        if(*str == c1)
        {
            *str = c2;
            count++;
        }
        str++;
    }
    return count;
}