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

Node* deleteMid(Node *head)
{
    Node *slow=head,*fast=head,*prev=head;
    while(fast and fast->next)
    {
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    prev->next=slow->next;
    delete slow;
    return head;
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
    Node *h1=deleteMid(head);
    print(h1);
}