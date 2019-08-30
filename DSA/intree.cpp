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

Node* insertnode(Node *root, int key)
{
    Node *node = new Node(key) ;
    queue<Node*>q ;
    if(root == NULL) root = node ;
    q.push(root);
    while(1)
    {
        Node *temp = q.front();
        q.pop();
        if(temp->left == NULL){ temp->left = node ; break ; }
        else q.push(temp->left) ;
        
        if(temp->right == NULL){ temp->right = node ; break ; }
        else q.push(temp->right) ;
    }
    
    return root ;
}

void Inorder(Node *root)
{
    if(root == NULL) return  ;
    Inorder(root->left);
    cout<<root->data<<" " ;
    Inorder(root->right) ;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(5);
    root->left->left = new Node(4);
    root->right->right = new Node(8) ;
    root->left->right = new Node(2) ;
    int key ; cin>>key ;
    cout<<"Inorder traversal before insertion : " ;
    Inorder(root);
    root = insertnode(root,key);
    cout<<"Inorder traversal after insertion : " ;
    Inorder(root);
}