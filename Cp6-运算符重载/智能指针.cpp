#include<iostream>
#include<memory>
using namespace std;

class A
{
public:
    A()
    {
        cout<<"A() constructor"<<endl;
    }
    ~A()
    {
        cout<<"A() destructor"<<endl;
    }
    void func()
    {
        cout<<"abc"<<endl;
    }
};

class Sp
{
public:
    Sp(A *p)
        :m_p(p){}
    ~Sp()
    {
        delete m_p;
    }

    A *operator->()
    {
        cout<<"智能指针重载1"<<endl;
        return m_p;
    }
    A& operator*()
    {
        cout<<"智能指针重载2"<<endl;
        return *m_p;
    }
    

private:
    A *m_p;
};

void foo()
{
//     A *p = new A;
        // 若不写delete 虽可执行 但会导致内存泄漏
//     delete p;

    // include<memory>
    // 智能指针
    // auto_ptr<A> ptr (new A); // 本质重载 -> 与 *
    // ptr->func();
    // (*ptr).func();

    Sp sp(new A);
    sp->func();
    (*sp).func();

}


int main()
{
    foo();
    return 0;
}


/*
    RAII (resource acquisition is initialization) 利用对象生命周期 控制程序资源的简单技术
    智能指针，为解决内存泄露问题所提出的一种具有类似指针功能的对象
    原理：智能指针具有生命周期，自动调用析构函数删除指向的内存
    C++98 auto_ptr<>
    C++11 unique_ptr  shared_ptr weak_ptr

    auto_ptr<Test> test(new Test);
    test->func();  // 底层实现由 成员函数重载 Test* operator->(){ return test;}
    (*test).func();// 底层实现由 成员函数重载 Test& operator*(){ return *test;}

    智能指针三个常用函数
    get() 获取智能指针托管的指针地址
    release() 取消智能指针对动态内存的托管
    reset() 重置智能指针托管的内存地址
*/ 
