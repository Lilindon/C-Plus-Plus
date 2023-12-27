#include<iostream>
// 隐式类型转换implicit 和 显式类型转换explicit

using namespace std;

class A
{
public:
    // 默认隐式类型转换implicit
    A(int i = 5)
    {
        this->m_a = i;
    }
    void dis()
    {
        cout<<this->m_a<<endl;
    }
private:
    int m_a;
};

class B
{
public:
    // 显式类型转换explicit
    explicit B(int i = 5)
    {
        this->m_a = i;
    }
    void dis()
    {
        cout<<this->m_a<<endl;
    }
private:
    int m_a;
};

int main()
{
    B s;
    s.dis();
    // s = 10;
    // 隐式转换为  s = A temp(10);
    // 报错 因为只允许显式转换 explicit
    s = B(20);// 这样可以转换
    s.dis();
    return 0;
}