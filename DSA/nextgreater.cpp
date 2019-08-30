# include<bits/stdc++.h>
# define ll long long
using namespace std ;

int leftind[10000000] ,rightind[10000000] ;

void rightgreater(int a[] , int n)
{
    stack<int> s ;
    for(int i=0;i<n;i++)
    {
        while(!s.empty() && a[s.top()] <= a[i])
        {
            rightind[s.top()] = i ;
            s.pop();
        }

        s.push(i) ;
    }
}


void leftgreater(int a[], int n)
{
    stack<int>s ;
    for(int i=n-1;i>=0;i--)
    {
        while(!s.empty() && a[s.top()] <= a[i])
        {
            leftind[s.top()] = i ;
            s.pop() ;
        }

        s.push(i) ;
    }
}


int main()
{
    int t ; cin>>t ;
    while(t--)
    {
        int n ; cin>>n ; 
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i] ;
        for(int i=0;i<n;i++){ rightind[i] = i , leftind[i] = i ; }
        rightgreater(a,n);
        leftgreater(a,n) ;
        int ans = 0 ;
        for(int i=0 ; i<n;)
        {
            ans += min(a[leftind[i]],a[rightind[i]])*(rightind[i]-leftind[i]-1) ;
            for(int x = leftind[i]+1;x<rightind[i];x++) ans-= a[x] ;
            if(i == rightind[i]) i++ ;
            else i = rightind[i] ;
            cout<<ans<<" " ;
        }

        cout<<endl ;
        
        cout<<ans<<endl ;
        
        
    }
}



/*void nextgreater(int a[], int n)
{
	stack<int> s ;


	for(int i=0;i<n;i++)
	{

		while(!s.empty() && a[i] > a[s.top()])
		{
			ind[s.top()] = i  ;
			s.pop();
		}

		s.push(i);
	}

}*/

/*int main()
{
	int t ; cin>>t ;
	while(t--)
	{
		int n ; cin>>n ;
		int a[n] ;
		for(int i=0;i<n;i++) cin>>a[i] ;
		for(int i=0;i<n;i++) ind[i] = n ;
		nextgreater(a,n);
	    /*for(int i=0;i<n;i++)
	    	cout<<a[ind[i]]<<" ";
	    cout<<endl ;
		int ans = 0 ;
	    for(int i=0;i<n;)
	    {
	    	if(a[i] == a[i+1]){ i++ ; continue ;}
	    	int nextg = ind[i];
	    	int width = nextg-i-1 ;
	    	ans += (width*a[i]) ;
	    	for(int x=i+1;x<nextg;x++)
	    		ans -= a[x] ;
	    	i = nextg ;
	    }

	    //cout<<endl ;

	    cout<<ans<<endl ;

	}
}*/

//int nextg[1000];
/*ll rightind[1000],leftind[1000];

void leftsmaller(ll a[], ll n)
{
	stack<ll> s ;
   
	for(ll i=n-1;i>=0;i--)
	{
		while(!s.empty() && a[i] < a[s.top()])
		{
			leftind[s.top()] = i ;
			s.pop();
		}

		s.push(i) ;
	}

}

void rightsmaller(ll a[], ll n)
{
	stack<ll> s ;
	for(ll i=0;i<n;i++)
	{
		while(!s.empty() && a[i] < a[s.top()])
		{
			rightind[s.top()] = i ;
			s.pop();
		}

		s.push(i) ;
	}
}



ll largestrec(ll a[], ll n)
{
  vector<ll> area ;
  memset(leftind,-1,sizeof(leftind));
  for(ll i=0 ; i<n;i++) rightind[i] = n ; 
  leftsmaller(a,n) ;
  rightsmaller(a,n) ;

  for(int i=0;i<n;i++)
  	cout<<"leftind-"<<i<<" = "<<leftind[i]<<"\t"<<"rightind-"<<i<<" = "<<rightind[i]<<endl ;

  for(int i=0;i<n;i++)
  {
  	area.push_back((abs(leftind[i]-rightind[i])-1)*a[i]);
  }

  return *max_element(area.begin(),area.end());

  
}

int main()
{
	ll t ; cin>>t ;
	while(t--)
	{
	  ll n ; cin>>n ;
	  ll a[n] ;
	  for(ll i=0;i<n;i++){ cin>>a[i] ; }
	  memset(leftind,-1,sizeof(leftind));
      for(ll i=0 ; i<n;i++) rightind[i] = n ; 
	  cout<<largestrec(a,n)<<endl ;
	}
}*/

