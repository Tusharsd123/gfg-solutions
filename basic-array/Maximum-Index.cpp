//maximise (j-i) subjected to constraint arr[i]<=arr[j];

//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//To solve this problem, we need to get two optimum indexes of arr[]: left index i and right index j. 
//For an element arr[i], we do not need to consider arr[i] for left index if there is an element smaller 
//than arr[i] on left side of arr[i]. Similarly, if there is a greater element on right side of arr[j] then 
//we do not need to consider this j for right index. So we construct two auxiliary arrays LMin[] and RMax[] 
//such that LMin[i] holds the smallest element on left side of arr[i] including arr[i], and RMax[j] holds the
//greatest element on right side of arr[j] including arr[j]. After constructing these two auxiliary arrays, we 
//traverse both of these arrays from left to right. While traversing LMin[] and RMa[] if we see that LMin[i] 
//is greater than RMax[j], then we must move ahead in LMin[] (or do i++) because all elements on left of LMin[i] 
//are greater than or equal to LMin[i]. Otherwise we must move ahead in RMax[j] to look for a greater j – i value.


//T.C - o(n)
//S.C - o(n)

#include <bits/stdc++.h>
using namespace std;

int main() {
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       int a[n];
       for(int i = 0;i<n;i++)
           cin>>a[i];
        int left[n],right[n];
        left[0] = a[0];
        for(int i = 1;i<n;i++)
            left[i] = min(a[i],left[i-1]);   //left array comprising of the minimums
        right[n-1] = a[n-1];
        for(int j = n-2;j>=0;j--)
            right[j] = max(a[j],right[j+1]);   //right array comprising of the maximums.
        int i = 0,j=0;
        int max_diff = -1;
        while(i<n && j<n)
        {
            if(left[i]<=right[j])
              {
                  max_diff = max(max_diff,j-i);
                  j++;
              }
              else
              {
                  i++;
              }
        }
        
        cout<<max_diff<<endl;
   }
	return 0;
}
