#include<iostream>
#include"utility/smart_ptr.h"

using namespace Wuda::utility;

class Test
{
public:
    Test() = default;  // default 告诉编译器声明 无参的默认构造函数 
    // 上面等价于下面     区别：1.多文件编成时 default声明的构造函数 不需要在写实现 
    //                      2.代码执行效率，default定义的构造函数，在声明时 编译器不会调用构造函数 不会生成相应代码
    //                        用户自己声明了构造函数会造成编译器开辟完内存后会去调用一次构造函数。
    // Test(){}
    Test(int a):m_a(a){}
    ~Test()
    {
        std::cout<<"Test is deleted"<<std::endl; 
    }
    void dis()
    {
        std::cout<<m_a<<std::endl;
    }

private:
    int m_a;
};



int main()
{
    auto p = new Test(10);
    SmartPtr<Test> sp(p);   // 智能指针SmartPtr<类型> 智能指针对象名()
    (*sp).dis();
    return 0;
}