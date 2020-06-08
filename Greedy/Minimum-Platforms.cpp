//Minimum platforms needed given the arrival and departure time of the trains.
//Brute Force approach checks for overlapping arrival and departure times.
//O(n^2)

int findPlatform(int arr[], int dep[], int n) 
{ 
  
    // plat_needed indicates number of platforms 
    // needed at a time 
    int plat_needed = 1, result = 1; 
    int i = 1, j = 0; 
  
    // run a nested  loop to find overlap 
    for (int i = 0; i < n; i++) { 
        // minimum platform 
        plat_needed = 1; 
  
        for (int j = i + 1; j < n; j++) { 
            // check for overlap 
            if ((arr[i] >= arr[j] && arr[i] <= dep[j]) || (arr[j] >= arr[i] && arr[j] <= dep[i])) 
                plat_needed++; 
        } 
  
        // update result 
        result = max(result, plat_needed); 
    } 
  
    return result; 
} 

//The given approach can take o(nlogn) for heapsort or mergesort or it could take upto o(n^2) in worst case of quicksort.

#include<bits/stdc++.h>
using namespace std;
int main() {
	int t; cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    int b[n];
	    for(int i = 0;i<n;i++)
	         cin>>a[i];
	         
	    for(int i = 0;i<n;i++)
	        cin>>b[i];
	        
	       sort(a,a+n);
	       sort(b,b+n);
	       
	       int i = 1,j=0;
	       int plat = 1,result = 1;
	       while(i<n && j<n)
	       {
	           if(a[i]<=b[j])
	           {
	               plat++;
	               i++;
	               
	               if(plat>result)
	                  result = plat;
	           }
	           
	           else
	           {
	               plat--;
	               j++;
	           }
	           
	       }
	       
	       cout<<result<<endl;
	}
	return 0;
}


//o(n) based approach using a multimap
int findPlatform(int arr[], int dep[], int n) 
{ 
    // Insert all the times (arr. and dep.) 
    // in the multimap. 
    multimap<int, char> order; 
    for (int i = 0; i < n; i++) { 
  
        // If its arrival then second value 
        // of pair is 'a' else 'd' 
        order.insert(make_pair(arr[i], 'a')); 
        order.insert(make_pair(dep[i], 'd')); 
    } 
  
    int result = 0; 
    int plat_needed = 0; 
  
    multimap<int, char>::iterator it = order.begin(); 
  
    // Start iterating the multimap. 
    for (; it != order.end(); it++) { 
  
        // If its 'a' then add 1 to plat_needed 
        // else minus 1 from plat_needed. 
        if ((*it).second == 'a') 
            plat_needed++; 
        else
            plat_needed--; 
  
        if (plat_needed > result) 
            result = plat_needed; 
    } 
    return result; 
} 
