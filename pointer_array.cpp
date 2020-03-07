#include<iostream>
using namespace std;
void add(int p[])
{
//    cout<<*p; 
//     for(int i =0;i<5;i++) 
//     {
//     cout<<*p<<"\n";
//     p=p+1;
//     }
    cout<<p;
    for(int i=0;i<5;i++)
    {
        cout<<i<<"\t"<<p[i]<<"\n"; //writing p[i] is same as wrting *(p+i)
        
    }
}

int main()
{
    

    int i=0;
    // string s[] = {"K","E"};
    
    
    // char c[] = {'k','e','s','h','a','v','\0'};
    // cout<<c;
    int a[] = {1,3,5,2,6};
    add(a); // here passing c is equivalent to passing &c[0]
    return 0;
}