//Brute force o(n^2) approach checking for each element to be the equillibrium point.
int equilibrium(int arr[], int n) 
{ 
    int i, j; 
    int leftsum, rightsum; 
  
    /* Check for indexes one by one until  
    an equilibrium index is found */
    for (i = 0; i < n; ++i)  
    {      
  
        /* get left sum */
        leftsum = 0;  
        for (j = 0; j < i; j++) 
            leftsum += arr[j]; 
  
        /* get right sum */
        rightsum = 0;  
        for (j = i + 1; j < n; j++) 
            rightsum += arr[j]; 
  
        /* if leftsum and rightsum   
        are same, then we are done */
        if (leftsum == rightsum) 
            return i; 
    } 
  
    /* return -1 if no equilibrium  
    index is found */
    return -1; 
} 



//optimised approach o(nlogn) using binary search

#include<bits/stdc++.h>
using namespace std;

int sum_util(int *a,int start,int end)
{
    long long sum = 0;
    for(int i = start;i<=end;i++)
    {
        sum += a[i];
    }
    return sum;
}

int binary_search(int *a,int start,int end,int n)
{
    while(start<=end)
    {
        int mid = start+(end-start)/2;
        if(sum_util(a,0,mid-1)==sum_util(a,mid+1,n-1))
           return mid+1;
        else if(sum_util(a,0,mid-1)>sum_util(a,mid+1,n-1))
           end = mid - 1;
        else
           start = mid+1;
    }
    return -1;
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
        cout<<binary_search(a,0,n-1,n)<<endl;
    }
}

//optimised (tricky) approach to o(n)

int equilibrium(int arr[], int n)  
{  
    int sum = 0; // initialize sum of whole array  
    int leftsum = 0; // initialize leftsum  
  
    /* Find sum of the whole array */
    for (int i = 0; i < n; ++i)  
        sum += arr[i];  
  
    for (int i = 0; i < n; ++i)  
    {  
        sum -= arr[i]; // sum is now right sum for index i  
  
        if (leftsum == sum)  
            return i;  
  
        leftsum += arr[i];  
    }  
  
    /* If no equilibrium index found, then return 0 */
    return -1;  
}  

