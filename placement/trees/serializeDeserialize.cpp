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

void preorder(Node* root)
{
    if(!root)
        return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

void serialize(Node *root, vector<int> &a)
{
    if(root==NULL)
    {
        a.push_back(-1);
        return;
    }
    a.push_back(root->val);
    serialize(root->left,a);
    serialize(root->right,a);
}

Node* helper(vector<int> a,int &idx)
{
    if(idx==a.size()-1 or a[idx]==-1)
    {
        idx++;
        return NULL;
    }
    Node *root=new Node(a[idx++]);
    root->left=helper(a,idx);
    root->right=helper(a,idx);
    return root;
}

Node* deserialize(vector<int> a)
{
    int idx=0;
    return helper(a,idx);
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
    preorder(root);cout<<endl;
    vector<int> a;
    serialize(root,a);
    for(auto x:a)
        cout<<x<<" ";
    cout<<endl;
    Node *r1=deserialize(a);
    inorder(r1);cout<<endl;
}