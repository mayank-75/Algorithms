void grayCodeUtil(vector<int>& res, int n, int& num) 
{ 
    // base case when we run out bits to process 
    // we simply include it in gray code sequence. 
    if (n == 0) { 
        res.push_back(num); 
        return; 
    } 
  
    // ignore the bit. 
    grayCodeUtil(res, n - 1, num); 
  
    // invert the bit. 
    num = num ^ (1 << (n - 1)); 
    grayCodeUtil(res, n - 1, num); 
}

vector<int> Solution::grayCode(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
     vector<int> res; 
  
    // num is passed by reference to keep 
    // track of current code. 
    int num = 0; 
    grayCodeUtil(res,A,num); 
  
    return res; 
    
}
