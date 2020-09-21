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

void leftView(Node *root)
{
    if(!root)
        return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int sz=q.size();
        cout<<q.front()->val<<" ";
        while(sz--)
        {
            Node *curr=q.front();q.pop();
            if(curr->left)
            q.push(curr->left);
            if(curr->right)
            q.push(curr->right);
        }
    }
    cout<<endl;
}

void leftViewHelper(Node *root,int level,int &cnt)
{
    if(!root)
        return;
    if(cnt==level)
    {
        cout<<root->val<<" ";
        cnt++;
    }
    leftViewHelper(root->left,level+1,cnt);
    leftViewHelper(root->right,level+1,cnt);
}

void recursiveLeftView(Node *root)
{
    int cnt=1;
    leftViewHelper(root,1,cnt);
    cout<<endl;
}

void rightView(Node *root)
{
    if(!root)
        return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int sz=q.size();
        while(sz--)
        {
            Node *curr=q.front();q.pop();
            if(sz==0)
            cout<<curr->val<<" ";
            if(curr->left)
            q.push(curr->left);
            if(curr->right)
            q.push(curr->right);
        }
    }
    cout<<endl;
}

void rightViewHelper(Node *root,int level,int &cnt)
{
    if(!root)
        return;
    if(cnt==level)
    {
        cout<<root->val<<" ";
        cnt++;
    }
    rightViewHelper(root->right,level+1,cnt);
    rightViewHelper(root->left,level+1,cnt);
}

void recursiveRightView(Node *root)
{
    int cnt=1;
    rightViewHelper(root,1,cnt);
    cout<<endl;
}

void topView(Node *root)
{
    queue<pair<Node*,int>> q;
    map<int,int> mp;
    q.push({root,0});
    while(!q.empty())
    {
        auto p=q.front();q.pop();
        int hd=p.second;
        Node *curr=p.first;
        if(!mp.count(hd))
            mp[hd]=curr->val;
        if(curr->left)
        q.push({curr->left,hd-1});
        if(curr->right)
        q.push({curr->right,hd+1});
    }
    for(auto x:mp)
    cout<<x.second<<" ";
    cout<<endl;
}

void topViewHelper(Node *root,int hd,int level,map<int,pair<int,int>>& mp)
{
    if(!root)
        return;
    if(!mp.count(hd) or level<mp[hd].second)
        mp[hd]={root->val,level};
    topViewHelper(root->left,hd-1,level+1,mp);
    topViewHelper(root->right,hd+1,level+1,mp);
}

void recursiveTopView(Node *root)
{
    map<int,pair<int,int>> mp;
    topViewHelper(root,0,0,mp);
    for(auto x:mp)
    cout<<x.second.first<<" ";
    cout<<endl;
}

void bottomView(Node *root)
{
    queue<pair<Node*,int>> q;
    map<int,int> mp;
    q.push({root,0});
    while(!q.empty())
    {
        auto p=q.front();q.pop();
        int hd=p.second;
        Node *curr=p.first;
        mp[hd]=curr->val;
        if(curr->left)
        q.push({curr->left,hd-1});
        if(curr->right)
        q.push({curr->right,hd+1});
    }
    for(auto x:mp)
    cout<<x.second<<" ";
    cout<<endl;
}

void bottomViewHelper(Node *root,int hd,int level,map<int,pair<int,int>>& mp)
{
    if(!root)
        return;
    if(!mp.count(hd) or level>=mp[hd].second)
        mp[hd]={root->val,level};
    bottomViewHelper(root->left,hd-1,level+1,mp);
    bottomViewHelper(root->right,hd+1,level+1,mp);
}

void recursiveBottomView(Node *root)
{
    map<int,pair<int,int>> mp;
    bottomViewHelper(root,0,0,mp);
    for(auto x:mp)
    cout<<x.second.first<<" ";
    cout<<endl;
}

int main()
{
    Node *root=NULL;
    root=insert(2,root);
    insert(1,root);
    insert(4,root);
    insert(3,root);
    insert(5,root);
    cout<<"Iterative Left View: ";
    leftView(root);
    cout<<"Recursive Left View: ";
    recursiveLeftView(root);
    cout<<"Iterative Right View: ";
    rightView(root);
    cout<<"Recursive Right View: ";
    recursiveRightView(root);
    cout<<"Iterative Top View: ";
    topView(root);
    cout<<"Recursive Top View: ";
    recursiveTopView(root);
    cout<<"Iterative Bottom View: ";
    bottomView(root);
    cout<<"Recursive Bottom View: ";
    recursiveBottomView(root);
}
