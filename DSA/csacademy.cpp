# include<bits/stdc++.h>
using namespace std ;

void generatePermutations(vector<vector<int>> &res, vector<int> comb, int index, vector<int> &v)
{
    if(index >= v.size())
    {
        res.push_back(comb) ; return ;
    }
    
    for(int i=0;i<v.size();i++)
    {
        auto it = find(comb.begin(),comb.end(),i) ;
        if(it == comb.end())
        {
            comb.push_back(i) ;
            generatePermutations(res,comb,index+1,v) ;
            comb.pop_back() ;
        }
    }
}

void printDistinctPermutations(vector<int>& v) {
    
    sort(v.begin(),v.end()) ;
    vector<vector<int>> res ;
    vector<int> comb ;
    generatePermutations(res,comb,0,v) ;
    set<vector<int>> s ;
    for(int i=0;i<res.size();i++)
    {
    	vector<int>  temp ;
    	for(int x : res[i])
    	{
          temp.push_back(v[x]) ;
    	}

    	s.insert(temp) ;
    }

    for(auto it=s.begin();it!=s.end();it++)
    {
    	for(int x : *it) cout<<x<<" " ;
    		cout<<endl ;
    }
    
}

int main()
{
	int t;  cin>>t ;
	while(t--)
	{
		int n ; cin>>n ;
		vector<int> v(n) ;
		for(int i=0;i<n;i++) cin>>v[i] ;
		printDistinctPermutations(v);

	}
}

/*void possibleSum(int n, int i, vector<int> &arr, vector<int> comb, vector<vector<int>> &res)
{
    if(i >= arr.size()) return  ;
    if(n == 0)
    {
        res.push_back(comb) ;
        return  ;
    }
    
    if(n-arr[i] >=0) 
    {
        comb.push_back(arr[i]) ;
        possibleSum(n-arr[i],i+1,arr,comb,res) ;
        comb.pop_back() ;
        possibleSum(n,i+1,arr,comb,res) ;
    }
    
    else
    {
        possibleSum(n,i+1,arr,comb,res) ;
    }
}

bool compare(vector<int> v1, vector<int> v2)
{
    return v1.size() < v2.size() ;
}

vector<int> fibonacciSum(int n) {
    
    
    vector<int> arr(2) ;
    arr[0] = 0, arr[1] = 1 ;
    while(arr.back() < n)
    {
        int x = arr.size() ;
        arr.push_back(arr[x-1]+arr[x-2]) ;
    }

    /*for(int x : arr) cout<<x<<" " ;
    	cout<<endl ;
    
    vector<vector<int>> res ;
    vector<int> comb ;
    possibleSum(n,0,arr,comb,res) ;
    sort(res.begin(),res.end(),compare) ;
    /*for(auto v : res)
    {
    	for(int x : v) cout<<x<<" " ;
    		cout<<endl ;
    }
    
    return res[0] ;
    
    
    
    
}*/


/*vector<int> fibonacciSum(int n) {
    
    
    vector<int> arr(2) ;
    arr[0] = 0, arr[1] = 1 ;
    while(arr.back() < n)
    {
        int x = arr.size() ;
        arr.push_back(arr[x-1]+arr[x-2]) ;
    }

    vector<int> res ;
    int x = arr.size() ;
    
    for(int i=x-1;i>=0;i--)
    {
        if((int)(n/arr[i]))
        {
            int c = n/arr[i] ;
            while(c--) res.push_back(arr[i]) ;
            n = n%arr[i] ;
        }
    }
    
    sort(res.begin(),res.end()) ;
    return res ;
    
    
}



int main()
{
	int t ; cin>>t ;
	while(t--)
	{
		int n ; cin>>n ;
		vector<int> res = fibonacciSum(n) ;
		for(int x : res) cout<<x<<" " ;
			cout<<endl ;
	}
}*/

/*bool compare(vector<int> v1, vector<int> v2)
{
    for(int i=0;i<v1.size();i++)
    {
        if(v1[i]!=v2[i]) return v1[i] < v2[i] ;
    }
}

void generateCombinations(int N, int K) {

  vector<vector<int>> res ; 
  int num = pow(2,N) ;
  vector<int> temp ;
  for(int i=0;i<num;i++)
  {
      temp.clear() ;
      for(int j=0;j<N;j++)
      {
          if(i & (1<<j)) temp.push_back(j+1) ;
      }
      
      if(temp.size() == K) 
      {
          res.push_back(temp) ;
      }
  }
  
  sort(res.begin(),res.end(),compare) ;

  for(auto v : res)
  {
  	for(int x  : v) cout<<x<<" " ;
  		cout<<endl ;
  }
     
}

int  main()
{
	int t ; cin>>t;
	while(t--)
	{
		int n,k ; cin>>n>>k ;
		generateCombinations(n,k) ;
	}

}*/

