#include<iostream>
using namespace std;

int main()
{
    int first_number, second_number, odd_digits=0 , even_digits =0, count =0, value;
    cout<<"enter the range\n ";
     cin>>first_number;
     cin>>second_number;
        for(int i= first_number+1;i<= second_number;i++)
        {
            int number = i;
            digits =0;
            even_digits = 0;
            odd_digits =0;
            while(number>0)
            {
                value = number%10;
                if(value % 2 == 0) even_digits++;
                else odd_digits++;
                number = number /10;
         
            }
            if(odd_digits %2 == 0 && even_digits %2 != 0)
            {
               
                count++;
            }
        }
        
        cout<<"total number of inresting numbers are"<<count;

        
}











