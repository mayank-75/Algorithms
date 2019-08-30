# include<bits/stdc++.h>
using namespace std ;

//recusive only approach
void generateSubsets(vector<int> &S, int index, vector<int> &current, vector<vector<int> > &result) {
    if (index >= S.size()) {
        result.push_back(current);
        return;
      }
    // Ignore the current index.
    generateSubsets(S, index + 1, current, result);

    // Include the current index. 
    current.push_back(S[index]);
    generateSubsets(S, index + 1, current, result);
    current.pop_back();
}


// In the array A at every step we have two 
// choices for each element either  we can 
// ignore the element or we can include the 
// element in our subset 
//recursive and iterative approach
void subsetsUtil(vector<int>& A, vector<vector<int> >& res, 
                 vector<int>& subset, int index) 
{ 
    res.push_back(subset); 
    for (int i = index; i < A.size(); i++) { 
  
        // include the A[i] in subset. 
        subset.push_back(A[i]); 
  
        // move onto the next element. 
        subsetsUtil(A, res, subset, i + 1); 
  
        // exclude the A[i] from subset and triggers 
        // backtracking. 
        subset.pop_back(); 
    } 
  
    return; 
} 


int main()
{
	vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > result; 
        vector<int> current;
        sort(S.begin(), S.end());
        generateSubsets(S, 0, current, result);
        sort(result.begin(), result.end());
        return result;
	}
}