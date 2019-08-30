# include<bits/stdc++.h>
using namespace std ;

struct Node
{
	int data ;
	struct Node* next ;
} ;

void push(struct Node **head , int d)
{
	struct Node* n = (struct Node*)malloc(sizeof(struct Node)) ;
	n->data = d ;
	n->next = *head ;
	*head = n ;
}

void insertafter(struct Node* prev, int d)
{
	if(prev == NULL)
	{
		cout<<"The given previous node can not be null"<<endl ;
		return  ;
	}

	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = d ;
	n->next = prev->next ;
	prev->next = n ;
}

void append(struct Node** head, int d)
{
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = d ;
	if(*head == NULL) 
	{
		*head = n ;
		n->next = NULL ;
		return  ; 
	}

	struct Node* last = *head ;
	while(last->next != NULL)
		last = last->next ;

	last->next = n ;
	n->next = NULL ;
}

void printlist(struct Node* node)
{
  while(node!=NULL)
  {
  	cout<<node->data<<" " ;
  	node = node->next ;
  }

  cout<<endl ;
}

int main()
{
	struct Node* head = NULL ;
	append(&head,6);
    push(&head,7);
	push(&head,1);
	append(&head,4);
	insertafter(head->next,8);
	insertafter(NULL,10);

	cout<<"Created Linkedlist is :" ;
	printlist(head);
}



