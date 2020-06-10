#include <bits/stdc++.h>
using namespace std;

long gcd(long a,long b){  //GCD using euclid algo
    if(a==0)
    return b;
    else
    return gcd(b%a,a);
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    long a,b;
	    cin>>a>>b;
	    long hcf=gcd(a,b);
	    long lcm=(a*b)/hcf;
	    cout<<lcm<<" "<<hcf<<endl;
	}
	return 0;
}
