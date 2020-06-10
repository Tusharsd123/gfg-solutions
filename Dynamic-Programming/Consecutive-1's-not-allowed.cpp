//a[] comprises of those stringd ending with 0;
//b[] comprises of those strings ending with 1;

#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n],b[n];
	    a[0]=b[0]=1;
	    for(int i = 1;i<n;i++)
	    {
	        a[i]=(a[i-1]+b[i-1])%1000000007;
	        b[i] = a[i-1];
	    }
	    
	     cout<<(a[n-1]+b[n-1])%1000000007<<endl;
	}
	return 0;
}
