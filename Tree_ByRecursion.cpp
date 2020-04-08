// imlplementation of all function of tree through recursion
//1.implement tree by recursion
#include<iostream>
using namespace std;
struct TreeNode
{
    int data;
    TreeNode* Right;
    TreeNode* Left;
};

//declaration
TreeNode* insert(int data  , TreeNode* TempNode);
TreeNode* NewNode(int data );
// definition
TreeNode* NewNode(int data)
{
    TreeNode* newnode = new TreeNode();
    newnode->data = data;
    newnode->Right = newnode->Left = NULL;
    return newnode;
}
TreeNode* insert(int data, TreeNode* TempRoot)
{
    //1.create a new node
    TreeNode* TempNode = new TreeNode;
    TempNode->data = data;
    TempNode->Left = TempNode->Right = NULL;
    if(TempRoot == NULL) TempRoot = TempNode;
    else if(data<TempRoot->data)
    { 
        insert(data , TempRoot->Left);
        cout<<"function called\n";
    }
    else if(data>TempRoot->data)
    {
        insert(data , TempRoot->Right);
        cout<<"this function called\n";
       
         
    }
    return TempRoot;
}

int main()
{
    TreeNode* Root = NULL;
    cout<<"working";
    Root = insert(15,Root);
    insert(10,Root);
    insert(20,Root);
    insert(7,Root);

    return 0;
}