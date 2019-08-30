# include<bits/stdc++.h>
using namespace std ;
# define int long long

struct compare
{
	bool operator()(pair<int,int>p1, pair<int,int>p2)
	{
		return p1.second < p2.second ;
	}
};

int32_t main()
{
	int t ; cin>>t ;
	while(t--)
	{
		int n,m ; cin>>n>>m ;
		int freqDrinks[m+1] ;
		priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq ;
		for(int i=1;i<=m;i++)
		{
			int x ; cin>>x ;
			freqDrinks[i] = x ;
			pq.push({i,x}) ;
		}
        int drink, willPrice, alterPrice ;
        int res = 0 ;
        /*while(!pq.empty())
        {
        	auto x = pq.top() ;
        	cout<<x.first<<" "<<x.second<<endl ;
        	pq.pop() ;
        }*/
		while(n--)
		{
           cin>>drink>>willPrice>>alterPrice ;
           cout<<drink<<" "<<willPrice<<" "<<alterPrice<<endl ;
           if(freqDrinks[drink]!=0) res += willPrice , freqDrinks[drink]-- ;
           else
           {
           	 while(pq.top().first == drink)
           	 {
           	 	pq.pop() ;
           	 }

           	 int chooseDrink = pq.top().first ;
           	 //cout<<alterPrice<<" " ;
           	 res += alterPrice ; freqDrinks[chooseDrink]-- ;

           }
		}
        cout<<endl ;
		cout<<res<<endl ;


	}
}

/*int32_t main()
{
	int t ; cin>>t ;
	while(t--)
	{
		int n,m ; cin>>n>>m ;
		int arr[m+1] ;
		memset(arr,0,sizeof(arr)) ;
		int d,v ;
		for(int i=0;i<n;i++) 
		{
			cin>>d>>v ;
            if(arr[d] < v) arr[d] = v ;
		}

		sort(arr+1,arr+m+1,greater<int>()) ;
		for(int i=1;i<=m;i++) cout<<arr[i]<<" " ;
			cout<<endl ;
		cout<<arr[1]+arr[2]<<endl ;
	}
}*/

/*int32_t main()
{
	int t ; cin>>t ;
	while(t--)
	{
	   int n ; cin>>n ;
	   string  s1,s2 ; cin>>s1>>s2 ;
	   int score = 0 ;
	   for(int i=0;i<n-1;i++)
	   {
	   	 if(s1[i] == s2[i]) score++ ;
	   	 else if(s2[i]!='N') i++ ;
	   }

	   if(s1[n-1] == s2[n-1]) score++ ;

	   cout<<score<<endl ;
	}
}*/


/*int32_t main()
{
	int t ; cin>>t ;
	while(t--)
	{
		int n;  cin>>n ;
		int oddA = 0, oddB = 0 , sum = 0 ;
		int x ;
		for(int i=0;i<n;i++)
		{
			cin>>x ;
			if(x%2) oddA++ ;
		}

		for(int i=0;i<n;i++)
		{
			cin>>x ; 
			if(x%2) oddB++ ;
		}

		cout<<(sum-abs(oddA-oddB))/2<<endl ;
		
	}
}*/

/*int32_t main()
{
	int t ; cin>>t ;
	while(t--)
	{
		int x,y,k  ; cin>>x>>y>>k ;
		int sets = (x+y)/k ;
		if(sets%2) cout<<"Paja"<<endl ;
		else cout<<"Chef"<<endl ;
	}
}*/

