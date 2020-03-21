#include<iostream>
using namespace std;
int main()
{
    int n = 0, toss, left , computer , user;
    //1 user input 
    cout<<"enter the no of matchsticks\n ";
    while(n<=10)
    {
        cin>>n;
        if(n<=10) cout<<"ivvalid input please enter value greater than 10\n";

    }
    left = n;
    //2.decide with toss
    if(n%5 == 1) 
    {
          toss = 1;
        cout<<"user will play first\n";
        
    }
    else
    {
      
        cout<<"computer won the toss\n";
        toss = 2;
        cout<<"computer will play first\n";
    }
     //both players should play while n > 0
    if(toss == 1)
    {
        while(left>1)
        {
            cout<<"enter input\n";
            cin>>user;
            left = left - user;
            cout<<" remaning sticks "<<left<<"\n";
            //comp will play
            if(left % 5 == 0) computer = 4;
            else if (left % 5 == 2) computer = 1;
            else if (left % 5 == 3) computer = 2;
            else if (left % 5 == 4) computer = 3;
            left = left - computer;
            cout<<"computer picks "<<computer<<" stikcs\nremaning sticks "<<left<<"\n";
        }
    }
    else
    {
        while(left>1)
        {
            //comp will play
            if(left % 5 == 0) computer = 4;
            else if (left % 5 == 2) computer = 1;
            else if (left % 5 == 3) computer = 2;
            else if (left % 5 == 4) computer = 3;
            left = left - computer;
            cout<<"\ncomputer picks "<<computer<<" stikcs \nremaning sticks "<<left<<"\n";
            cout<<"enter input\n";
            cin>>user;
            left = left - user;
            cout<<" remaning sticks"<<left;
        }

    }
    if(left == 1) 
    cout<<"computer wins";
    return 0;
}