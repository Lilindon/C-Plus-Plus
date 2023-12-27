#include<iostream>
using namespace std;

void MyFunc(){}; // 全局函数

class Other; // 友元的对象类 

class Me
{
public:
    Me(int age,string name)
        : m_age1(age),m_name1(name){};
    ~Me();
    void Swap(Other &oth); // 不同类中的友元函数

private:
    int m_age1;
    string m_name1;
};

class Friend
{
public: 
    Friend(){};
    ~Friend(){};
    void ShowOther(Other &oth);
};

class Other
{
public:
    Other(){};
    Other(int age,string name)
        : m_age(age),m_name(name){};
    ~Other();

    void show();
    friend void MyFunc(Other &oth); // 全局函数作为友元函数
    friend void Me::Swap(Other &oth); // 其他类中的成员函数作为友元函数
    // friend Friend;        // 其他类作为友元类 或者写成 friend class Friend;
    friend class Friend;
private:
    int m_age;
    string m_name;
};



void Other::show()
{
    cout<<"name: "<<this->m_name<<endl;
    cout<<"age: "<<this->m_age<<endl;
}

void Me::Swap(Other &oth)
{
    cout<<"age(Me)::"<<this->m_age1<<endl;
    cout<<"name(Me)::"<<this->m_name1<<endl;
    oth.show();
}

void Friend::ShowOther(Other &oth)
{
    cout<<"age(Fri)—>oth:"<<oth.m_age<<endl;
    cout<<"name(Fri)—>oth:"<<oth.m_name<<endl;
}
Other::~Other()
{
}
Me::~Me()
{
}

void MyFunc(Other &oth) // 全局函数 作为类的友元函数变为 类的静态成员函数
{
    // this只能用于非静态成员函数 ？
    cout<<"name(Other):"<<oth.m_name<<endl;
    cout<<"age(Other):"<<oth.m_age<<endl;
}

int main()
{
    Other oth1(19,"string");
    oth1.show();
    MyFunc(oth1);
    Me me(15,"wuda");
    me.Swap(oth1);
    Friend fri1;
    fri1.ShowOther(oth1);

    return 0;
}

