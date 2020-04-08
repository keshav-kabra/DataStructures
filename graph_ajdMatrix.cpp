#include<iostream>
using namespace std;
void add_edge(int v[][5] ,int first_element , int second_element)
{
    v[first_element][second_element] = 1;
    v[second_element][first_element] = 1;

}

int main()
{
    cout<<"working";
    int v[5][5] ,i,j;
    for(int i=0;i<5;i++) for(int j=0;j<5;j++) v[i][j] = 0;
        
    add_edge(v,0,1);
    add_edge(v,0,2);
    add_edge(v,3,1);
    add_edge(v,2,3);
    add_edge(v,2,4);
    add_edge(v,3,4);

    cout<<"adjacency Matrix\n";
    for(int i=0;i<5;i++) 
    {   
        cout<<i <<"-->\t";
        for(int j=0;j<5;j++)
        {
            cout<<v[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"working";
    return 0;

}