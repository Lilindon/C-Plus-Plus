#include<iostream>

using namespace std;

// 重载：运算符重载(本质函数重载)
//  友元 重载
//  成员 重载    当成员函数与友元函数  重载同一运算符时，优先调用成员函数重载

class Complex
{
public:
    Complex(float x,float y)
        :m_x(x),m_y(y){};

    void dis();

    friend const Complex operator+(const Complex &c1,const Complex &c2);

    const Complex operator+(Complex &c);

    // 前向++ 成员重载
    Complex& operator++(void);

    // 后向++ 成员重载
    // const Complex operator++(Complex &c,int); // 报错 参数过多 原因成员函数重载 只能有一个参数
    const Complex operator++(int);  // 前面的const 保持成员不改变

private:
    float m_x;
    float m_y;
};

void Complex::dis()
{
    cout<<" x= "<<this->m_x<<endl;
    cout<<" y= "<<this->m_y<<endl;
}

// 友元函数重载
const Complex operator+(const Complex &c1,const Complex &c2)
{
    cout<<"友元函数重载"<<endl;
    return Complex(c1.m_x+c2.m_x,c1.m_y+c2.m_y);
}

// 成员函数重载
const Complex Complex::operator+(Complex &c)
{
    cout<<"成员函数重载"<<endl;
    return Complex(this->m_x+c.m_x,this->m_y+c.m_y);
}

// 前向++ 成员重载
Complex& Complex::operator++(void)
{   
    cout<<"前向++ 成员函数重载"<<endl;
    this->m_x++;
    this->m_y++;
    return *this;
}

// 后向++ 成员重载
const Complex Complex::operator++(int)
{
    Complex t = *this;  // 保存原有对象地址
    this->m_x++;        // 原有对象++
    this->m_y++;
    return t;           // 返回原对象地址 后向++本质：1.保存原有对象地址；2.原有对象++；3.返回新对象 即不发生自加对象的地址。
}


int main()
{
    Complex c1(1,2);
    Complex c2(2,3);
    Complex c3 = c1+c2;
    c3.dis();
    ++c3;
    c3.dis();
    return 0;
}