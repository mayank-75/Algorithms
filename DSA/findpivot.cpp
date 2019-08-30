#include <iostream>
using namespace std;

int findPivot(int a[], int s, int e)
{
    while(s <= e)
    {
        int mid = (s+e)/2 ;
        //cout<<a[mid]<<" "<<a[mid+1]<<endl ;
        if(mid-1 >= s && a[mid] < a[mid-1]) return mid-1 ;
        else if( mid +1 <= e && a[mid] > a[mid+1]) return mid ;
        else if(a[mid] > a[s]) s = mid+1 ;
        else e = mid ;
    }
    
    return s ;
}

int main() {
	//code
	int t ; cin>>t ;
	while(t--)
	{
	    int n ; cin>>n ;
	    int a[n] ;
	    for(int i=0;i<n;i++) cin>>a[i] ;
	    cout<<findPivot(a,0,n-1)<<endl ;
	}
	return 0;
}