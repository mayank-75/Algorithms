# include<bits/stdc++.h>
# define ll long long
using namespace std ;


struct Node
{
	int data ;
	Node *left, *right ;
	Node(int d)
	{
		data = d ;
		right = left = NULL ;
	}
};

int c = 0 ;
/*
code for no of nodes in each subtree rooted at each node
void countnode(Node* root)
{
	if(root == NULL) return ;
	int x = c ;
	countnode(root->left);
	countnode(root->right);
	cout<<"no of nodes in subtree rooted at "<<root->data<<" is "<<c+1-x<<endl ;
	c++ ;
}
*/

/*code for vertical order traversal
map<int,vector<Node *>>m ;

void vertiorder(Node *root, int hd)
{
  if(root == NULL) return  ;
  m[hd].push_back(root);
  vertiorder(root->left, hd-1);
  vertiorder(root->right, hd+1);
}
*/

map<int,vector<Node *>>m ;

void topview(Node *root, int hd)
{
	if(root == NULL) return  ;
	queue<pair<int,Node *>> q ;
	q.push({hd,root});
	while(!q.empty())
	{
		//cout<<q.front().second->data<<" " ;
		Node *t = q.front().second ;
		hd = q.front().first ;
		m[hd].push_back(t); 
		q.pop() ;
		 
		if(t->left !=NULL) q.push(make_pair(hd-1,t->left));
		if(t->right!=NULL) q.push(make_pair(hd+1,t->right));

	}

	//cout<<endl ;
	
}


int main()
{

	Node *root = new Node(1) ;
	root->left = new Node(2) ;
    root->right = new Node(3) ;
    /*root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);*/
	root->left->left = new Node(4) ;
	root->left->right = new Node(5) ;
	root->right->left = new Node(6) ;
	root->right->right = new Node(7);
	/*Node *root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->right->left = new Node(6); 
    root->right->right = new Node(7); 
    root->right->left->right = new Node(8); 
    root->right->right->right = new Node(9); */
	//lorder(root) ;
	//countnode(root) ;
	//vertiorder(root,0);
	topview(root,0);
	for(auto p : m) cout<<p.second[0]->data<<" " ;
	cout<<endl;
	
	
}   


/*
code for level order with mapping of nodes at each level
void lorder(Node * root)
{
	if(root == NULL) return  ;
	int level = 0 ;
	queue<pair<Node*,int>> q ;
	q.push(make_pair(root,level));
	map<int,vector<int>> m ;
	while(!q.empty())
	{
       Node *temp = q.front().first ;
       int l = q.front().second ;
       m[l].push_back(temp->data);
       q.pop();

       if(temp->left!=NULL) q.push(make_pair(temp->left,l+1));

       if(temp->right!=NULL) q.push(make_pair(temp->right,l+1));

	}

    for(auto p : m)
    {
    	cout<<p.first<<" :\t" ;
    	for(auto x : p.second)
    		cout<<x<<" ";
    	cout<<endl ;
    }
}
*/


/*
code for level order traversal without storing nodes at each level
void levelorder(Node* root)
{
	queue<Node*> s ;
	s.push(root);
	while(!s.empty())
	{
		Node *temp  = s.front() ;
		cout<<temp->data<<" " ;
		s.pop();
		if(temp->left != NULL) s.push(temp->left) ;

        if(temp->right != NULL) s.push(temp->right) ;
	}

	cout<<endl ;
}
*/




