//We can use sorting to solve it in lesser time complexity. We can sort the array in O(nLogn) time. 
//Once the array is sorted, then all we need to do is a linear scan of the array. 
//So this approach takes O(nLogn + n) time which is O(nLogn).

//We can also use hashing. We can build a hash table of all positive elements in the given array.
//Once the hash table is built. We can look in the hash table for all positive integers, starting from 1
//As soon as we find a number which is not there in hash table, we return it. This approach may take O(n) time on average
//but it requires O(n) extra space.

//O(n) T.C
//O(1) S.C
int firstMissingPos(int A[], int n) 
{ 
  
    // To mark the occurrence of elements 
    bool present[n + 1] = { false }; 
  
    // Mark the occurrences 
    for (int i = 0; i < n; i++) { 
  
        // Only mark the required elements 
        // All non-positive elements and 
        // the elements greater n + 1 will never 
        // be the answer 
        // For example, the array will be {1, 2, 3} 
        // in the worst case and the result 
        // will be 4 which is n + 1 
        if (A[i] > 0 && A[i] <= n) 
            present[A[i]] = true; 
    } 
  
    // Find the first element which didn't 
    // appear in the original array 
    for (int i = 1; i <= n; i++) 
        if (!present[i]) 
            return i; 
  
    // If the original array was of the 
    // type {1, 2, 3} in its sorted form 
    return n + 1; 
} 
