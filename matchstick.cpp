#include<iostream>
using namespace std;
int main()
{
    int play = 1;
    while (play == 1)
    {


    int n = 0, toss, left , computer , user;
    //1 user input 
    cout<<" WEL-COME TO MATCHSTICKS GAME \nenter the no of matchsticks\n ";
    while(n<=10)
    {
        cin>>n;
        if(n<=10) cout<<"invalid input please enter value greater than 10\n";

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
     //both players should play while more than one matchstick left
    if(toss == 1)
    {
        while(left  > 1)
        {
            cout<<"enter input\n";
             while(true)
            {
                cin>>user;
                if(user == 1 || user == 2 || user == 3 || user == 4)
                break;
                else
                cout<<"enter a valid number of sticks please\n";
                 

            }
            
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
        while(left > 1)
        {
            //comp will play
            if(left % 5 == 0) computer = 4;
            else if (left % 5 == 2) computer = 1;
            else if (left % 5 == 3) computer = 2;
            else if (left % 5 == 4) computer = 3;
            left = left - computer;
            cout<<"\ncomputer picks "<<computer<<" stikcs \nremaning sticks "<<left<<"\n";
            cout<<"enter input\n";
            while(true)
            {
                cin>>user;
                if(user == 1 || user == 2 || user == 3 || user == 4)
                break;
                else
                cout<<"enter a valid number of sticks please\n";
                 

            }
            left = left - user;
            cout<<" remaning sticks"<<left;
        }

    }
    if(left == 1) 
    cout<<"\ncomputer wins";
    cout<<"\npress  1 for play again \n0 fro exit";
    cin>>play;
     
    }
    return 0;
}