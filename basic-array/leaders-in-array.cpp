#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	long long t;
	cin>>t;
	while(t--)
	{
	    long long n,max=INT_MIN;
	    cin>>n;
	    long long a[n],b[n],count=0;
	    for(long long i=0;i<n;i++)
	    cin>>a[i];
	    for(long long i=n-1;i>=0;i--)
	    if(a[i]>=max)     //taking the largest elements from the back of array and storing then in new array.
	    {
	        max=a[i];
	        b[count]=a[i];
	        count++;
	    }
	    for(long long i=count-1;i>=0;i--)  //to output the leaders in ascending manner.
	    cout<<b[i]<<" ";
	    
	    cout<<endl;  
	}
	return 0;
}
