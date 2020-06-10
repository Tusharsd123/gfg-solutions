//T.C - O(nlogn)
int findLongestConseqSubseq(int arr[], int n) 
{ 
    int ans = 0, count = 0; 
  
    // sort the array 
    sort(arr, arr + n); 
  
    // find the maximum length 
    // by traversing the array 
    for (int i = 0; i < n; i++) { 
        // if the current element is equal 
        // to previous element +1 
        if (i > 0 && arr[i] == arr[i - 1] + 1) 
            count++; 
        // reset the count 
        else
            count = 1; 
  
        // update the maximum 
        ans = max(ans, count); 
    } 
    return ans; 
} 

//O(N) solution using sets

int findLongestConseqSubseq(int arr[], int n) 
{ 
    unordered_set<int> S; 
    int ans = 0; 
  
    // Hash all the array elements 
    for (int i = 0; i < n; i++) 
        S.insert(arr[i]); 
  
    // check each possible sequence from 
    // the start then update optimal length 
    for (int i = 0; i < n; i++) { 
        // if current element is the starting 
        // element of a sequence 
        if (S.find(arr[i] - 1) == S.end()) { 
            // Then check for next elements 
            // in the sequence 
            int j = arr[i]; 
            while (S.find(j) != S.end()) 
                j++; 
  
            // update  optimal length if 
            // this length is more 
            ans = max(ans, j - arr[i]); 
        } 
    } 
    return ans; 
} 
