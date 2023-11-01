#include<iostream>

const int limit = 5;
int fill_arr(double arr[],int max_capacity);    // 添加数组元素
void show_arr(const double arr[],int n);        // 显示数组元素
void reset_arr(double ratio,double arr[],int n);// 重新设置数组元素

int main()
{
    using namespace std;

    double arr[limit];      // 声明数组 arr[limit]
    int size = fill_arr(arr,limit); // 添加数组元素 接受返回值int size = fill_arr(数组地址arr[]==arr,数组容量=limit)
    show_arr(arr,size);     // 显示数组元素 返回值为void  show_arr(数组地址const double arr[]==arr,显示数组个数=size)
    if(size>0)   // 若size>0,数组中存在元素
    {
        cout<<"input factor:"<<endl;
        double factor;      // 要添加的元素
        while((cin>>factor))// 元素加入到输入队列中  当cin为回车时视为0 退出while
        {
            cin.clear();    
            while(cin.get()!='\n')// 若不为回车，则继续
                continue;
            cout<<"bad input"<<endl;
        } 
        reset_arr(factor,arr,size);// 重新设置数组元素 reset_arr(放缩因子,数组首地址arr[]=arr,放缩个数size)
    }
    cin.get();
    cin.get();
    return 0;
}

int fill_arr(double arr[],int max_capacity)
{   
    using namespace std;

    double tmp;
    int i;
    for(i = 0;i<max_capacity;i++)
    {   
        cout<<"Enter insert factor:"<<endl;
        cin>>tmp;
        if(!cin)
        {
            cin.clear();
            while (cin.get()!='\n')
                continue;
            cout<<"bad input"<<endl;
            break;
        }
        else if(tmp<0)
            break;
        arr[i] = tmp;
    }

    return i;
} 

void show_arr(const double arr[],int n)
{
    using namespace std;
    
    for(int i = 0;i<n;i++)
    {
        cout<<"i = "<<i+1<<endl;
        cout<<arr[i]<<endl;
    }
}

void reset_arr(double ratio,double arr[],int n)
{
    for(int i = 0;i<n;i++)
    {
        arr[i]*=ratio;
    }
}