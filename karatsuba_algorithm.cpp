//constraint is that both number should be of same digits 
//if you take numbers with different digits then make necessary changes
#include<iostream>
#include<cstring>
using namespace std;
double multi(double x , double y , int mid);
double multi(double x , double y , int mid)
{
    if(mid < 1) return x*y;
    //try string
    
    
     // compute a b c d from x and y respectively
     int a, b, c, d , duplicate_mid=0,divisor=1 , duplicate_x , duplicate_y;
    duplicate_x =x;
    duplicate_y = y;
    duplicate_mid = mid;
    while(duplicate_mid>0) 
    {
        divisor = divisor * 10 ;
        duplicate_mid --;
    }
    a = x/divisor;
    b = duplicate_x%divisor;
    c = y/divisor;
    d = duplicate_y%divisor;
    // cout<<"a "<<a<<"\nb "<<b<<"\nc "<<c<<"\nd "<<d<<"\n";
    return (divisor*divisor)*(multi(a,c,mid/2))  + (divisor)*(multi(a,d,mid/2)) + (divisor)*(multi(b,c,mid/2)) + multi(b,d, mid/2);

}

main()
{
    cout<<"working\n";
    double answer = multi( 2  ,1000,1);
    cout<<"answer is "<<answer;
}