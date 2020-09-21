#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int x)
    {
        this->val=x;
        this->next=NULL;
    }
};

Node* insert(int x,Node *head)
{
    if(head==NULL)
        head=new Node(x);
    else
    {
        Node *curr=head;
        while(curr->next)
        curr=curr->next;
        curr->next=new Node(x);
    }
    return head;
}

void print(Node *head)
{
    Node *curr=head;
    while(curr)
    {
        cout<<curr->val<<" ";
        curr=curr->next;
    }
    cout<<endl;
}

bool isPalin(auto &l,auto r)
{
    if(r==NULL)
        return true;
    bool f1=isPalin(l,r->next);
    if(!f1)
        return false;
    bool f2=(r->val==l->val);
    l=l->next;
    return f2;
}

int main()
{
    Node *head=NULL;
    head=insert(1,head);
    insert(2,head);
    insert(2,head);
    insert(1,head);
    print(head);
    cout<<isPalin(head,head)<<endl;
}