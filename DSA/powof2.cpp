#include <iostream>
# define int long long
using namespace std;

int32_t main() {
	//code
	int t ; cin>>t ;
	while(t--)
	{
	    int n ; cin>>n ;
	    if(n == 0) cout<<"NO"<<endl ;
	    else
	    {
	        cout<<((n & (n-1))?"NO":"YES")<<endl ;
	    }
	}
	return 0;
}