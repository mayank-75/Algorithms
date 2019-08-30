# include<bits/stdc++.h>
using namespace std ;

int main()
{
	int a[] = {1,2,5,10,20,50,100,200,500,1000} ;
	int t ; cin>>t ;
	while(t--)
	{
		int sum ; cin>>sum ;
		int ans = 0 ;
		while(sum)
		{
			for(int i=9;i>=0;i--)
			{
				if(sum/a[i])
				{
					cout<<sum<<" "<<a[i]<<" " ;
					ans += sum/a[i];
					sum = sum%a[i] ;
                    cout<<sum<<endl ;
				}
			}

		}

		cout<<ans<<endl ;
	}
}