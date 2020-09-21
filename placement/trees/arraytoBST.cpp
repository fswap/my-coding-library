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

void preorder(Node* root)
{
    if(!root)
        return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root)
{
    if(!root)
        return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

Node* arraytoBST(int a[],int l,int h)
{
    if(l>h)
        return NULL;
    int m=(l+h)>>1;
    Node *root=new Node(a[m]);
    root->left=arraytoBST(a,l,m-1);
    root->right=arraytoBST(a,m+1,h);
    return root;
}

int main()
{
    int i,n;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    Node *root=NULL;
    root=arraytoBST(a,0,n-1);
    inorder(root);cout<<endl;
    preorder(root);cout<<endl;
}