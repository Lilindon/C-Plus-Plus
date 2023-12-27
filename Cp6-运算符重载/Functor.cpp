#include<iostream>
// functor 仿函数 重载 operator()
// 个人理解：使得相同的代码 应用于不同的数据类型中 类似template和STL


using namespace std;

class Sqr
{
public:
    int operator()(int i)
    {
        return i*i;
    }
    double operator()(double d)
    {
        return d*d;
    }

};


int main()
{
    Sqr sqr;
    int i = sqr(4);  // sqr.operator()(4);
    double d = sqr(5.5); // sqr.operator()(5.5);
    cout<<i<<endl;
    cout<<d<<endl;
    return 0;
}