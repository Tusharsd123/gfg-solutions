//T.C - O(n) and S.C-O(n) solution is based on hashmap

#include <bits/stdc++.h>
using namespace std;
int main() {
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i = 0;i<n;i++)
           cin>>arr[i];
        unordered_map<int,int> mp;
        for(int i = 0;i<n;i++)
           mp[arr[i]]++;
        int x,y;   
        for(int i=1;i<=n;i++)
        {
            if(mp[i]>1)
              x=i;
            if(mp[i]==0)
              y=i;
        }
        cout<<x<<" "<<y<<endl;
    }
    
	return 0;
}

//for constant space solution lets use a index based approach.
//Traverse the array. While traversing, use the absolute value of every element as an index
//and make the value at this index as negative to mark it visited. 
//If something is already marked negative then this is the repeating element. 
//To find missing, traverse the array again and look for a positive value.


//the motive of the solution is that value of array is used as its own indices and all the values
//of the array are made negative. If a non visited value comes out to be negative than thats the repeating element.

void printTwoElements(int arr[], int size) 
{ 
    int i; 
    cout << " The repeating element is "; 
  
    for (i = 0; i < size; i++) { 
        if (arr[abs(arr[i]) - 1] > 0) 
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1]; 
        else
            cout << abs(arr[i]) << "\n"; 
    } 
  
    cout << "and the missing element is "; 
    for (i = 0; i < size; i++) { 
        if (arr[i] > 0) 
            cout << (i + 1); 
    } 
} 
