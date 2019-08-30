# include<bits/stdc++.h>
using namespace std ;

int start,endi ;

bool ispresent(int a[],int s, int e,int k)
{
	if(s>e) return false ;
	else if(a[s]+a[e] == k && s!=e) 
	{
		start = s ; endi = e ;
		return true ;
	}

	return (ispresent(a,s+1,e,k)||ispresent(a,s,e-1,k));
}

int main()
{
	int t ; cin>>t ;
	while(t--)
	{
		int n,sum ; cin>>n ;
		int a[n+1] ;
		for(int i=1;i<=n;i++)
		{
			int x ; cin>> x ;
			a[i] = x*x ;
		}
		for(int i=1;i<=n;i++)
		{
		  if(ispresent(a,1,n,a[i])) cout<<"Yes- "<<endl ;
	      else cout<<"No"<<endl ;
		}


	}
}