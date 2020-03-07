#include<iostream>
using  namespace std;
int front = 0 , rear = -1 , a[5];
int enqueue(int element)
{
    //check if queue is full
    
    if(rear == 5) cout<<"queue is full\n";
    else
    {
        rear++;
        a[rear] = element;
    }
    return 0;
}
int dequeue()
{
    front++;
    return 0;
}
int display()
{
    for(int i = front;i<=rear;i++) 
    cout<<"element at"<<i<<" - "<<a[i]<<"\n";
    return 0;
}
int main()
{
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    enqueue(9);
    display();
    
    return 0;
}




