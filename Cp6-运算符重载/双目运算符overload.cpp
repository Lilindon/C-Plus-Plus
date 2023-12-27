#include<iostream>
using namespace std;

class Complex
{
public:
    Complex(float x,float y)
        : m_x(x),m_y(y){};

    void dis();
    // 双目运算符重载 +=,-=
    Complex& operator+=(const Complex &c1);
private:
    float m_x;
    float m_y;
};

void Complex::dis()
{
    cout<<"x:"<<this->m_x<<" y:"<<this->m_y<<endl;
}
Complex& Complex::operator+=(const Complex &c1)
{
    this->m_x+=c1.m_x;
    this->m_y+=c1.m_y;
    return *this;
}

int main()
{
    Complex c1(1.0,2.0);
    Complex c2(2.0,3.0);
    c2.dis();
    c2+=c1;
    c2.dis();
    return 0;
}