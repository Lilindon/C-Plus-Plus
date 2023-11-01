#include<iostream>
const int size = 8;
int sum_arr(int arr[],int n);
int main()
{
    using namespace std;
    
    int c[size] = {1,2,4,6,8,10,12,14}; //创建数组c[size] = {}
    int sum = sum_arr(c,size);          //调用函数sum_arr(数组地址c=arr[],长度size)
    cout<<"sum = "<<sum<<endl;
    
    return 0;    
}
int sum_arr(int arr[],int n)
{
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }

    return sum;
}