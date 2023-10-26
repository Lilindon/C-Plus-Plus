#include<iostream>


int main()
{
    int age = 10;
    const int* pt = &age;      //const int* pt = &age; const修饰指针的指向不发生改变
    std::cout<<*pt<<std::endl; //10
    age = 20;
    std::cout<<*pt<<std::endl; //20 

    const int age2 = 10;       // age2值不变
    const int* pt2 = &age2;    
    std::cout<<*pt2<<std::endl;// 10

    int age3 = 20;
    int* pt3 = &age3;         
    const int* pt4 = pt3;        
    std::cout<<*pt3<<std::endl;//20
    std::cout<<*pt4<<std::endl;//20
    return 0;
}