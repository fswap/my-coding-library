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

int sum=0;
vector<bool> vis(10000,false);
vector<int> path(10000);

void helper(Node *root,int idx,int k)
{
    if(root==NULL)
        return;
    path[idx]=root->val;
    vis[idx]=false;
    idx++;
    if(!root->left and !root->right and idx-k-1>=0 and !vis[idx-k-1])
    {
        sum+=path[idx-k-1];
        vis[idx-k-1]=true;
        return;
    }

    helper(root->left,idx,k);
    helper(root->right,idx,k);
}

void disKLeaf(Node *root,int k)
{
    helper(root,0,k);
}

void solve()
{
    int k;
    cin>>k;
    Node* root=new Node(1); 
    root->left=new Node(2); 
    root->right=new Node(3); 
    root->left->left=new Node(4); 
    root->left->right=new Node(5); 
    root->right->left=new Node(6); 
    root->right->right=new Node(7); 
    root->right->left->right=new Node(8);
    disKLeaf(root,k);
    cout<<sum<<endl;
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

/*

void leafNodeDistance(Node* node, vector<Node*> path,
					unordered_set<Node*> &set, int dist)
{
    // base case: empty tree
    if (node == nullptr)
        return;

    // if a leaf node is found, insert the node at distance 'dist' from
    // leaf node into the set
    if (isLeaf(node) && path.size() >= dist)
    {
        set.insert(path.at(path.size() - dist));
        return;
    }

    // include current node into current path
    path.push_back(node);

    // recur for left and right subtree
    leafNodeDistance(node->left, path, set, dist);
    leafNodeDistance(node->right, path, set, dist);
}

// find all distinct nodes at given distance from leaf nodes
void leafNodeDistance(Node* node, int dist)
{
    // vector to store root to leaf path
    vector<Node*> path;

    // create an empty set to store distinct nodes at given
    // distance from leaf nodes
    unordered_set<Node*> set;

    // find all nodes
    leafNodeDistance(node, path, set, dist);

    // print output
    for (Node* node: set)
        cout << node->data << " ";
}

*/

