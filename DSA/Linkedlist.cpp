# include<bits/stdc++.h>
using namespace std ;

class Linkedlist
{
	public :
	class Node
	{
		public :
		Node *next ;
		int data ;
		Node(int d)
		{
			next = NULL ; data = d ;
		}
	};

	Node *head = NULL ;
};


Node *push(Node *head, int key)
{
   Node *node = new Node(key);
   node->next = head ;
   head = node ;
   return head ;
	
}

Node *append(Node *head , int key)
{
   Node *node = new Node(key);
   if(head == NULL) head = node ;
   else
   {
     Node *last = head ;
	 while(last->next != NULL)
		last = last->next ;

		last->next = node;
    }

	 return head ;

}

Node *insertafter(Node *prev, int key)
{
  if(prev == NULL){ cout<<"Previous can not be Null!" ; return head; }
  Node *node  = new Node(key);
  node->next = prev->next ;
  prev->next = node ;
  return head ;

}

Node *printlist(Node *head)
{
   while(head!=NULL)
   {
   	 cout<<head->data<<" ";
   	 head = head->next ;
   }

   	 cout<<endl ;
}


int main()
{
	Linkedlist *l = new Linkedlist();
	l->append(l->head,6);
	l->push(l->head,7);
	l->push(l->head,1);
	l->apped(l->head,4);
	l->insertafter(l->head->next, 8);
	cout<<"Created Linkedlist is :" ;
	printlist(l->head);
}
