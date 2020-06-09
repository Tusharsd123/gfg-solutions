#include<bits/stdc++.h>
using namespace std;
  int main()
{
  int t;
  cin>>t;
  while(t--)
{
  int n,m,i,j,ans=-1;
  cin>>n>>m;
  string x,y;
  cin>>x>>y;
  int dp[n+1][m+1];
  for(i=0;i<=n;i++)
{
     for(j=0;j<=m;j++)
   {
         if(i==0||j==0)
              dp[i][j]=0;
         else if(x[i-1]==y[j-1])
              dp[i][j]=dp[i-1][j-1]+1;
         else 
             dp[i][j]=0;
         
         ans=max(ans,dp[i][j]);  //for substring max length can be anywhere.
     }
}
   cout<<ans<<endl; 
    
    
}

}
