#include<iostream>
using namespace std;

struct applicant{
    char name[30];
    int credict_rating[3];
};

void show_by_value(const applicant ap);// 结构体按值传递
void show_by_reference(const applicant * app);// 结构体按地址传递

int main()
{
    applicant app1 = {"Andy",3,2,1};// 结构体变量声明时就需要定义，并且不可修改
    show_by_value(app1);
    show_by_reference(&app1);
    system("pause");
    return 0;
}

void show_by_value(const applicant ap)
{
    cout<<"name:"<<ap.name<<endl;
    for(int i=0;i<3;i++)
        cout<<ap.credict_rating[i]<<" ";
    cout<<endl;
}

void show_by_reference(const applicant * app)
{
    cout<<"name by reference:"<<(*app).name<<endl;
    cout<<app->name<<endl;
    for(int i = 0;i<3;i++)
    {    
        // cout<<(*app).credict_rating[i]<<" ";
        cout<<app->credict_rating[i]<<" ";
    }    
    cout<<endl;
}