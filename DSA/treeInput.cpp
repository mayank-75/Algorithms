#include<bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
	Node(int x){
		data=x;
		left=NULL;
		right=NULL;
	}
};

int main(void){
	int n;
	cin>>n;
	Node* arr[n+1];
	for(int i=0;i<n+1;i++){
		arr[i] = new Node(999);//999 is just a random number
	}
	
	for(int i=0;i<n-1;i++){
		int a,b;
		char c;
		cin>>a>>b>>c;
		if(c=='L'){	
			arr[a]->left=arr[b];
		}
		else if(c=='R'){
			arr[a]->right=arr[b];
		}
	}

	for(int i=0;i<n;i++){
		cin>>arr[i]->data;
	}

	Node* root=arr[1];
}