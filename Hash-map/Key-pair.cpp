//Given an array A of N positive integers and another number X.
//Determine whether or not there exist two elements in A whose sum is exactly X.

//T.C - O(nlogn)
//S.C - O(1)

#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int x;
        cin>>x;
        vector<int> a(n);
        for(int i = 0;i<n;i++)
           cin>>a[i];
        sort(a.begin(),a.end());
        int start = 0;
        int end = n-1;
        int flag = -1;
        while(start<=end)
        {
            if(a[start]+a[end]==x)
              { cout<<"Yes"<<endl;;
                 flag = 1;
              }
            if(a[start]+a[end]<x)
               start++;
            if(a[start]+a[end]>x)
               end--;
        }
        if(flag==-1)
           cout<<"No"<<endl;
    }
	return 0;
}

//using set we can decrease the time complexity to O(n)

void printPairs(int arr[], int arr_size, int sum) 
{ 
    unordered_set<int> s; 
    for (int i = 0; i < arr_size; i++) { 
        int temp = sum - arr[i]; 
  
        if (s.find(temp) != s.end()) 
            cout << "Pair with given sum "
                 << sum << " is ( 
                           " << arr[i] << ", 
                "  
                    << temp << ")" << endl; 
  
        s.insert(arr[i]); 
    } 
} 
