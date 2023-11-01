#include<iostream>
using namespace std;

struct applicant{
    char name[20];
    int credit_ratings[3];
};


void f1(applicant *a);
const char * f2(const applicant *a1,const applicant *a2);


int main()
{

    system("pause");
    return 0;
}