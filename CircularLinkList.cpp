
#include <iostream>

using namespace std;
struct node
{
    int data;
    node *link;
};
 
 class cLL
 {
     node *start;
     
     public:  
      cLL()
      {
          start=NULL;
      }
      
      bool isempty()
    {
        if(start==NULL)
        {
        return true;
        }
        else
        {
        return false;
        }
        
    }
    void display()
    {
        if(isempty())
        {
            cout<<"EMPTY";
            return;
        }
        node *p=start->link;
        do
        {
            cout<<p->data<<"  ";
            p=p->link;
        }while(p!=start->link);
        
    }
    void insert_beg(int value)
    {
        node *p=new node;
        p->data=value;
        p->link=NULL;
        
        if(isempty())
        {
            start=p;
            p->link=p;
            return;
        }
        p->link=start->link;
        start->link=p;
    }
    void insert_end(int value)
    {
         node *p=new node;
        p->data=value;
        p->link=NULL;
        
        if(isempty())
        {
            start=p;
            p->link=p;
            return;
        }
        p->link=start->link;
        start->link=p;
        start=p;
    }
    void insert_pos(int n)
   {
       node *mid=new node;
      
       node *curr=start,*prev=NULL;
       int val;
       cout<<"ENTER THE VALUE TO BE INSERTED AT "<<n<<" POSITION"<<endl;
       cin>>val;
        mid->data=val;
         mid->link=NULL;
       for(int i=1;i<=n;i++)
       {
           prev=curr;
           curr=curr->link;
       }
       
       mid->link=prev->link;
       prev->link=mid;
       
       
   }
   void del_end()
   {
       if(isempty())
       {
           cout<<"EMPTY";
           return;
       }
       if(start->link==start)
       {
           start->link=NULL;
           delete start;
           start=NULL;
           return;
       }
       node *p=start;
       while(p->link!=start)
       {
           p=p->link;
       }
       node *q=p->link;
       p->link=q->link;
       start=p;
       q->link=NULL;
       delete q;
       q=NULL;
       
   }
   void del_beg()
   {
      if(isempty())
       {
           cout<<"EMPTY";
           return;
       }
      if(start->link==start)
       {
           start->link=NULL;
           delete start;
           start=NULL;
           return;
       }
       node *q=start->link;
       start->link=q->link;
       q->link=NULL;
       delete q;
       q=NULL;
   }
 };

int main()
{
    cLL c1;
    c1.insert_beg(10);
    c1.insert_beg(20);
    c1.insert_beg(30);
    c1.insert_end(40);
    c1.insert_end(50);
    c1.insert_end(60);
    c1.display();
     c1.insert_pos(5);
     cout<<endl;
      c1.display();
    c1.del_beg();
    c1.del_end();
     cout<<endl;
      c1.display();
    return 0;
}

