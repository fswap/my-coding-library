#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left,*right;
    Node(int x)
    {
        this->val=x;
        this->left=this->right=NULL;
    }
};

Node* insert(int x,Node *root)
{
    if(!root)
        return new Node(x);
    if(x<root->val)
        root->left=insert(x,root->left);
    else
        root->right=insert(x,root->right);
    return root;
}

void inorder(Node* root)
{
    if(!root)
        return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

bool identicalTrees(Node *r1,Node *r2)
{
    if(!r1 and !r2)
        return true;
    if(!r1 or !r2)
        return false;
    if(r1->val!=r2->val)
        return false;
    return (identicalTrees(r1->left,r2->left) and identicalTrees(r1->right,r2->right));
}

int main()
{
    Node *r1=NULL,*r2=NULL;
    r1=insert(2,r1);
    insert(1,r1);
    insert(4,r1);
    insert(3,r1);
    insert(5,r1);
    inorder(r1);cout<<endl;
    r2=insert(2,r2);
    insert(1,r2);
    insert(4,r2);
    insert(3,r2);
    insert(5,r2);
    inorder(r2);cout<<endl;
    if(identicalTrees(r1,r2))
    cout<<"Identical"<<endl;
    else
    cout<<"Not Identical"<<endl;
}