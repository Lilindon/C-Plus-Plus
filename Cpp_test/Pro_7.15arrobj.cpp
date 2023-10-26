#include<iostream>
#include<array>
#include<string>

const int Seasons = 4;
const std::array<std::string,Seasons> Snames =   // const 显示的时候不改变其元素
    {"Spring","Summer","Fall","Winter"};
void fill(std::array<double,Seasons> *pa); // 记录一年四季的开支  array<double,Season> -> array<double,4>
void show(std::array<double,Seasons> da);


int main()
{
    std::array<double,Seasons> expenses;
    fill(&expenses);//按地址传递，处理原始对象
    show(expenses);//按值传递，处理副本
    return 0;
}

void fill(std::array<double,Seasons> *pa) // pa是指向std::array<double,Seasons>对象的指针
{
    using namespace std;
    for(int i =0;i<Seasons;i++)
    {
        cout<<"Enter"<<Snames[i]<<"Expenses:";  // 修改原始对象，添加Sname[i] 季节对象的花费
        cin>>(*pa)[i];      // (*pa)[i] 指向不同的元素
    }
}

void show(std::array<double,Seasons> da)  //  效率低，创建对象da存储Season的值，值传递的缺点
{
    using namespace std;
    double total = 0.0;
    for(int i=0;i<Seasons;i++)
    {
        cout<<Snames[i]<<" expense is"<<da[i]<<endl;  //值传递，显示Sname[i] 季节对象的花费
        total +=da[i];
    }
    cout<<"total expenses is "<<total<<endl;
}