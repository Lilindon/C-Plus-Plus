#include<iostream>
using namespace std;

class Complex
{
public:
    Complex(float x,float y)
        : m_x(x),m_y(y){};

    void dis();


    
    // 前向++

    // 成员函数重载 const Complex& operator+(void) const; // 只读
    // Complex& operator++(void);
    
    // 友元函数重载 
    friend Complex& operator++(Complex &c1); 

    // 后向++
    // 成员函数重载 const Complex operator++(int);
    
    // 友元函数重载 
    friend const Complex operator++(Complex &c1,int);

    // 使用友元 避免修改C++标准库
    friend ostream& operator<<(ostream &os,const Complex &c); // 输出时保证不要修改输入Complex
    friend istream& operator>>(istream &is,Complex &x);
private:
    float m_x;
    float m_y;
};

void Complex::dis()
{
    cout<<"x:"<<this->m_x<<endl;
    cout<<"y:"<<this->m_y<<endl;
}

// 前向++ 第一种方法 成员函数 void
// Complex& Complex::operator++(void)
// {
//     cout<<"成员：前向++"<<endl;
//     this->m_x++;
//     this->m_y++;
//     return *this;
// }

// 前向++ 第二种方法 友元函数 引用
Complex& operator++(Complex &c1)
{
    cout<<"友元：前向++"<<endl;
    c1.m_x++;
    c1.m_y++;
    return c1; 
}

// 后向++ 方法一 ： const Complex 作为返回值 传参:int
// const Complex Complex::operator++(int)
// {
//     cout<<"成员：后向++"<<endl;
//     Complex t = *this;
//     m_x++;
//     m_y++;
//     return t;
// }

// 后向++ 方法二： friend const Complex operator++(Complex &c,int);
const Complex operator++(Complex &c1,int)
{
    cout<<"友元：后向++"<<endl;
    Complex t(c1.m_x,c1.m_y);
    c1.m_x++;
    c1.m_y++;
    return t;
}

ostream& operator<<(ostream& os,const Complex &c)
{
    os<<"("<<c.m_x<<","<<c.m_y<<")"<<endl;
    return os;
}

istream& operator>>(istream& is,Complex &c)
{
    is>>c.m_x>>c.m_y;
    return is;
}

// int main()
// {
//     Complex c1(1.0,2.0);
//     c1.dis();
    
//     ++c1;
//     c1.dis();
//     c1++;
//     c1.dis();
//     return 0;
// }

int main()
{
    Complex c1(2,3);
    cout<<c1;
    cin>>c1;
    cout<<c1;
    return 0;
}