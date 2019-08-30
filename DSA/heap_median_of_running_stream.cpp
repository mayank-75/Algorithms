// this is very hard to think appraoch, anyways
/*
steps of algo-
- median is average when total elements are even, middle element else
- so here we maintain two heaps min heap for greater half of stream
ans max heap for lower half
- case 1- if size of both heap are same, if current median is smaller than the
next element, push it to the min heap and curr median is top of min heap,
else if curr median is greater than the incoming  element, push it to max heap,
curr median is top of max hap
case 2- if size of max_heap is greater than the size if min heap ans incoming element 
is smaller than curr median, pop the top element of max heap and put in the min heap,
else push the incoming element in min heap, median will be the mean of top elements of both heap
case 3- if size of min heap is greater than the max heap and incoming element is greater than the curr median,
pop from min heap and put in the max heap, push the incoming element in min heap,
else push the incoming element in max heap
median will be the mean of top elements of both the heaps
*/


# include<bits/stdc++.h>
#  define int long long
using namespace std ;

int32_t  main()
{
    int n ; cin>>n ;
    int x ;
    priority_queue<int> max_heap ;
    priority_queue<int,vector<int>,greater<int>> min_heap ;
    int curr_median = 0 ;
    while(n--)
    {
        cin>>x ;
        if(min_heap.size() == max_heap.size())
        {
            if(x > curr_median) min_heap.push(x) , curr_median = min_heap.top() ;
            else max_heap.push(x), curr_median = max_heap.top() ;
        }
        
        else if(min_heap.size() > max_heap.size())
        {
            if(x > curr_median)
            {
                int temp = min_heap.top() ; min_heap.pop() ;
                max_heap.push(temp) ;
                min_heap.push(x) ;
            }
            
            else max_heap.push(x) ;
            curr_median = (min_heap.top()+max_heap.top())/2 ;
        }
        
        else if(max_heap.size() > min_heap.size())
        {
            if(x < curr_median)
            {
                int temp = max_heap.top() ; max_heap.pop() ;
                min_heap.push(temp) ;
                max_heap.push(x) ;
            }
            
            else min_heap.push(x) ;
            
            curr_median = (min_heap.top()+max_heap.top())/2 ;
        }
        
        cout<<curr_median<<endl ;
        
    }
}