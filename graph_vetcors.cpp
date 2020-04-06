//in this program we have used the properties of  vecotors in c++ to implement graphs
#include<iostream>
#include<vector>
using namespace std;
void add_edge(vector<int> vertices[] , int u , int v)
{
    vertices[u].push_back(v);
    vertices[v].push_back(u);
}
void print_graph(vector<int> vertices[] , int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<i<<"- - >\t";
        for(int j=0;j<vertices[i].size();j++)
        {
            cout<<vertices[i][j]<<"\t";
        }
        cout<<endl;
    }
}



int main()
{
    int total_verteices;
    vector<int> vertices[5];
    
    // cout<<"enter the number of vertices";
    // cin>>total_vertices;

       //call function read graph
    add_edge(vertices, 0,1);
    add_edge(vertices, 0,2);
    add_edge(vertices, 3,1);
    add_edge(vertices, 2,3);
    add_edge(vertices, 2,4);
    add_edge(vertices, 3,4);
    print_graph(vertices, 5);
    cout<<"working";
    return 0;
}   