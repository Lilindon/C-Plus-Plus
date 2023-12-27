#include<iostream>

using namespace std;
class Complex
{
public:
    Complex(float x,float y)
        : m_x(x),m_y(y){};

    void dis();
    // 友元运算符重载 运算符重载也叫函数重载
    friend const Complex operator+(const Complex &c1,const Complex &c2);
    // 成员运算符重载
    const Complex operator-(const Complex &c1);
    const Complex operator+(const Complex &c1);
private:
    float m_x;
    float m_y;
};

void Complex::dis()
{
    cout<<"x :"<<this->m_x<<" y: "<<this->m_y<<endl;
}

const Complex operator+(const Complex &c1,const Complex &c2)
{
    cout<<"友元函数重载"<<endl;
    return Complex(c1.m_x+c2.m_x,c1.m_y+c2.m_y);
}

const Complex Complex::operator-(const Complex &c1)
{
    cout<<"成员函数重载"<<endl;
    return Complex(this->m_x-c1.m_x,this->m_y-c1.m_y);
}

const Complex Complex::operator+(const Complex &c1)
{
    cout<<"成员函数重载"<<endl;
    return Complex(this->m_x+c1.m_x,this->m_y+c1.m_y);
}

int main()
{
    Complex c1(1.0,2.0);
    Complex c2(2.0,3.0);
    Complex c3 = c1+c2; // 友元函数重载   当友元函数重载与成员函数重载为同一运算符时，优先成员函数重载
    c3.dis();
    Complex c4 = c2-c1; // 成员函数重载
    c4.dis();
    return 0;
}