#include<cmath>
#include<iostream>
#include<cstring>
using namespace std;
string add(string num1 , string num2)
{
    int carry=0;
    int sum = 0;
    string answer ;
    
    int length = max(num1.size() , num2.size());
    while(num1.size()<length) num1.insert(0,"0");
    while(num2.size()<length) num2.insert(0,"0");
    //perform add
    for(int i = length-1; i >= 0; i--)
    {
        sum = (num1[i]-'0')+(num2[i]-'0')+carry;
        carry = sum/10;
        answer.insert(0,to_string( (sum%10)));
    }
    if(carry)  answer.insert(0 ,to_string(carry));
   
    return answer;

}
string multi(string x , string y )

{
    int length = max(x.size() , y.size());
    while(x.size() < length) x.insert(0 , "0");
    while(y.size() < length) y.insert(0 , "0");
    if(length==1) 
    {
        return to_string((x[0]-'0')*(y[0]-'0'));
    }
    string a ,b  ,c ,d ;
    a = x.substr(0, ((x.size()/2)));
    b =  x.substr((x.size()/2), x.size() );
    c = y.substr(0, ceil((y.size()/2)));
    d =  y.substr((y.size()/2), y.size() );
    //find no of zeros to add
    string zeros = "1"; 
    
    int zero_int = stoi(zeros);
    string ac = (multi(a,c))  ; 
    string ad =  (multi(a,d)) ;
    string bc =  (multi(b,c)) ;
    string bd =  multi(b,d);

    for(int i=0;i<length;i++) ac.append("0");
    for(int i=0;i<(length)/2;i++)
    {
        ad.append("0");
        bc.append("0");
    }

    //now we need to create a function for addition 
    string answer =     add(add(add(ac,bd),bc),ad);
    return answer;

    
    

}
main()
{
    
    string answer = multi("3141592653589793238462643383279502884197169399375105820974944592", "2718281828459045235360287471352662497757247093699959574966967627");
    cout<<answer;
}
