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

void convert(Node *root,auto &prev,auto &head)
{
    if(!root)
        return;
    convert(root->left,prev,head);
    if(!prev)
        head=root;
    else
    {
        root->left=prev;
        prev->right=root;
    }
    prev=root;
    convert(root->right,prev,head);
}

int main()
{
    Node *root=NULL;
    root=insert(2,root);
    insert(1,root);
    insert(4,root);
    insert(3,root);
    insert(5,root);
    inorder(root);cout<<endl;
    Node *prev=NULL,*head=NULL;
    convert(root,prev,head);
    Node *curr=head;
    while(curr)
    {
        cout<<curr->val<<" ";
        curr=curr->right;
    }
    cout<<endl;
}