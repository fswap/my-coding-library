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

void postorder(Node* root)
{
    if(!root)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}

void levelorder(Node* root)
{
    if(!root)
        return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* curr=q.front();q.pop();
        cout<<curr->val<<" ";
        if(curr->left)
        q.push(curr->left);
        if(curr->right)
        q.push(curr->right);
    }
}

int main()
{
    Node *root=NULL;
    root=insert(45,root);
    insert(36,root);
    insert(76,root);
    insert(23,root);
    insert(89,root);
    insert(115,root);
    insert(98,root);
    insert(39,root);
    insert(41,root);
    insert(56,root);
    insert(69,root);
    insert(48,root);
    inorder(root);cout<<endl;
    preorder(root);cout<<endl;
    postorder(root);cout<<endl;
}