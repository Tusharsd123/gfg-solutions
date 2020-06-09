void countDistinct(int arr[], int k, int n) 
{ 
    // Creates an empty hashmap hm 
    map<int, int> hm; 
  
    // initialize distinct element count for current window 
    int dist_count = 0; 
  
    // Traverse the first window and store count 
    // of every element in hash map 
    for (int i = 0; i < k; i++) 
    { 
       if (hm[arr[i]] == 0) 
       { 
           dist_count++; 
       } 
    hm[arr[i]] += 1; 
    } 
  
   // Print count of first window 
  cout << dist_count << endl; 
  
   // Traverse through the remaining array 
   for (int i = k; i < n; i++) 
   { 
     // Remove first element of previous window 
     // If there was only one occurrence, then reduce distinct count. 
     if (hm[arr[i-k]] == 1) 
     { 
        dist_count--; 
     } 
   // reduce count of the removed element 
     hm[arr[i-k]] -= 1; 
  
   // Add new element of current window 
   // If this element appears first time, 
   // increment distinct element count 
  
    if (hm[arr[i]] == 0) 
    { 
       dist_count++; 
    } 
    hm[arr[i]] += 1; 
  
  // Print count of current window 
    cout << dist_count << endl; 
  } 
} 
