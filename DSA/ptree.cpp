# include<bits/stdc++.h>
using namespace std ;

struct Node
{
	int data ;
	Node *left, *right ;
	Node(int d)
	{
		data = d ;
		left = right = NULL ;
	}
};

int search(int in[], int key, int n)
{
	for(int i=0;i<n;i++)
	{
		if(in[i] == key) return i ;
	}

	return -1 ;
}

int pindex = 0 ;

Node* constructree(int in[], int pre[], int n)
{
  if(pindex>5) return NULL ;
  Node* root = new Node(pre[pindex]); 
  //cout<<root->data<<" " ;
  int index = search(in,root->data,n);
  if(index == -1) return NULL ;
  //cout<<index<<" " ;
  pindex++ ;
  root->left = constructree(in,pre,index);
  root->right = constructree(in+index+1,pre,n);
  return root ;
  

  return NULL ;

   
}

void Inorder(Node *root)
{
	if(root == NULL) return ;
	Inorder(root->left);
	cout<<root->data<<" " ;
	Inorder(root->right);
}

int main()
{
  int in[] =  {4,2,5,1,3,6} ;
  int pre[] = {1,2,4,5,3,6} ;
  int n = 6 ;
  Node *root = constructree(in,pre,n);
  Inorder(root) ;
  cout<<endl ;


}