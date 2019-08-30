# include<bits/stdc++.h>
using namespace std ;

int to_int(string s)
{
	int n = s.size() ;
	int num = 0 ;
	for(int i=0;i<n;i++) 
	{
		num += (s[n-i-1]-'0')*pow(2,i) ;
	}

	return num ;
}

int main()
{
   int t ; cin>>t ;
   while(t--)
   {
   	 string s ; cin>>s ;
   	 cout<<to_int(s)<<endl ;
   }
}