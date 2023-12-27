#include<iostream>

using namespace std;
class Complex
{
public:
    Complex(float x,float y)
        : m_x(x),m_y(y){};

    void dis();
    // 返回值类型前加const有什么区别？ const加在前面，表示函数不修改成员变量，加在最后表示只读函数
    // friend Complex operator+(const Complex &c1,const Complex &c2);
    friend const Complex operator+(const Complex &c1,const Complex &c2);
private:
    float m_x;
    float m_y;
};

const Complex operator+(const Complex &c1,const Complex &c2)
{
    return Complex(c1.m_x+c2.m_x,c1.m_y+c2.m_y); //利用有参构造函数
}

void Complex::dis()
{
    // cout输出6位有效数
    cout<<"x = "<<this->m_x<<" y = "<<this->m_y<<endl;
}

int main()
{
    Complex c1(11.0001,2.0);
    Complex c2(2.0,3.0);
    Complex c3 = c1+c2;
    c3.dis();
    return 0;
}