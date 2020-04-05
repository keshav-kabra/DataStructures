#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct node{
    int data;
    node* next;
};
int nodes,neighbours,i ,j,data;
void print_graph(node *vertex_list[])

{
    
    int i= 0,front_node, k=0, flag =0 ;
    // node* temp = vertex_list[k];
    queue<int> visited;  
    queue<int> queue;
    bool visited_node[10];
    for(i=0;i<nodes;i++) visited_node[i] == false;
    queue.push(0);
    visited_node[0] = true;
    while(!queue.empty())
    {
        // node *temp = vertex_list[k++];
        node* temp = vertex_list[queue.front()];
        front_node = queue.front();queue.pop();
        visited.push(front_node);
        while(temp != NULL)
        {
            if(visited_node[temp->data] == false) 
            {
                queue.push(temp->data);
                visited_node[temp->data] = true;
                
            }
            
            
            temp = temp->next;
        }
        //dequeue the list and put vertice in visited list
        

            

        //push all the vertices in queue 
    }
    cout<<"vertices :\t";
    while(!visited.empty())
    {
        cout<<visited.front()<<"\t";
        visited.pop();
    }


}

void read_graph(node* vertex_list[])
{

    //create array of pointers to nodes
    //
    for(i=0;i<nodes;i++)
    {
        cout<<"enter the no of neighbour of node"<<i<<"\n";
        cin>>neighbours;
        node *lastnode = NULL;
        for(j=0;j<neighbours;j++)
        {
            //create new node
            cout<<"enter the "<<j+1<<" neighbour of"<<i<<"node\n";
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
    
    cout<<"enter the number of nodes to enter\n";
    cin>>nodes;
    node* vertex_list[nodes];
    for(i=0;i<nodes;i++) vertex_list[i] = NULL;


    
    read_graph(vertex_list);
    // for(i=0;i<nodes;i++) cout<<vertex_list[i]->data<<"\t";
    print_graph(vertex_list);
    cout<<"working";
    return 0;
}

