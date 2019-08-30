# include<bits/stdc++.h>
using namespace std ;

struct Node
{
	int data ;
	Node *next ;
	Node(int d){ data = d ; next = NULL ;}
};

struct Node *head = NULL ;

bool compare(Node* head1, Node* head2)
{
  Node* tmp1 = head1 ;
  Node* tmp2 = head2 ;
  while(tmp1!=NULL && tmp2!=NULL)
  {
  	if(tmp1->data != tmp2->data) return 0;
  }

  return 1 ;
}

/*bool palindrome(Node* head)
{
  bool res = 1 ;
  Node *fast = head, *slow = head ;
	while(fast!=NULL && fast->next!=NULL)
	{
		slow = slow->next ;
		fast = fast->next->next ;
	}

	Node *mid = NULL ;
	if(fast!=NULL)
	  mid = slow , slow = slow->next, mid.next = NULL ;

	Node *head2 = rev(slow);

	res = compare(head,slow);

	head2 = rev(slow);

	if(mid!=NULL)
	  append(mid) , append(head2);

	else append(head2);

    return res ;
		

}*/

void lasttofirst()
{
	Node* last = head ;
	while(last->next->next!=NULL)
	{
		last = last->next ;
	}

	Node* tmp = last->next ;
	last->next = NULL ;
	tmp->next = head ;
	head = tmp ;
}

Node* rev(Node* head)
{
	if(head->next == NULL || head == NULL) return head ;
	Node *t = rev(head->next);
	head->next->next = head ;
	head->next = NULL ;
	return t ;
}

Node* middle(Node *head1)
{
	Node *fast = head1, *slow = head1 ;
	while(fast!=NULL && fast->next!=NULL)
	{
		slow = slow->next ;
		fast = fast->next->next ;
	}

	return slow ;
}

void push(int key)
{
  Node *node = new Node(key);
  node->next = head ;
  head = node ;
}

void append( int key)
{
  Node *node = new Node(key);
  if(head == NULL){ head = node ;}
  else
  {
	Node *last = head ;
	while(last->next != NULL)
		last = last->next ;

	last->next = node;
  }

}

void insertafter(Node *prev, int key)
{
  if(prev == NULL){ cout<<"Previous can not be Null!"<<endl  ; return ; }
  Node *node  = new Node(key);
  node->next = prev->next ;
  prev->next = node ;
}

void printlist()
{
  Node *t = head ;
  while(t!=NULL)
  {
   	 cout<<t->data<<" ";
   	 t = t->next ;
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
   lasttofirst();
   printlist();

}
