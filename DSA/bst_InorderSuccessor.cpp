# include<bits/stdc++.h>
using namespace std ;

struct Node
{
	Node *right, *left ;
	int data ;
	Node *parent ;
	Node(int d)
	{
		right = left = parent = NULL ;
		data = d ; 
	}
};


Node* minvalue(Node *root)
{
	if(root == NULL) return root ;
	while(root->left!=NULL)
	{
		root = root->left ;
	}

	return root ;
}

Node *inordersucc(Node *root, Node *n)
{
	if(root == NULL) return root ;
	if(n->right!=NULL) return minvalue(n->right);
	else
	{
		Node *p = n->parent ;
		while(p!=NULL && n == p->right)
		{
			n = p ;
			p = p->parent ;
		}

		return p ;
	}

}

Node *insucc(Node *root, Node *n)
{
	Node * succ ;
	if(root == NULL ) return root ;
	while(root!=NULL)
	{
      if(root->data > n->data)
      {
      	 succ = root ;
      	 root = root->left ;
      }

      else if(root->data < n->data)
      {
      	root = root->right ;
      }

      else break ;
	}

	return succ ;
}

Node *insert(Node *root, int key)
{
	Node *n = new Node(key) ;
	if(root == NULL) return n ;
	Node * temp ;
	if(root->data > key)
	{
		temp = insert(root->left, key);
		root->left = temp ;
		temp->parent = root ;
	}

	else if(root->data < key)
	{
		temp = insert(root->right, key);
		root->right = temp ;
		temp->parent = root ;
	}

	return root ;
}


int main()
{
	Node * root = NULL, *temp, *succ, *min ;
	root = insert(root, 20) ;
	root = insert(root, 8) ;
	root = insert(root, 22) ;
	root = insert(root, 4) ;
	root = insert(root, 12) ;
	root = insert(root, 10) ;
	root = insert(root, 14) ;
	temp = root->left->right->right ;

	succ = inordersucc(root, temp) ;
	if(succ != NULL) cout<<"inorder successor of "<<temp->data<<" is "<<succ->data<<endl ;
	else cout<<"inorder successor does not exist"<<endl ;



}