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

void postorder(Node *root)
{
    if(!root)
        return;
    inorder(root->left);
    inorder(root->right);
    cout<<root->val<<" ";
}

Node* construct(int l,int h,int &pindx,int *pre,int *in)
{
    if(l>h)
        return NULL;
    int idx,curr=pre[pindx++];
    for(int i=l;i<=h;i++)
        if(in[i]==curr)
        {
            idx=i;
            break;
        }
    
    Node *root=new Node(curr);
    root->left=construct(l,idx-1,pindx,pre,in);
    root->right=construct(idx+1,h,pindx,pre,in);
    return root;
}

Node* buildTree(int in[],int pre[], int n)
{
    int pindx=0;
    return construct(0,n-1,pindx,pre,in);
}

int main()
{
    int i,n;
    cin>>n;
    int pre[n],in[n];
    for(i=0;i<n;i++)
        cin>>in[i];
    for(i=0;i<n;i++)
        cin>>pre[i];
    int pindx=0;
    Node *root=NULL;
    root=buildTree(in,pre,n);
    inorder(root); cout<<endl;
    preorder(root); cout<<endl;
    postorder(root); cout<<endl;
}