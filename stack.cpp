#include<iostream>
#include<stack>
#include<cstring  >
using namespace std;

void reverse_using_stack();
void reverse_linkedlist_using_stack(); // in singly linked list.cpp

void reverse_using_stack(char c[] , int length)
{
    stack<char> s;
    for(int i=0;i<length;i++) s.push(c[i]); // *(c+i)
    for( int i=0;i<length;i++) 
    {
    c[i] = s.top();
    s.pop();

    }
}


int main()

{
    
    char c[50];
    cout<<"enter the string";
    cin>>c;
    //for reversing a string of characters 
    reverse_using_stack(c , strlen(c));
    cout<<c;
    
    return 0;
}