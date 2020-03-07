#include<iostream>
using namespace std;
struct node{
    int data;
    node* next ; 
    node* back ;
};
node* head = NULL;
int insert(int value);
int insert_at_nth_position(int value , int position);
int update_at_nth_position (int value , int position);
int print();
int print_reversre();
int delete_node(int position);

int  insert(int value)
{
    //1. create new node
    node* temp = new node();
    //2. assign values to fields
    temp->data = value;
    temp->back = NULL;
    temp->next = NULL; 
     //3. adjust head
    if(head == NULL) head = temp;
    else {
        node* temp1 = head;
        while(temp1->next != NULL) temp1 = temp1->next;
        temp1->next = temp;
        temp->back = temp1;
    }
    return 0;
}
int insert_at_nth_position(int value , int position){

   
    node *temp1 = head, *temp2 = head;
    node* temp = new node();
    temp->data = value;
    temp->next = NULL;
    temp->back = NULL;
    //loop till back node of given position
      if(position == 1)
    { 
        temp->next = head;
        head->back = temp;
        head = temp;
    }else{

    for(int i = 0;i<position-2;i++)   temp1 = temp1->next;
    for(int i=0;i<position;i++) temp2=temp2->next;
   
    temp->next = temp1->next;
    temp1->next = temp;
    temp->back = temp1;
    temp2->back = temp;
    }

    return 0;
}
int print(){
    
    node *temp = head;
    cout<<"\nLIST :";
    while(temp!=NULL)
    {
        cout<<temp->data<<"\t";
        temp = temp->next;
    }
    return 0;
}
int print_reversre()
{
    node* temp = head;
    cout<<"\nLIST : ";
    while(temp->next!= NULL)
    temp = temp->next;
    while(temp!=NULL)
    {
    cout<<temp->data<<"\t";
    temp = temp->back;
    }
    return 0;
}
int update_at_nth_position(int value, int position)
{
    node* temp = head;
    for(int i=0;i<position-1;i++)  temp = temp->next;
    temp->data = value;
    return 0;
    
}
int delete_node(int position)
{
    node *temp1 = head , *temp2 = head;
    for(int i=0;i<position-2;i++) temp1 = temp1->next;
    for(int i=0;i<position;i++) temp2 = temp2->next;
  
    temp1->next = temp2;
    temp2->back = temp1;
    return 0;

}

int main(){

    insert(5);
    insert(4);
    insert(3);
    insert(10);
    print();
    insert_at_nth_position(12 , 1);
    print();
    insert_at_nth_position(14 , 1);
    print();
    
    update_at_nth_position(4 , 1);
    print();
    delete_node(3);
    print();
    
    return 0 ;
}