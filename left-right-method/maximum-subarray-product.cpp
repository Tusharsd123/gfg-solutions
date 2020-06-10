#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i,j;
 
	    cin>>n;
	    int a[n];
	    for(i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    int left[n+1];
	    int right[n+1];
	        left[0]=a[0];
	        right[n-1] = a[n-1];
	    for(i=1,j=n-2;i<n && j>=0;i++,j--)
	    {
	        if(left[i-1] !=0 && a[i]!=0)
	        {
	            left[i] = left[i-1]*a[i];
	        }
	        else
	        if(left[i-1]==0 && a[i]!=0)
	        {
	            left[i] = a[i];
	        }
	        else
	        {
	            left[i]=0;
	        }
	        if(right[j+1] !=0 && a[j]!=0)
	        {
	            right[j] = right[j+1]*a[j];
	        }
	        else
	        if(right[j+1]==0 && a[j]!=0)
	        {
	            right[j] = a[j];
	        }
	        else
	        {
	            right[j]=0;
	        }
	    }
	   
	    int mx = INT_MIN;
	    for(i=0;i<n;i++)
	    {
	        mx = max(mx ,max(right[i],left[i]));
	    }
	    cout<<mx<<endl;
	}
	return 0;
}


//another approach

int maxProduct(vector<int>& a) {
        if (a.size() == 0) return 0;
        int ans = INT_MIN, minNeg = 1, maxPos = 1;

        for (int i : a) {
            int mp = maxPos;
            maxPos = max({i, minNeg * i, maxPos * i});
            minNeg = min({i, mp * i, minNeg * i});
            ans = max(ans, maxPos);
        }

        return ans;
        
    }
