/* this question is based on the application of LDS(not longest increasing but the logic is same)
first we have to generate all the 3 possible rotations of the box, then sort them on the basis of base area, then just apply logic of LDS*/


#include<bits/stdc++.h>
using namespace std;
int maxHeight(int height[],int width[],int length[],int n);
int main()
{
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	
 	int A[1000],B[1000],C[10001];
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		A[i]=a;
		B[i]=b;
		C[i]=c;
	}
	cout<<maxHeight(A,B,C,n)<<endl;
}
 
/*This is a function problem.You only need to complete the function given below*/
/*The function takes an array of heights, width and 
length as its 3 arguments where each index i value 
determines the height, width, length of the ith box. 
Here n is the total no of boxes.*/
bool comp(pair<pair<int,int>,int> p1, pair<pair<int,int>,int> p2)
{
    int l1 = p1.first.first , w1 = p1.first.second ;
    int l2 = p2.first.first, w2 = p2.first.second ;
    return (l1*w1) > (l2*w2) ;
}

int maxHeight(int height[],int width[],int length[],int n)
{
    //Your code here
    vector<pair<pair<int,int>,int>> v ;
    for(int i=0;i<n;i++)
    {
       int l = length[i], w = width[i], h = height[i] ;
       v.push_back({{max(l,w),min(l,w)},h}) ;
       v.push_back({{max(h,w),min(h,w)},l}) ;
       v.push_back({{max(h,l),min(h,l)},w}) ;
    }
    
    sort(v.begin(),v.end(),comp) ;
    n *= 3 ;
    int dp[n] ;
    for(int i=0;i<n;i++) dp[i] = v[i].second ;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(v[j].first.first > v[i].first.first && v[j].first.second > v[i].first.second && dp[i] < v[i].second + dp[j])
            {
                dp[i] = v[i].second + dp[j] ;
            }
        }
    }
    
    return *max_element(dp,dp+n) ;
}

