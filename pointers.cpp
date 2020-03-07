#include<iostream>
using namespace std;
int increment(int *p);

int main()
{
    int a = 5, *p;
    cout<<a;
    p = &a;
    int** q = &p;
    **q = 6;
    cout<<&a<<"\n";  
    cout<<&p<<"\n";
    cout<<&q<<"\n";
    cout<<a<<"\n";
    cout<<p<<"\n";
    cout<<q<<"\n";
    cout<<*p<<"\n"; // 6
    cout<<*q<<"\n";// value at p i.e. add of a
    cout<<**q<<"\n";//6
    increment(&a);
    cout<<a;
    return 0;
}
int increment(int* x)
{
    *x = *x+1;
    return 0;

}

