#include <iostream>

using namespace std;
struct node
{
    int data;
    node *link;
};


class linklist
{
   
   node *start;
   
   public:
   linklist()// constructor is created to intialize linked list
   {
       start = NULL;
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
   void insert_beg(int x)
   {
       node *ptr; 
       ptr = new node;
       ptr->data=x;
       ptr->link=NULL;
       if(isempty())
       {
       start =ptr;
       }
       else
       {
           ptr->link=start;
           start=ptr;
       }
   }
    void insert_pos(int n)
   {
       node *mid=new node;
      
       node *curr=start,*prev=NULL;
       int val;
       cout<<"ENTER THE VALUE TO BE INSERTED AT "<<n<<" POSITION";
       cin>>val;
        mid->data=val;
         mid->link=NULL;
       for(int i=1;i<n;i++)
       {
           prev=curr;
           curr=curr->link;
       }
       
       mid->link=prev->link;
       prev->link=mid;
       
       
   }
   void insert_end(int x)
   {
       node *ptr=new node;
       
       if(isempty())
       {
           insert_beg(x);
       }
       else
       {
        node *q=start;
       
         while(q->link!=NULL)
       {
           
           q=q->link;
       }
       q->link=ptr;
       ptr->data=x;
       ptr->link=NULL;
       }
   }
   void delete_beg()
   {
       if(isempty())
       {
           cout<<"ALREADY NULL";
       }
       else
       {
           node *ptr=start;
           start=ptr->link;
           ptr->link=NULL;
           delete ptr;
           ptr=NULL;
        
       }
   }
   
   void delete_end()
   {
       
       if(isempty())
       {
           cout<<"ALREADY NULL";
           return;
       }
       if(start->link==NULL)
       {
           delete start;
           start=NULL;
           return;
       }
       node *q=start;
       while(q->link->link!=NULL)
       
       {
           q=q->link;
       }
       delete (q->link);
       q->link =NULL;
   }
   void display()
   {
        node *ptr;
       ptr = start;
       while(ptr!=NULL)
       {
           cout<<ptr->data<<"  ";
           ptr=ptr->link;
       }
   }
   void dlt_pos()
   {
       if(isempty())
       {
           cout<<"EMPTY LINKED LIST";
           return;
       }
     
       puts("ENTER THE POSITION FROM WHERE YOU WANT TO DELETE THE NODE");
       int n;
       cin>>n;
         if(n==1)
       {
          delete_beg();                                            
    
           return;
       }
      
      node *cur=start,*temp=NULL;
      int i;
      for(i=1;i<n-1;i++)
      {
       
          cur=cur->link;
         
      }
      temp=cur->link;
      cur->link=cur->link->link;
      temp->link=NULL;
      delete temp;
      
   }
   
   
   
} ;
int main()
{
   linklist ll;
   ll.insert_beg(1);
   ll.insert_beg(1);
   ll.insert_beg(1);
   ll.display();
   cout<<endl;
   ll.insert_end(2);
   ll.insert_end(2);
   ll.insert_end(3);
    ll.display();
    cout<<endl;
     
   ll.display();
   
     
      
   
}




