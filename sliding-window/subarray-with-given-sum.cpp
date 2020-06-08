#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
       int n,s;
       cin>>n>>s;
       int arr[n];
       for(int i = 0;i<n;i++)
           cin>>arr[i];
       int sum  = 0;
       int j = 0;
       int flag=-1;
       for(int i = 0;i<n;i++)
       {
           sum += arr[i];
           if(sum>s)
           {
               sum = sum - arr[j];
               j++;
           }
           if(sum==s)
           {
               cout<<j+1<<" "<<i+1<<endl;
               flag=1;
           }
       }
       if(flag==-1)
       cout<<"-1"<<endl;
    }
}
