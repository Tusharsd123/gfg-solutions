//T.C - (O(log(n)))
//auxilary space = O(1)


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define f(i,n) for(int i=0; i<n; i++)
int FindPivotIndex(int arr[] , int n){
    int left = 0;
    int right = n-1,mid;
        
        while(left <= right){
            
            mid = left -(left-right)/2;
            
            if(arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1])
                return mid;
            
            else if(arr[mid] < arr[mid+1]){
                left = mid+1;
            }
            else if(arr[mid-1] > arr[mid]){
                right = mid-1;
            }
        }
        return (right == 0 ? 0 : INT_MAX); //again most important shit
}

int AscendingOrderSearch(int arr[] , int left,int right ,int target){
    int  mid;
    while(left<= right){
        mid = (left +right)/2;
        
        if(arr[mid] == target) return mid;
        else if(arr[mid] < target) left = mid+1;
        else right = mid-1;
    }
    return -1;
}


int DescendingOrderSearch(int arr[] , int left,int right, int target){
    int  mid;
    while(left<= right){
        mid = (left +right)/2;
        
        if(arr[mid] == target) return mid;
        else if(arr[mid] < target) right = mid-1;
        else left = mid+1;
    }
    return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,target;
		cin>>n;
		int arr[n];
		f(m,n) {
			cin>>arr[m];
		}
		cin>>target;
		int pivot = FindPivotIndex( arr ,  n);
		//cout<<"pivot "<<pivot<<endl;
		switch(pivot) {
		  case 0:{
		      //important shit when first element comes out to be pivot point.
		     cout<<DescendingOrderSearch(arr , 0,n-1, target)<<endl ;
		     break;
		  } //here last element comes out to be the pivot point
		  case INT_MAX:{
		      cout<<AscendingOrderSearch(arr , 0,n-1, target)<<endl ;
		      break;
		  }
		  default :{
		      int index = AscendingOrderSearch(arr , 0,pivot, target) ;
		      //cout<<"index "<<index<<endl;
		      if(index != -1){
		          cout<<index<<endl;
		      }else {
		          cout<<DescendingOrderSearch(arr , pivot,n-1, target)<<endl;
		      }
		  }
		}
		
 	}
	 return 0;
}
