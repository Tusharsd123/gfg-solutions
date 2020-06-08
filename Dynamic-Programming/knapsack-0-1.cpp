#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,W;
	    cin>>n>>W;
	    int val[n];
	    int wt[n];
	    for(int i = 0;i<n;i++)
	    {
	        cin>>val[i];
	    }
	    for(int i = 0;i<n;i++)
	    {
	        cin>>wt[i];
	    }
	    int dp[n+1][W+1];
	    memset(dp,0,sizeof(dp));
	    for(int i =1 ;i<=n;i++)
	    {
	        for(int j = 1;j<=W;j++)
	        {
	            if(wt[i-1]<=j)
	              dp[i][j] = max(dp[i-1][j],dp[i-1][j-wt[i-1]]+val[i-1]);
	            else
	               dp[i][j] = dp[i-1][j];
	        }
	    }
	    
	    cout<<dp[n][W]<<endl;
	}
	return 0;
}
