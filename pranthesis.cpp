//program for finding out string is a proper paranthesis or not
//assumption no space in input stack

#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
int main()
{
    stack<char> paranthesis_stack; 
    string s;
    cin>>s;
    //check if string is a balance parathesis
    
    for(int i =0;i<s.size();i++)
    {
        if(s[i] == '(' ||s[i] == '{' ||s[i] == '[' )
        {
            paranthesis_stack.push(s[i]);
        }
        else if(s[i] == ')')
        {
            int value = paranthesis_stack.top();
            if(value == '(') paranthesis_stack.pop();
            else {
                cout<<"imbalance paranthesis 1 ";
                return 0;
            }
        }
        else if(s[i] == '}')
        {
            int value = paranthesis_stack.top();
            if(value == '{') paranthesis_stack.pop();
            else {
                cout<<"imbalance paranthesis 2";
                return 0;
            }
        }
        else if(s[i] == ']')
        {
            int value = paranthesis_stack.top();
            if(value == '[') paranthesis_stack.pop();
            else {
                cout<<"imbalance paranthesis 3";
                return 0;
            }
        }
    }
    
    if(paranthesis_stack.empty()) cout<<"balance paranthesis";
    else cout<<"imbalance paranthesis";
    // while(!paranthesis_stack.empty())
    // {
    //     cout<<paranthesis_stack.top()<<"\n";
    //     paranthesis_stack.pop();


    // }



    return 0;
}