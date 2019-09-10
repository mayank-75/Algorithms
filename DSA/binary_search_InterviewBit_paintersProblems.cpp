# include<bits/stdc++.h>
# define int long long
using namespace std ;


bool isPossible(vector<int> &A, int sum, int K)
{
	int c = 1 , s =  0 ;
	for(int i=0;i<A.size();i++)
	{
		s += A[i] ;
		if(s > sum) s = A[i] , c++ ;
	}

	if(c<=K) return true ;
	return false ;
}


int painters(int K, int T, vector<int> &A)
{
   int max = 0 , n = A.size(), min = 0 ;
   for(int i=0;i<n;i++) max += A[i] ;
   while(min < max)
   {
   	 int mid = (min+max)/2 ;
   	 if(isPossible(A,mid,K)) r = mid ;
   	 else l = mid+1 ;
   }

   return min ;
}