#include<iostream>
using namespace std;
int main()
{
    int a[] = {0,0,0,1,1,1,1,1,1,1};
    int  i, index=0;
    //count no 0's or 1's
    for(i=0;i<10;i++)
    {
        if(a[i] == 0)
        {
            swap(a[i],a[index]);
            index++;
        }
    }
    for( i=0;i<10;i++)cout<<a[i]<<"\t";
    return 0;
}