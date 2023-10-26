#include<iostream>
using namespace std;

//判断输入的是字母


int main()
{
    char ch;
    cout<<"Enter a letter"<<endl;
    cin>>ch;
    if(ch>='a'&&ch<='z')
    {
        cout<<"是小写字母"<<endl;
    }
    else if (ch >='A' && ch<='Z')
    {
        cout<<"是大写字母"<<endl;
    }
    else
        cout<<"不是字母";
    return 0;
}