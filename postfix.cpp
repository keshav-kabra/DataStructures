//we will find the value of a particular postfix string
#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int evaluate_postfix(string str , int length);
int airthmetic_operation(int value1, int value2 , char o);

int airthmetic_operation(int value1, int value2 , char o)
{
    int calculated_value = 0;
    if(o == '+') calculated_value = value1 + value2;
    else if(o == '-') calculated_value = value1 - value2;
    else if(o == '*') calculated_value = value1 * value2;
    else if(o == '/') calculated_value = value1 / value2;
    return calculated_value;


}
int evaluate_postfix(string str , int length)
{
    stack<int> s;
    if(s.empty()) cout<<"stack is emplty";
    // int value1 , value2, result,calculated_value;
    //1.scan the list
    for(int i=0;i<length;i++)
    {
        if(str[i] == '+'||str[i] == '-'||str[i] == '/'||str[i] == '*')
        {
            int value1 = s.top();
            s.pop();
            int value2 = s.top();
            s.pop();

            cout<<"\nvalues gained from stack are "<<value1<<"\t"<<value2;
            
            int calculated_value = airthmetic_operation(value1 , value2 , str[i]);
            s.push(calculated_value);
        }
        else
        {
            str[i] = int(str[i]);// gives the ascii value of the string literal;
            s.push(str[i]-48);
        }
    }
    //top value of stack will be my final result value
    int result = s.top();
    return result;

}

int main()
{
    string str ;
    cout<<"enter a valid postfix string without space";
    cin>>str;
    int result = evaluate_postfix(str ,str.size());
    cout<<"\nresult is "<<result; 
    return 0;
}