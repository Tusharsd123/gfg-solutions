#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int chk(char x){
    if(x-'0'>=0 && x-'0'<=9)    return 1;
    if(x-'a'>=0 && x-'a'<26)    return 2;
    if(x-'A'>=0 && x-'A'<26)    return 3;
    return 0;
}

int main()
 {
	int t;
	cin>>t;
	char cc;
    cc = getchar();
	while(t--){
	    int n,i=0,j;
	    string s;
	    getline(cin,s);
	    n=s.length();
	    j=n-1;
	    while(i<j){
	        if(chk(s[j])==0)    j--;
	        else if(chk(s[i])==0)   i++;
	        else{
	            if(s[i]==s[j])  {i++;j--;continue;}
	            if(chk(s[j])==2 && chk(s[i])==3){
	                if(s[j]-'a'==s[i]-'A')  {i++;j--;continue;}
	                else    break;
	            }
	            if(chk(s[j])==3 && chk(s[i])==2){
	                if(s[j]-'A'==s[i]-'a')  {i++;j--;continue;}
	                else    break;
	            }
	            break;
	        }
	    }
	    if(i>=j)    cout<<"YES"<<endl;
	    else    cout<<"NO"<<endl;
	}
}
