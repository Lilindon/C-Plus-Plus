#include<iostream>
using namespace std;

//�ж����������ĸ


int main()
{
    char ch;
    cout<<"Enter a letter"<<endl;
    cin>>ch;
    if(ch>='a'&&ch<='z')
    {
        cout<<"��Сд��ĸ"<<endl;
    }
    else if (ch >='A' && ch<='Z')
    {
        cout<<"�Ǵ�д��ĸ"<<endl;
    }
    else
        cout<<"������ĸ";
    return 0;
}