/*void nextgreater(int a[], int n)
{
	stack<int> s ;
	for(int i=0;i<n;i++)
	{
		while(!s.empty() && a[i] < a[s.top()])
		{
			nextg[s.top()] = a[i] ;
			s.pop();
		}

		s.push(i);

	}

}*/

/*int main()
{
	int t ; cin>>t ;
	while(t--)
	{
		int n ; cin>>n ;
		int a[n];
		memset(nextg,-1,sizeof(nextg));
		for(int i=0;i<n;i++)
			cin>>a[i] ;

		for(int i=0;i<n;i++) cout<<a[i]<<" " ;
		cout<<endl ;

        nextgreater(a,n);
	    for(int i=0;i<n;i++)
	    	cout<<nextg[i]<<" ";
	    cout<<endl ;

	}
}*/


/*bool isbalanced(string s)
{
	bool b = 0 ;
	stack<char> st ;
	for(char x: s)
	{
		if(x == '(' || x == '{' || x == '[')
         st.push(x);

        else
        {
        	if(!st.empty())
        	{	
        		char t = st.top();
        		st.pop();
        		if(x == ')' && t != '(')
        		{
    				
					b = 1 ;
					cout<<"here\n";
					break ;
        		}
        		
        		if(x == '}' && t != '{')
        		{
    				
					b = 1 ;
					cout<<"here\n";
					break ;
        		}

        		if(x == ']' && t != '[')
        		{
    				
					b = 1 ;
					cout<<"here\n";
					break ;
        		}
        	}
        	else
        		b = 1;
        }
        //cout<<b<<"ok\n " ;
        if(b == 1) break ;
	}
	//cout<<endl ;

	if(!st.empty())
		b = 1;
	//cout<<b<<"ok2\n " ;
	return b ;
}

int main()
{
	int t ; cin>>t ;
	while(t--)
	{
		string s ; cin>>s ;
		bool b = isbalanced(s);
		cout<<(b == 0 ?"Balanced!" : "Unblanced!")<<endl ;
	}

}*/

/*class twostacks
{
	public :
	int *a ;
	int size ;
	int top1,top2 ;
	twostacks(int n)
	{
		size = n ;
		a = new int[n] ;
		top1 = -1 ;
		top2 = size ;
	}

	void push1(int x)
	{
		if(top1+1 == top2)
		{
			cout<<"stack overflow!"<<endl ; return ;
		}
		a[++top1] = x ;
		
	}

	void push2(int x)
	{
		if(top2-1 == top1)
		{
			cout<<"stack overflow"<<endl ; return ;
		}
		a[--top2] = x ;
	}

	int pop1()
	{
		int topop = 0 ;
		if(top1!=-1)
		{ 
          topop = a[top1--];
		}
		else {cout<<"stack underflow"<<endl ; exit(1) ; }
		return topop ;
	}

	int pop2()
	{
		int topop = 0 ;
		if(top2!=size) topop = a[top2++]; 
		else {cout<<"stack underflow"<<endl ; exit(1) ; }
		return topop ;
	}

	void printstack()
	{
		for(int i=0;i<size;i++)
		 cout<<a[i]<<" " ;
	    cout<<endl ;
	}
} ;

int main()
{
	twostacks ts(5);
	ts.push1(5);
	ts.push2(10);
	ts.push2(15);
	ts.push1(11);
	ts.push2(7);
	ts.printstack() ;
	cout<<"popped element from stack1 is "<< ts.pop1() ;
	cout<<endl ;
	ts.push2(40);
	ts.printstack();
	cout<<"Popped element from stack2 is "<< ts.pop2() ;
	cout<<endl ;

}/*



/*int main()
{
	string str ; cin>>str ;
  	stack<int> s ;
  	for(char x  : str)
  		s.push(x) ;

  	for(char &x : str)
  		x = s.top() , s.pop() ;

  	cout<<str<<endl ;
}

int main()
{
	vector<int> v = {1,2,3,4} ;
	for(int &x : v)
		x = 2*x ;

	for(int x : v)
		cout<<x<<" ";
	cout<<endl ;
}*/

