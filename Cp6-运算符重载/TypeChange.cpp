#include<iostream>
 
using namespace std;

class Point3D;

class Point2D
{
public:
    Point2D(int x,int y)
        :m_x(x),m_y(y){};

    void dis();
    friend Point3D;// 友元类 使得3D中可以访问2D中的所有元素

    // 类型转换方法二 成员函数 operator 操作符函数转换
    operator Point3D();

private:
    int m_x;
    int m_y;
};

class Point3D
{
public:
    Point3D(int x,int y,int z)
        :m_x(x),m_y(y),m_z(z){};
    
    // 类型转换  分为隐式类型转换/显式类型转换; 不加关键字默认为隐式转换implicit 显式类型转换要加关键字explicit
    // explicit关键字只能用于类内部的构造函数声明上
    
    // 类型转换方法一  友元类 构造函数转换
    explicit Point3D(Point2D &p)
    {
        this->m_x = p.m_x;
        this->m_y = p.m_y;
        this->m_z = 0;
    }

    void dis();
private:
    int m_x;
    int m_y;
    int m_z;
};

void Point2D::dis()
{
    cout<<"Point2D::dis()"<<endl;
    cout<<" x = "<<this->m_x<<" y = "<<this->m_y<<endl;
}

Point2D::operator Point3D()
{
    return Point3D(m_x,m_y,0);
}

void Point3D::dis()
{
    cout<<"Point3D::dis()"<<endl;
    cout<<" x = "<<this->m_x<<" y = "<<this->m_y<<" z = "<<this->m_z<<endl;;
}

int main()
{
    Point2D p1(2,3);
    p1.dis();
    Point3D p2(3,4,5);
    p2.dis();
    Point3D p3(p1);
    p3.dis();
    
    // cout<<" implicit隐式类型转换 "<<endl;
    // Point3D p4 = p1;
    // p4.dis();

    cout<<" explicit显式类型转换 "<<endl;
    Point3D p5 = static_cast<Point3D> (p1);
    p5.dis();
    return 0;
}