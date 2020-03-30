//program for implementing binary search tree
//all functions without recursion

#include<iostream>
#include<queue>
#include<stack>
#include<cstring>
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
void DFS_traversal_inorder();
 void DFS_traversal_postorder();
void DFS_traversal_postorder_multipleStack();
bool search(int data);
int maximum_number();
int minimum_number();
bool IsBST();
void delete_node(int value);
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
void DFS_traversal_inorder()
{
    cout<<"\n";
    stack<BstNode*> s;
    BstNode* tempRoot = Root;
    // s.push(tempRoot);
    while(true)
    {
        while(tempRoot!=NULL)
        {
            s.push(tempRoot);
            tempRoot = tempRoot->left;
        }
        if(s.empty()) return;
        tempRoot = s.top();s.pop();
        cout<<tempRoot->data<<"\t";
        tempRoot = tempRoot->right;
    }
    return;
}
void DFS_traversal_postorder()
{
    stack<BstNode*> s;
    BstNode* current = Root;
    BstNode* previous = NULL;
    s.push(Root);
    while(!s.empty())
    {
        current = s.top();
        if(previous == NULL || previous->right == current)
        {
            while(current->left!=NULL)
            {
                current = current->left;
                s.push(current);
            }
            current = s.top();s.pop();
            cout<<current->data<<"\t";
            
        }
        else if(current->left == previous)
        {
            if(current->right!=NULL)
            {
                s.push(current->right); 
            }
            else 
            {
                cout<<current->data<<"\t";
                s.pop();
            }
            
        }
        else if(current->right == previous)
        {
            cout<<current->data<<"\t";
            s.pop();
            
        }
        previous = current;
    }
    return;
}

void DFS_traversal_postorder_multipleStack()
{
    cout<<"\n";
    stack<BstNode*> s1;
    stack<BstNode*> s2;
    BstNode *tempRoot;
    s1.push(Root);
    while(!s1.empty())
    {
        tempRoot = s1.top();s1.pop();
        s2.push(tempRoot);
        if(tempRoot->left!=NULL) s1.push(tempRoot->left);
        if(tempRoot->right!=NULL) s1.push(tempRoot->right);
    }
    while(!s2.empty())
    {
        tempRoot = s2.top();s2.pop();
        cout<<tempRoot->data<<"\t";
    }

    return;
}
bool IsBST()
{
    //1.  do inorder traversal  
    int result[100],i=0;
    stack<BstNode*> s;
    
    
    BstNode* tempRoot = Root;
    while(true)
    {
        while(tempRoot!=NULL)
        {
            s.push(tempRoot);
            tempRoot = tempRoot->left;
        }
        if(s.empty()) break ;
        tempRoot = s.top();s.pop();
        // cout<<tempRoot->data<<"\t"; 
        result[i++] = tempRoot->data;
        tempRoot = tempRoot->right;
        
        
    }
    int size = sizeof(result)/sizeof(result[0]);
    //2.store result in an array or stack
    for(i=0;i<size;i++)
    {
        if(result[i]>result[i+1]) return true;
        else false;
    }
    //3.if arr is sorted then it is a binary tree  else not 
    return true;
    

}

void delete_node(int data)
{
    string relation = ""; 
    //1.go till the value in the tree
    BstNode *tempRoot = Root;
    BstNode *previous_node = NULL;
    while(tempRoot->data != data)
    {
        previous_node = tempRoot;
        if(data<=tempRoot->data) 
        {
            tempRoot = tempRoot->left;
            relation = "left";
        }
        else 
        {
            tempRoot = tempRoot-> right;
            relation = "right";
        }
    }
    cout<<"\nprevious_node "<<previous_node->data;

    cout<<"\nnode to be deleted "<<tempRoot->data;
    //2.check the which case fits with the node  i.e node has one two or null child
     // case 1
    if (tempRoot->left == NULL && tempRoot->right == NULL) // case 1
    {
        if(previous_node->left == tempRoot) previous_node->left = NULL;
        else previous_node->right = NULL;
    }
    //case 2 if only one child
    else if (tempRoot->right == NULL || tempRoot->left == NULL)
    {
        if(tempRoot->right == NULL) 
        {
            if(relation == "left") previous_node->left = tempRoot->left;
            else previous_node->right = tempRoot->left;
        }
        else
        {
            if(relation == "left") previous_node->left = tempRoot->right;
            else previous_node->right = tempRoot->right;
        }


    }
    //case 3 
    else
    {
        BstNode* replacing_node = tempRoot->left;
        previous_node = tempRoot;
        
        
        //find largest in left sub tree
        while(replacing_node->right != NULL)
        {
            previous_node = replacing_node;
            replacing_node = replacing_node ->right;
        }
        tempRoot->data = replacing_node->data;
        //now we have to delete replacing node
        if(replacing_node->left == NULL)
        {
            //apply case 1
            if(previous_node->left == tempRoot) previous_node->left = NULL;
            else previous_node->right = NULL;
        }
        else
        {
            //apply case 2
            previous_node->left = replacing_node->left;

        }
        

    }
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
    insert(5);
    insert(11);
    insert(17);

    if(search(20) == true) cout<<"value found\n";
    else cout<<"value not found\n";
    int maximum_value = maximum_number();
    int minimum_value = minimum_number();
    cout<<"Maximum value is "<<maximum_value<<"\tand minimum value is "<<minimum_value<<"\n";
    
    DFS_traversal_preorder();
    DFS_traversal_inorder();
    cout<<"\n";
    DFS_traversal_postorder();
    cout<<"\nfor bool function \n";
    if(IsBST()== true) cout<<"\nthe tree is binary tree";
    DFS_traversal_postorder_multipleStack();
    delete_node(10);
    
    DFS_traversal_inorder();

    return 0;
}