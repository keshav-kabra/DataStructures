#include<iostream>
using namespace std;
struct node 
{
    int data;
    node* next;
};
node* head;
//function declarations

int insert_at_end(int value);
int insert_at_begining(int value);
int insert_at_Nth_position(int value , int position);
int delete_at_Nth_position(int position);
int update_at_Nth_position(int position , int value);
int reverse();
int reverse_recursively();
int print_recursively(node* head);
int print();

int insert_at_begining(int value)
{
    node* temp = new node();
    temp->data = value;
    temp->next = head;
    head = temp;
    return 0;
}
int insert_at_end(int value)
{
    node* temp1 =  head;
    node* temp = new node();
    temp->data = value;
    temp->next = NULL;
    while(temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = temp;
    return 0;
}
int insert_at_Nth_position(int value , int position)
{
    node* temp1 = head;
    //check if list is empty
    if(position == 1)
    {
        insert_at_begining(value);
        return 0;
    }
    //  else to till end node
    node* temp = new node();
    temp->data = value;
    temp->next = NULL;
    for(int i=0;i<position-2;i++)
    {
        temp1 = temp1->next;
        
    }

    temp->next = temp1->next;
    temp1->next = temp;
    return 0;
}
int delete_at_Nth_position(int position)
{
    node* temp1 = head;
    node* temp2 = head;
    
        for(int i=0; i <position-2;i++)
        {
            temp1 = temp1->next;
        }
        for(int i=0;i<position;i++)
        {
            temp2 = temp2->next;
        }
        temp1->next = temp2; 



    return 0;
}
int update_at_Nth_position(int position , int value)
{
    node* temp = head;
    for(int i=0;i<position-1;i++)
    {
        temp = temp->next;
    }
    temp->data = value;
    return 0;

}
int reverse()
{
    node *temp= head, *current ,*back =NULL , *next_node;
    while(temp!= NULL)
    {

        next_node= temp->next;
        temp->next = back;
        back = temp;
        if(next_node == NULL) 
        {
            head = temp;
            break;
        }
        temp = next_node;

    }


    return 0;
}
int reverse_recursively(node* head)
{
    
    if(head == NULL) return 0;
    
    reverse_recursively(head->next);
    cout<<head->data<<"\t";
    return 0;
}

int print_recursively(node* head)
{
    
    if (head == NULL) return 0;
    cout<<head->data<<"\t";
    print_recursively(head->next);
    return 0;
}


int print()
{
    node* temp = head;
    cout<<"\nLIST : ";
    while(temp != NULL)
    {
        cout<<temp->data<<"\t";
        temp = temp->next;
    }
    return 0;
}
int main()
{
    head = NULL;
    insert_at_begining(2);
    print();
    insert_at_begining(4);
    print();
    insert_at_begining(6);
    print();
    insert_at_begining(8);
    print();
    insert_at_end(10);
    print();
    insert_at_Nth_position(12 , 2);
    print();
    delete_at_Nth_position(1);
    print();
    delete_at_Nth_position(3);
    print();
    update_at_Nth_position(1 , 14);
    print();
    reverse();
    print();
    reverse();
    print();
    cout<<"\nLIST : ";
    print_recursively(head);
    cout<<"\nLIST : ";
    reverse_recursively(head);
    print();

}
