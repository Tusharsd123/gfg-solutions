#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>>n>>k;
	    int x;
	    priority_queue<int> pq;
	    for(int i=0;i<n;i++)
	     {cin>>x; pq.push(x);}

	    while(k--)
	    { cout<<pq.top()<<" "; pq.pop(); }
	    
	    cout<<endl; 
	}
	return 0;
}
