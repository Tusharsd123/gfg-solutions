#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> v;
		for(int i =0;i<n;i++)
		{
			string s;
			cin>>s;
			v.push_back(s);
		}
		
		sort(v.begin(),v.end());
		string a = v[0];
		string b = v[v.size() - 1];
		int i =0;
		while(a[i]==b[i])
		{
			i++;
		}
		
		if(i==0)
		   cout<<"-1"<<endl;
		   
		if(i)
		   cout<<a.substr(0,i)<<endl;
	}
}
