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

Node* delDupsSorted(Node *head)
{
    Node *curr=head;
    while(curr->next)
    {
        if(curr->val==curr->next->val)
        {
            Node *t=curr->next;
            curr->next=curr->next->next;
            delete t;
        }
        else
        curr=curr->next;
    }
    return head;
}

Node* delDupsUnsorted(Node *head)
{
    Node *curr=head,*prev=NULL;
    unordered_set<int> st;
    while(curr)
    {
        if(st.count(curr->val))
        {
            prev->next=curr->next;
            delete curr;
        }
        else
        {
            st.insert(curr->val);
            prev=curr;
        }
        curr=prev->next;
    }
    return head;
}

int main()
{
    Node *h1=NULL;
    h1=insert(1,h1);
    insert(2,h1);
    insert(2,h1);
    insert(2,h1);
    print(h1);
    Node *h2=delDupsSorted(h1);
    print(h2);
    Node *h3=NULL;
    h3=insert(1,h3);
    insert(4,h3);
    insert(1,h3);
    insert(1,h3);
    print(h3);
    Node *h4=delDupsUnsorted(h3);
    print(h4);
}