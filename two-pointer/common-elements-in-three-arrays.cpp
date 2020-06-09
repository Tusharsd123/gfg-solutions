//to avoid printing duplicate common elements we use hashmaps. Since all arrays are sorted so we can use a 
//two pointer technique

#include <bits/stdc++.h>
using namespace std;
int min(int x,int y)
{
    return x>y?y:x;
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    unordered_map<int,int> mp;
	    int n1,n2,n3;
	    cin>>n1>>n2>>n3;
	    int a[n1],b[n2],c[n3];
	    for(int i = 0;i<n1;i++)
	    {
	        cin>>a[i];
	    }
	    for(int i = 0;i<n2;i++)
	    {
	        cin>>b[i];
	    }
	    for(int i = 0;i<n3;i++)
	    {
	        cin>>c[i];
	    }
	    int ans = 0;
	    int a_start=0;
	    int b_start=0;
	    int c_start=0;
	    while(a_start<n1 && b_start<n2 && c_start<n3)
	    {
	        if(min(c[c_start],min(a[a_start],b[b_start]))==c[c_start])
	            c_start++;
	       if(min(a[a_start],min(c[c_start],b[b_start]))==a[a_start])  
	           a_start++;
	       if(min(b[b_start],min(a[a_start],c[c_start]))==b[b_start])
	            b_start++;
	       if(a[a_start]==b[b_start] && b[b_start]==c[c_start])
	            { if(mp.find(a[a_start])!=mp.end())
	                   {  cout<<ans<<" ";
	                      mp[a[a_start]]++;
	                   }
	            }        
	    }
	}
	return 0;
}
