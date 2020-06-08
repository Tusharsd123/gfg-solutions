//memoised dp sol

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int min(int x, int y, int z) 
{ 
   return min(min(x, y), z); 
} 
int editDist(string str1 , string str2 , int m ,int n,int dp[][5000]) 
{ 
    
    if (m == 0) return n; 
  
   
    if (n == 0) return m; 
  
 
    if (str1[m-1] == str2[n-1]) 
        return editDist(str1, str2, m-1, n-1,dp); 
  if(dp[m][n]!=0)
  return dp[m][n];
  else
  {
       dp[m][n]= 1 + min ( editDist(str1,  str2, m, n-1,dp),    
                     editDist(str1,  str2, m-1, n,dp), 
                     editDist(str1,  str2, m-1, n-1,dp)
                   ); 
      return dp[m][n];
  }
 
   
} 
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n;
	    cin>>m;
	    char a[n],b[m];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    for(int i=0;i<m;i++)
	    cin>>b[i];
	    int dp[n+1][5000];
	    memset(dp,0,sizeof(dp));
	    dp[0][0]=1;
	    cout<<editDist(a,b,n,m,dp)<<endl;
	    
	    
	    
	}
	return 0;
}

//top-down dp approach

int editDistDP(string str1, string str2, int m, int n) 
{ 
    // Create a table to store results of subproblems 
    int dp[m + 1][n + 1]; 
  
    // Fill d[][] in bottom up manner 
    for (int i = 0; i <= m; i++) { 
        for (int j = 0; j <= n; j++) { 
            // If first string is empty, only option is to 
            // insert all characters of second string 
            if (i == 0) 
                dp[i][j] = j; // Min. operations = j 
  
            // If second string is empty, only option is to 
            // remove all characters of second string 
            else if (j == 0) 
                dp[i][j] = i; // Min. operations = i 
  
            // If last characters are same, ignore last char 
            // and recur for remaining string 
            else if (str1[i - 1] == str2[j - 1]) 
                dp[i][j] = dp[i - 1][j - 1]; 
  
            // If the last character is different, consider all 
            // possibilities and find the minimum 
            else
                dp[i][j] = 1 + min(dp[i][j - 1], // Insert 
                                   dp[i - 1][j], // Remove 
                                   dp[i - 1][j - 1]); // Replace 
        } 
    } 
  
    return dp[m][n]; 
} 
