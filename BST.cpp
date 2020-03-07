//program for implementing binary search tree
//all functions without recursion

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

struct BstNode
{
    int data;
    BstNode *left;
    BstNode *right;
};
BstNode *Root = NULL;
void insert(int data);
void BFS_traversal();
void DFS_traversal_preorder();
int hieght();
//void DFS_traversal_inorder();
//void DFS_traversal_postorder();
bool search(int data);
int maximum_number();
int minimum_number();
BstNode* GetNewNode(int data);

BstNode* GetNewNode(int data)
{
    BstNode* NewNode = new BstNode();
    NewNode->data = data;
    NewNode->left = NewNode->right = NULL;
    return NewNode;
}
void insert(int data)
{
    BstNode* NewNode = GetNewNode(data);   
    if(Root == NULL) Root = NewNode;
    else
    {
        BstNode *temp1Root = NULL;
        BstNode *temp2Root = Root;
        while(temp2Root  != NULL)
        {
            temp1Root = temp2Root;
            if(data<= temp2Root->data) temp2Root = temp2Root->left;
            else if(data > temp2Root->data) 
            {
                temp2Root= temp2Root->right;
            }
        }
        if(data<= temp1Root->data) temp1Root->left = NewNode;
        else 
        {
            temp1Root->right = NewNode; 
        }

    }
    return;
    
}
bool search(int data)
{
    BstNode *tempRoot  = Root;
    if(Root == NULL) return false;
    else
    {
        BstNode* tempRoot = Root;
        while(true)
        {
            if(tempRoot->data == data) return true;
            // if(tempRoot == NULL) 
            // {
            //     cout<<"comming to false";
            //     return false;
            // }
            else if(data<= tempRoot->data) 
            {
                tempRoot = tempRoot->left;
                
                if(tempRoot == NULL) return false;

            }

            else 
            {
                tempRoot = tempRoot->right;
                if(tempRoot == NULL) return false;
            }
        }
    

    }
    
}
int maximum_number()
{
    BstNode *tempRoot = Root, *tempRoot_value = NULL;
    while(tempRoot!=NULL)
    {
        tempRoot_value = tempRoot;
        tempRoot = tempRoot->right;
    }

    return tempRoot_value->data;
}
int minimum_number()
{
    BstNode *tempRoot = Root, *tempRoot_value = NULL;
    while(tempRoot!=NULL)
    {
        tempRoot_value = tempRoot;
        tempRoot = tempRoot->left;
    }

    return tempRoot_value->data;
}

void BFS_traversal()
{
    //check if root is empty or not
    if(Root == NULL) return;
    //first we need to create a queue
    queue<BstNode*> q;
    BstNode* tempRoot = NULL;
    q.push(Root);
    while(!q.empty())
    {
        tempRoot = q.front();
        cout<<tempRoot->data<<"\t";
        if(tempRoot->left!=NULL) q.push(tempRoot->left);
        if(tempRoot->right!=NULL) q.push(tempRoot->right);
        q.pop();
    }
    return ; 

}

void DFS_traversal_preorder()
{
    BstNode *tempRoot = Root, *temp1Root = NULL;
    stack<BstNode*> s;
    tempRoot  = Root;
    // while(tempRoot!=NULL)
    // {
    //     cout<<tempRoot->data<<"\t";
    //     if(tempRoot->right!=NULL) s.push(tempRoot->right);
    //     tempRoot = tempRoot->left;

    // }
    s.push(Root);
    while(!s.empty())
    {
        tempRoot = s.top();
        cout<<tempRoot->data<<"\t";
        temp1Root = tempRoot;
        s.pop();
        if(temp1Root->right!=NULL) s.push(temp1Root->right);
        if(temp1Root->left!=NULL) s.push(temp1Root->left);
        
    }
    
    return ;
}
int main()
{
    //call functions here
    insert(15);
    insert(10);
    insert(12);
    insert(7);
    insert(20);
    insert(500);
    insert(18);
    if(search(20) == true) cout<<"value found\n";
    else cout<<"value not found\n";
    int maximum_value = maximum_number();
    int minimum_value = minimum_number();
    cout<<"Maximum value is "<<maximum_value<<"\tand minimum value is "<<minimum_value<<"\n";
    
    DFS_traversal_preorder();

    return 0;
}