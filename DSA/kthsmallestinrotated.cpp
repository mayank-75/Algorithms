# include<bits/stdc++.h>

int binsearch(const vector<int> &a, int l, int r, int x)
{
    int mid ;
    while(l < r)
    {
        mid = (l+r)/2 ;
        if(a[mid] == x) return mid ;
        else if(a[mid] > x) r = mid-1 ;
        else l = mid +1 ;
    }
    
    if(a[l] == x) return l ;
    else return -1 ;
}

int findPivot(const vector<int>&a, int l, int r)
{
    int mid ;
    while(l<r)
    {
        mid = (l+r)/2 ;
        if(mid > l && a[mid] < a[mid-1]) return mid-1 ;
        else if(mid < r && a[mid] > a[mid+1]) return mid ;
        else if(a[mid] < a[l]) r= mid-1 ;
        else l = mid+1 ;
    }

    return l ;
}

int Solution::search(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int pivot = findPivot(A,0,A.size()) ;
    if(pivot == A.size()) pivot = A.size()-1 ;
    if(B >= A[0] && B <= A[pivot]) return binsearch(A,0,pivot,B) ;
    else return binsearch(A,pivot+1,A.size()-1,B) ;
    
    
}
