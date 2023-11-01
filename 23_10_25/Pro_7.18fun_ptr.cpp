#include<iostream>
double betsy(int);// 函数的地址：存储函数的机器语言代码的内存开始地址   
double pam(int);  // 函数指针,指向函数的地址

void estimate(int lines,double (*pa)(int));


int main()
{
    using namespace std;
    int code;
    cout<<"How many lines of code do you need?";
    cin>>code;
    cout<<"Here's Betsy's estimate:\n";
    estimate(code,betsy);// 函数double besty(int)中函数名besty就是函数的地址 besty == pa
    cout<<"Here's Pam's estimate:\n";
    estimate(code,pam);
    return 0;
}


double betsy(int lns)
{
    return 0.05*lns;
}

double pam(int lns)
{
    return 0.03*lns + 0.0004*lns*lns;
}

void estimate(int lines,double (*pa)(int))
{
    using namespace std;
    cout<<lines<<" lines will take ";
    cout<<(*pa)(lines)<<" hours"<<endl; // (*pa)(lines) == 函数名(lines) == 在函数estimate中根据不同的函数地址调用函数
}