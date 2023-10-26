#include<iostream>
const int size = 8;
int sun_arr(int arr[],int n);
int main()
{
    using namespace std;
    int c[size] = {1,2,4,6,8,10,12,14};
    int sum = sun_arr(c,size);
    cout<<"sum = "<<sum<<endl;
    
    return 0;    
}
int sun_arr(int arr[],int n)
{
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    return sum;
}