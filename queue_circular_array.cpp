#include<iostream>
using namespace std;
int rear = -1 , front =0 , a[5];                                   
int enqueue(int element){
    //check if queue is full

    if ( ((front !=0) && (front == rear+1)) || (front == 0 && rear == 5 ))  cout<<"queue is full\n";
    else{   
        if(rear == 5) rear = -1;
        rear++;
        a[rear] = element;
    }
    return 0;
}
int dequeue(){
    front++;
    return 0;
}
int display(){   
  
    int i = front;
    do {
        if(i == 6) i= 0;
        cout<<"element at "<<i<<" - "<<a[i]<<"\n";
        i++;
    } 
    while (i!=rear) ;
    cout<<"element at "<<i<<" - "<<a[rear]<<"\n";    return 0;
   
}
int main()
{
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    display();
    dequeue();
    dequeue();
    enqueue(9);
    enqueue(10);
    display();

    return 0;
}







