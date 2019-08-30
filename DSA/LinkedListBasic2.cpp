# include<bits/stdc++.h>
using namespace std ;
# define ll long long

struct Node
{
   int data ;
   Node next ;
   Node(int d)
   {
   	 data = d ; next = Null ; 
   }
}

Node head = Null ;

void push(int key)
{
  Node node(key) ;
  node.next = head ;
  head = node ;
}

void append( int key)
{
  Node node(key);
  if(head == Null){ head = node ;}
  else
  {
	Node last = head ;
	while(last.next != Null)
		last = last.next ;

	last.next = node;
  }

}

void insertafter(Node prev, int key)
{
  if(prev == Null){ cout<<"Previous can not be Null!"<<endl  ; return ; }
  Node node(key);
  node.next = prev.next ;
  prev.next = node ;
}

void printlist()
{
  Node t = head ;
  while(t!=Null)
  {
   	 cout<<t.data<<" ";
   	 t = t.next ;
  }

   	 cout<<endl ;
}


int main()
{

   for(int i=1;i<=6;i++) append(i);  
   cout<<"Created Linkedlist is : " ;
   printlist();
   //cout<<"The middle element is : "<<middle(head)<<endl ;
   //head = reverse(head);
   //lasttofirst();
   //printlist();

}
