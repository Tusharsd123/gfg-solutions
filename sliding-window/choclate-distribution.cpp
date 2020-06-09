int findMinDiff(int arr[], int n, int m) 
{ 
    // if there are no chocolates or number 
    // of students is 0 
    if (m==0 || n==0) 
        return 0; 
  
    // Sort the given packets 
    sort(arr, arr+n); 
  
    // Number of students cannot be more than 
    // number of packets 
    if (n < m) 
       return -1; 
  
    // Largest number of chocolates 
    int min_diff = INT_MAX; 
  
    // Find the subarray of size m such that 
    // difference between last (maximum in case 
    // of sorted) and first (minimum in case of 
    // sorted) elements of subarray is minimum. 
      
    for (int i=0; i+m-1<n; i++) 
    { 
        int diff = arr[i+m-1] - arr[i]; 
        if (diff < min_diff) 
            min_diff = diff; 
    } 
    return min_diff; 
} 

time complexity is O(nlogn)
