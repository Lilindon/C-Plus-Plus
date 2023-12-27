#include<iostream>
#include<string>

using namespace std;

class Email;
class Sender;

class Sender
{
public:
    Sender(string addr)
        : m_addr(addr) {};
    // 接收邮箱的内容
    Sender& operator<<(const Email & email);
private:
    string m_addr;
};

class Email
{
public:
    Email(string title,string content)
        : m_title(title),m_content(content){};
    // 友元，访问邮件里的所有信息
    friend Sender& Sender::operator<<(const Email & email);
private:
    string m_title;
    string m_content;    
};

Sender& Sender::operator<<(const Email& email) // const Email& email 保证传入的信息不变;返回值为Sender& 传入已有对象中
{
    cout<<"Address:"<<m_addr<<endl;
    cout<<"Title:"<<email.m_title<<endl;
    cout<<"Content:"<<email.m_content<<endl;
    return *this;
}

int main()
{
    Sender sender("110@qq.com");
    Email emali1("note","meeting at 3pm");
    Email email2("tour","One night in beijing");
    sender<<emali1<<email2;
    return 0;
}