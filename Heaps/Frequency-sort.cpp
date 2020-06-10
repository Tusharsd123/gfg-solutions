#include<bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int> a(n);
	    for(int i = 0;i<n;i++)
	        cin>>a[i];
	    unordered_map<int,int> mp;
	    for(int i = 0;i<n;i++)
	         mp[a[i]]++;
	    unordered_map<int,int>::iterator it;   
	    priority_queue<pair<int,int>> pq;
	    for(it = mp.begin();it!=mp.end();it++)
	    {
	        pq.push({it->second,it->first});
	    }
	    while(!pq.empty())
	    {
	        int k = pq.top().first;
	        int num = pq.top().second;
	        for(int i = 0;i<k;i++)
	        {
	            cout<<num<<" ";
	        }
	        pq.pop();
	    }
	    cout<<endl;
	}
	return 0;
}
