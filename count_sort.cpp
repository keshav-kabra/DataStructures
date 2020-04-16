//implement count sort 
#include<iostream>
using namespace std;

main()
{
    int a[5] , b[5];
    for(int i=1;i<5;i++) b[i]=0;
    cout<<"enter the elements";
    for(int i=1;i<5;i++)
    {
        cin>>a[i];
        //implement b array
        b[a[i]]++;
    }
    cout<<"input array :";
    for(int i=1;i<5;i++) cout<<a[i]<<"\t";
    cout<<"\ninput array :";
    for(int i=1;i<5;i++) cout<<b[i]<<"\t";

    //printing the sorted array
    cout<<"\nsorted array:\t";
    for(int i=1;i<5;i++) 
    {
        if(b[i]>0)
        for (int j=1;j<=b[i];j++)
        cout<<i<<"\t";

        
        
    }
}