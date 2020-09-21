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

Node* reverseLL(Node *head)
{
    Node *p=NULL,*curr=head,*n=NULL;
    while(curr)
    {
        n=curr->next;
        curr->next=p;
        p=curr;
        curr=n;
    }
    return p;
}

Node* reverse(Node *head)
{
    if(head->next==NULL)
        return head;
    Node *newhead=reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}

int main()
{
    Node *head=NULL;
    head=insert(1,head);
    insert(2,head);
    insert(3,head);
    print(head);
    insert(4,head);
    print(head);
    Node *h1=reverseLL(head);
    print(h1);
    Node *h2=reverse(h1);
    print(h2);
}