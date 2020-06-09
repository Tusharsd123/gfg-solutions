//A dp based O(n^2) approach is used totally based on LIS

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; 
	cin>>t;
	while(t--) 
	{
	    int n; 
	    cin>>n; 
	    int a[n],dp[n];
	    for(int i=0;i<n;i++)
	     {   
	         cin>>a[i];
	         dp[i]=a[i];
	         
	     }
	         int ans=dp[0];
	   for(int i=1;i<n;i++)
	   {
	    for(int j=0;j<i;j++)
	    {    
	        if(a[j]<a[i])
	            dp[i]=max(dp[i],dp[j]+a[i]);
	        if(ans<dp[i])
	              ans=dp[i];
	   }
	  }     
	   cout<<ans<<"\n";   
	}
	return 0;
}
