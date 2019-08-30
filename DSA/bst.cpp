# include<bits/stdc++.h>
using namespace std ;

struct Node
{
	int data  ;
	Node *left,*right ;
	Node(int d)
	{
		left = right = NULL ;
		data = d ;
	}
};

/*deletion in a tree*/

void inorder(Node *root)
{
	if(root == NULL) return  ;
	inorder(root->left);
	cout<<root->data<<" " ;
	inorder(root->right);
}

Node *minvalue(Node *root)
{
  if(root == NULL) return root ;

  while(root->left!=NULL)
  {
  	root = root->left ;
  }

  return root ;
}

Node* deletenode(Node *root, int key)
{
	if(root == NULL) return root ;
	
	if(root->data > key)
	{
		root->left  = deletenode(root->left,key);
	}

	if(root->data < key)
	{
		root->right = deletenode(root->right,key);
	}

	if(root->data == key)
	{
		if(root->left == NULL)
		{
		   Node *temp = root->right ;
		   free(root);
		   return temp ;
		}

		else if(root->right == NULL )
		{
			Node *temp = root->left ;
			free(root);
			return temp ;
		}

		else
		{
			Node *temp = minvalue(root->right) ;
            root->data = temp->data ;
            root->right = deletenode(root->right, temp->data);
            return root ;
		}
	}

	return root ;
}


int main()
{
	Node *root = new Node(50) ;
	root->left  = new Node(30);
	root->right = new Node(70);
	root->left->left = new Node(20);
	root->left->right = new Node(40);
	root->right->left = new Node(60);
	root->right->right = new Node(80);

	cout<<"inorder traversal of the given tree"<<endl ;
	inorder(root) ;
	cout<<endl ;

	cout<<"delete 20"<<endl ;
	root = deletenode(root, 20);
    cout<<"inorder traversal of modified tree"<<endl ;
    inorder(root);
    cout<<endl ;

    cout<<"delete 30"<<endl ;
    root = deletenode(root,30);
    cout<<"inorder traversal of modified tree"<<endl ;
    inorder(root);
    cout<<endl ;

    cout<<"delete 50"<<endl ;
    root = deletenode(root,50);
    cout<<"inorder traversal of modified tree"<<endl ;
    inorder(root) ;
    cout<<endl ;
}


