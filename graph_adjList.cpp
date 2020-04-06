#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
struct node{
    int data;
    node* next;
};
int nodes,neighbours,i ,j,data;
void print_graph_dfs(node* vertex_list[] , int element)
{
    //1.initialize a stack
    stack<int> vertex_stack;
    bool visited_node[nodes];
    for(i=0;i<nodes;i++) visited_node[i] = false;
    //2. put any one vertice in the stack
    vertex_stack.push(element);
    visited_node[element] = true;
    //3.while stack is not empty
    cout<<"\nvertices:\t";
    while(!vertex_stack.empty())
    {  

        //1.take out element form stack and push its neighbour to stack if not visisted
        int poped_element = vertex_stack.top();
        cout<<poped_element<<"\t";
        vertex_stack.pop();
        node* temp = vertex_list[poped_element];
        //2.reaeat step 1 till all the neightbour of a vertice are visisted
        while(temp != NULL)
        {
            //check if visited
            if(visited_node[temp->data] == false)
            {
                vertex_stack.push(temp->data);
                visited_node[temp->data] = true;
                
            }
            temp = temp->next;
        }
        //3.print the vertices
    }
}
void print_graph_bfs(node *vertex_list[])

{
    
    int i= 0,front_node, k=0, flag =0 ;
    // node* temp = vertex_list[k];
    queue<int> visited;  
    queue<int> queue;
    bool visited_node[nodes];
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
    print_graph_bfs(vertex_list);
    print_graph_dfs(vertex_list, 0);
    cout<<"working";
    return 0;
}

