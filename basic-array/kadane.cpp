#include<bits/stdc++.h>
using namespace std;
int maxsubarray(int a[],int size)
{
    int max_so_far = a[0];
    int curr_max = a[0];
    for(int i = 1;i<size;i++)
    {
        curr_max = max(a[i],curr_max+a[i]);
        max_so_far = max(curr_max,max_so_far);
    }
    
    return max_so_far;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i = 0;i<n;i++)
           cin>>a[i];
           
        cout<<maxsubarray(a,n)<<endl;   
    }
}
