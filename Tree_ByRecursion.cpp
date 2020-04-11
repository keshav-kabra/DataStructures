// imlplementation of all function of tree through recursion
//1.implement tree by recursion i.e insert method
//-- search an element in the tree
//2.bfs traversa of tree
//3.dfs traversal of tree
#include<iostream>
#include<queue>
using namespace std;
struct TreeNode
{
    int Data;
    TreeNode* Right;
    TreeNode* Left;
};

//declaration
TreeNode* Insert(int Data  , TreeNode* TempNode);
TreeNode* NewNode(int Data );
void BFS_traversal(TreeNode* TempRoot);
bool serach(int Data , TreeNode* TempNode);
// definition
TreeNode* NewNode(int Data)
{
    TreeNode* newnode = new TreeNode();
    newnode->Data = Data;
    newnode->Right = newnode->Left = NULL;
    return newnode;
}
TreeNode* Insert(int Data, TreeNode* TempRoot)
{
    //1.create a new node
    
    
    if(TempRoot == NULL)
    {
        TreeNode* TempNode = new TreeNode;
        TempNode->Data = Data;
        TempNode->Left = TempNode->Right = NULL;
        TempRoot = TempNode;
    }
    else if(Data<TempRoot->Data)
    { 
        TempRoot->Left = Insert(Data , TempRoot->Left);
        cout<<"function called\n";
    }
    else if(Data>TempRoot->Data)
    {
        TempRoot->Right = Insert(Data , TempRoot->Right);
        cout<<"this function called\n";
       
         
    }
    return TempRoot;
}
bool Search(int Data , TreeNode* TempRoot)
{
    bool ReturnedValue = false;
    if(TempRoot == NULL) return false;
    if(TempRoot->Data == Data) return true;
    else if(Data<TempRoot->Data)  ReturnedValue =  Search(Data , TempRoot->Left);
    else if(Data>TempRoot->Data)  ReturnedValue =  Search(Data , TempRoot->Right);
    return ReturnedValue;
}
void BFS_traversal(TreeNode* TempRoot)
{
    //conventially not posiible 
    //will try to implement later

}

int main()
{
    TreeNode* Root = NULL;
    cout<<"working";
    Root = Insert(15,Root);
    cout<<Root<<"\t";

    Insert(10,Root);
    cout<<Root->Left;
    Insert(20,Root);
    Insert(7,Root);
    Insert(18,Root);
    Insert(500,Root);
    // check if tree is correct
    // TreeNode* TempRoot = Root;
    // while(TempRoot!= NULL)
    // {
    //     cout<<TempRoot->Data<<"\t";
    //     TempRoot = TempRoot->Right;
    // } 
   
   //check the value is present in the tree
   if(Search(500, Root) == true) cout<<"\nvalue is present in the tree";
   else cout<<"\ncant find value";  

    return 0;
}