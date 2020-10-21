#include <bits/stdc++.h>
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

bool isIdentical(Node *r1,Node *r2)
{
    if(!r1 and !r2)
        return true;
    if(!r1 or !r2)
        return false;
    return (r1->val==r2->val and isIdentical(r1->left,r2->left) and isIdentical(r1->right,r2->right));
}

bool isSubtree(Node *r1,Node *r2)
{
    if(r2==NULL)
        return true;
    if(r1==NULL)
        return false;
    if(isIdentical(r1,r2))
        return true;
    return (isSubtree(r1->left,r2) or isSubtree(r1->right,r2));
}

int countNodes(Node *root)
{
    if(!root)
        return 0;
    return 1+countNodes(root->left)+countNodes(root->right);
}

int helper(Node *r1,Node*r2)
{
    if(!r1 or !r2)
    return -1;
    else if(isSubtree(r1,r2))
    {
        cout<<"YES"<<endl;
        return countNodes(r2);
    }
    else
    {
        cout<<"NO"<<endl;
        return 0;
    }
}

void solve()
{
    Node *T = new Node(26);  
    T->right         = new Node(3);  
    T->right->right = new Node(3);  
    T->left         = new Node(10);  
    T->left->left     = new Node(4);  
    T->left->left->right = new Node(30);  
    T->left->right     = new Node(6);  
    Node *S = new Node(10);  
    S->right     = new Node(6);  
    S->left     = new Node(4);  
    S->left->right = new Node(30);  
    cout<<helper(T,S)<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    t=1;
    //cin>>t;
    while(t--)
        solve();
}