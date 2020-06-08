#include<bits/stdc++.h>
using namespace std;
int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	     for(int i =0;i<n-1;i++)
	     {
	         cin>>a[i];
	     }      
	    int sum_arr = 0;
	    int sum = (n*(n+1))/2;
	    
	    for(int i = 0;i<n-1;i++)
	       sum_arr += a[i];
	       
	    cout<<sum - sum_arr<<endl;    
	    
	}
	return 0;
}
