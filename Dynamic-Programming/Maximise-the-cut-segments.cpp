//As the solution for maximum number of cuts that can be made in a given length depends on the maximum number of cuts
//previously made in shorter lengths, this question could be solved by the approach of Dynamic Programming. Suppose we 
//are given a length ‘l’. For finding the maximum number of cuts that can be made in length ‘l’, find number of cuts made 
//in shorter previous length ‘l-p’,’l-q’,’l-r’ lengths respectively. The required answer would be the max(l-p,l-q,l-r)+1 as
//one more cut should be needed after this to cut length ‘l’. So for solving this problem for given length, find maximum number
//of cuts that can be made in lengths ranging from ‘1’ to ‘l’.


int findMaximum(int l, int p, int q, int r) 
{ 
  
    // Array to store the cut at each length 
    int dp[l + 1]; 
  
    // All values with -1 
    memset(dp, -1, sizeof(dp)); 
  
    // if length of rod is 0 then total cuts will be 0 
    // so, initialize the dp[0] with 0 
    dp[0] = 0; 
  
    for (int i = 0; i <= l; i++) { 
  
        // if certain length is not possible 
        if (dp[i] == -1) 
            continue; 
  
        // if a segment of p is possible 
        if (i + p <= l) 
            dp[i + p] = max(dp[i + p], dp[i] + 1); 
  
        // if a segment of q is possible 
        if (i + q <= l) 
            dp[i + q] = max(dp[i + q], dp[i] + 1); 
  
        // if a segment of r is possible 
        if (i + r <= l) 
            dp[i + r] = max(dp[i + r], dp[i] + 1); 
    } 
  
    // return value corresponding to length l 
    return dp[l]; 
} 
  
