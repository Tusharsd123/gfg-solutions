//Rahul and Ankit are the only two waiters in Royal Restaurant. 
//Today, the restaurant received N orders. The amount of tips may differ when handled by different waiters, 
//if Rahul takes the ith order, he would be tipped Ai rupees and if Ankit takes this order, the tip would be Bi rupees.
//In order to maximize the total tip value they decided to distribute the order among themselves. One order will be handled
//by one person only. Also, due to time constraints Rahul cannot take more than X orders and Ankit cannot take more than Y orders.
//It is guaranteed that X + Y is greater than or equal to N, which means that all the orders can be handled by either Rahul or Ankit. 
//Find out the maximum possible amount of total tip money after processing all the orders.



#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> x,pair<int,int> y)
{
	return (fabs(x.first-x.second)>fabs(y.first-y.second));
}

int main()
{
	int t; cin>>t;
	while(t--)
	{
	int n,x,y;
	cin>>n>>x>>y;
	vector<pair<int,int> >a(n);
	for(int i =0;i<n;i++)
	   cin>>a[i].first;
	   
	for(int i =0;i<n;i++)
	   cin>>a[i].second;
	   
	   sort(a.begin(),a.end(),compare);
	   
	   int ans = 0;
	   
	   for(int i =0;i<n;i++)
	   {
	   	if(x>0 && ((a[i].first>=a[i].second)||y==0))
	   	{
	   		ans += a[i].first;
	   		x--;
	   	}
	   	
	   	else if(y>0 && ((a[i].second>=a[i].first)||x==0))
	   	{
	   		ans += a[i].second;
	   		y--;
	   	}
	   }
	   
	   cout<<ans<<endl;
	}
}
