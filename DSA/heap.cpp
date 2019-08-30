# include<bits/stdc++.h>
using namespace std ;

/* code for sorting almost k sorted elements */
int sortk(int arr[], int n, int k)
{
	priority_queue<int, vector<int>, greater<int>> pq(arr,arr+k+1);
	int index = 0 ;
	for(int i=k+1;i<n;i++)
	{
		arr[index++] = pq.top();
		pq.pop();
		pq.push(arr[i]);
	}

	while(!pq.empty())
	{
		arr[index++] = pq.top();
		pq.pop();
	}
}

void printarr(int arr[], int n)
{
	for(int i=0;i<n;i++) cout<<arr[i]<<" " ;
		cout<<endl ;
}

int main()
{
	int k = 3 ;
	int arr[] = { 2,6,3,12,56,8 };
	int n = sizeof(arr)/sizeof(arr[0]);
	sortk(arr,n,k);

	cout<<"sorted array !"<<endl ;
	printarr(arr,n);
}