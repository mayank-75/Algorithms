/*function that finds the pivot aout which a sorted array is rotated*/
/* strictly try it yourself before seeing the solution*/

int findPivot(int arr[], int low, int high) 
{ 
  // base cases 
  if (high < low) return -1; 
  if (high == low) return low; 
  
   int mid = (low + high)/2; /*low + (high - low)/2;*/
   if (mid < high && arr[mid] > arr[mid + 1]) 
    return mid; 
      
   if (mid > low && arr[mid] < arr[mid - 1]) 
    return (mid-1); 
      
   if (arr[low] >= arr[mid]) 
    return findPivot(arr, low, mid-1); 
      
   return findPivot(arr, mid + 1, high); 
}