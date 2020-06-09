//Given an unsorted array of size N. Find the first element in array such that all of its left elements are smaller
//and all right elements to it are greater than it.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int Elements(vector < int > v,int n)
{
    vector < int > left(n,0),right(n,0);
    
    int maxi=v[0];
    for(int i=1;i<n-1;i++)
     {
         maxi=max(maxi,v[i]);
         left[i]=maxi;
     }
     
    int mini=v[n-1];
    for(int i=n-2;i>0;i--)
     {
         mini=min(mini,v[i]);
         right[i]=mini;
     }
     
     
    for(int i=1;i<left.size()-1;i++)
     if(left[i]==right[i])
      return left[i];
    
    return -1;
}

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        vector < int > v(n);
        for(int i=0;i<n;i++)
         cin>>v[i];
        
        cout<<Elements(v,n)<<endl;
        
    }

  
  return 0;
  
}
