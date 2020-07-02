#include <iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

void distinct(string s)
{
	int arr[26]; 
    memset(arr,-1,sizeof(arr));
    int start=0;
    int end=0;
    int max1=1;
    for(int i=0;i<s.size();i++)
    {
        if(arr[s[i]-'a']==-1)
        {
            arr[s[i]-'a']=i;
            end++;
        }
        else 
        {
            if(arr[s[i]-'a']<start)
            {
                 arr[s[i]-'a']=i;
                 end++;
            }
            else
            {
                start=arr[s[i]-'a']+1;
                arr[s[i]-'a']=i;
                end++;
                
            }
        }
        max1=max(max1,(end-start));
    }
     cout<<max1<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	string s;
    	cin>>s;
    	distinct(s);
    }
 return 0;   
}    
    
