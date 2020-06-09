//We have been provided with two unsorted arrays and we need to find a pair that sums to a given target.

#include<bits/stdc++.h>
using namespace std;
int main(){
    int test;
    cin>>test;
    while(test-- > 0){
        int m,n,x;
        cin>>m>>n>>x;
        int a[m],b[n];
        for(int i=0;i<m;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            cin>>b[i];
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            st.insert(b[i]);
        }
        int flag=0;
        for(int i=0;i<m;i++){
            int dif=x-a[i];
            if(st.find(dif)!=st.end()){
                if(flag==1) cout<<", ";
                cout<<a[i]<<" "<<dif;
                flag=1;
            }
        }
        if(flag==0) cout<<-1;
        cout<<endl;
    }
}
