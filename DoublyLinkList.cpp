#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node *prev;
    node(int x)
    {
        data =x;
        next=NULL;
        prev=NULL;
    }
};

class doublyLinkList
{
    public:
    node *head;

    node *insertBegin(node *head,int x)
    {
        node *temp=new node(x);
        temp->next=head;
        if(head!=NULL) 
        {
            head->prev=temp;
        }
        return temp;
    }

    node *insertEnd(node *head,int x)
    {
        node *temp=new node(x);
        if(head==NULL) return temp;
        node *curr=head;
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        curr->next=temp;
        temp->prev=curr;
        return head;
    }

    node *delHead(node *head)
    {
        if(head==NULL) return NULL;
        if(head->next==NULL)
        {
            delete head;
            return NULL;
        }
        else
        {
            node *temp=head;
            head=head->next;
            head->prev=NULL;
            delete temp;
            return head;
        }
    }

    node *delEnd(node *head)
    {
    if(head==NULL) return NULL;
    if(head->next==NULL)
    {
         delete head;
            return NULL;
    } 
    else
    {
        node *curr=head;
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        curr->prev->next=NULL;
        delete curr;
        return head;
    }
    }

    node *insertPos(node *head,int pos,int x)
    {
        node *temp=new node(x);
         if(pos==1)
         {
            insertBegin(head,x);
         }
            node *curr=head;
            for(int i=1;i<=pos-2&&curr!=NULL;i++)
            {
                curr=curr->next;
            }
            if(curr==NULL) return head;
            else
            {
                temp->next=curr->next;
                curr->next=temp;
                temp->prev=curr;
                temp->next->prev=temp;
                return head;
            }
        
    }

    void display(node *head)
    {
        node *temp=head;
        if(head==NULL) return;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    node *reverse(node *head)
    {
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        node *prev=NULL;
        node *curr=head;
        while(curr!=NULL)
        {
            prev=curr->prev;
            curr->prev=curr->next;
            curr->next=prev;
            curr=curr->prev;
        }
        return prev->prev;
    }
};

int main(void)
{
    node *head=NULL;
    doublyLinkList d1;
    head=d1.insertBegin(head,20);
    head=d1.insertBegin(head,10);
    head=d1.insertEnd(head,30);
    head=d1.insertEnd(head,40);
    //head=d1.insertPos(head,4,35);
    //head=d1.delHead(head);
    //head=d1.delEnd(head);
    d1.display(head);
    cout<<"REVERSED LIST IS>>";
    head=d1.reverse(head);
    d1.display(head);

}