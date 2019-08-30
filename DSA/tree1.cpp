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
		left = right = NULL ;
	}
};

/*code for bulding tree in a level order fashion from input array*/
Node *buildtree(int a[], int n, int i)
{
    Node *t ;
	if(i<n)
	{
	  t = new Node(a[i]);
	  t->left = buildtree(a,n,2*i+1);
	  t->right = buildtree(a,n,2*i+2);
	  return t ;
	}
	return NULL ;
}

// Function to print tree nodes in 
// InOrder fashion 
void inOrder(Node* root) 
{ 

    if (root != NULL) 
    { 
        inOrder(root->left); 
        cout << root->data <<" "; 
        inOrder(root->right); 
    } 

} 
  
// Driver program to test above function 
int main() 
{ 
    int arr[] = { 1, 2, 3, 4, 5, 6, 6, 6, 6 }; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    Node* root = buildtree(arr,n,0); 
    inOrder(root); 
} 



/*
code for building tree using levelorder and inorder arrays
vector<int> extract(int in[], int l[], int start, int index)
{
	vector<int> 
}

Node* builtree(int in[], int l[], int start, int end)
{
	if(start > end) return NULL ;
	Node *t = new Node(l[0]);
	if(start == end) return t ;

}

//Driver program to test above functions
int main() 
{ 
    int in[]    = {4, 8, 10, 12, 14, 20, 22}; 
    int level[] = {20, 8, 22, 4, 12, 10, 14}; 
    int n = sizeof(in)/sizeof(in[0]); 
    Node *root = buildTree(in, level, 0, n - 1, n); 
  
    //Let us test the built tree by printing Insorder traversal 
    cout << "Inorder traversal of the constructed tree is \n"; 
    printInorder(root); 
  
    return 0; 
}
*/

/*

struct Node
{
	char data ;
	Node *left, *right ;
	Node(char d)
	{
		data = d ;
		left = right = NULL ;
	}
};

code for building tree using preorder and inorder traversal
int search(char in[], int start, int end, char key)
{
  for(int i=start;i<=end;i++)
  {
  	if(key == in[i]) return i ;
  }

  return -1 ; 
  
}

int preindex = 0 ;

Node* buildtree(char in[], char pre[], int start, int end)
{
   if(start > end) return NULL ;
   Node *t = new Node(pre[preindex++]);
   if(start == end) return t ;
   int inindex = search(in,start,end,t->data);
   t->left = buildtree(in,pre,start,inindex-1);
   t->right = buildtree(in,pre,inindex+1,end);
   return t ;
}



void printInorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
  
    //first recur on left child
    printInorder(node->left); 
  
    //then print the data of node
    printf("%c ", node->data); 
  
    //now recur on right child 
    printInorder(node->right); 
}

Driver program to test above functions
int main() 
{ 
    char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' }; 
    char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' }; 
    int len = sizeof(in) / sizeof(in[0]); 
    struct Node* root = buildtree(in, pre, 0, len - 1); 
  
    //Let us test the built tree by printing Insorder traversal
    printf("Inorder traversal of the constructed tree is \n"); 
    printInorder(root); 
    getchar(); 
}*/


