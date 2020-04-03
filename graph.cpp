#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};

void read_graph()
{
    int nodes,neighbours,i,j, data;
    cout<<"enter the number of nodes to enter\n";
    cin>>nodes;

    //create array of pointers to nodes
    node* vertex_list[nodes];
    for(i=0;i<nodes;i++) vertex_list[i] = NULL;
    //
    for(i=0;i<nodes;i++)
    {
        cout<<"enter the no of neighbour of node"<<i+1<<"\n";
        cin>>neighbours;
        node *lastnode = NULL;
        for(j=0;j<neighbours;j++)
        {
            //create new node
            cout<<"enter the "<<j+1<<" neighbour of"<<i+1<<"node\n";
            cin>>data;
            node *temp = new node();
            temp->data = data;
            temp->next = NULL;
            if(vertex_list[i] == NULL) vertex_list[i] = temp;
            else lastnode->next = temp;
            lastnode = temp;
            

        }

    }


}
int main()
{
    read_graph();
    cout<<"working";
    return 0;
}



/*
 //2. take the values of nodes of graph
    for(i=0;i<nodes;i++)
    {
        cout<<"enter the value of"<<i+1<<"node\n";
        cin>>value;
        cout<<"commint 1";
        //3.put value in the vertex array and put next value as NULL
        vertex_list[i]->data = value;
        cout<<"comming here";
        vertex_list[i]->next = NULL;
    }
    //4. try to print what you have done
    for(i=0;i<nodes;i++)
    {
        cout<<"value "<<vertex_list[i]->data<<"\t";
        if(vertex_list[i]->next == NULL)
        {
            cout<<"yes next is NULL\n";
        }
    }
 */