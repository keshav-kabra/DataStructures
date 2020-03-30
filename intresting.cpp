#include<iostream>
#include<stack>
using namespace std;
stack<int> s1;
stack<int> s2;
int main()
{
    int first_number, second_number,pushed, digits =0, odd_digits=0 , even_digits =0,original_number, count =0, value;
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
                //count num of digits in number
                number=number/10;
                digits++;
                
            }
            number = i;
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













/*
i = original_number;
        cout<<"value "<<i<<"\n";
        if(digits % 2 == 0)
        {
            while(i>0)
            {
            even_digits++;
            i=i/10;

            if(i<0) break;
            odd_digits++;
            i= i/10;
            }
            

        }
        else
        {
            while(i>0)
            {
            i= i/10;
            odd_digits++;
            // thn even 
            if(i<0) break;
            even_digits++;
            i=i/10;
            }

        }
        cout<<"comming here";

        if(even_digits %2 != 0 && odd_digits %2 == 0)
        {
            cout<<original_number;
            count ++;
        }

    }
    cout<<"total numbers of number are" <<count<<"\n";
    return 0;
    */