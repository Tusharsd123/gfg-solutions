#include<iostream>
#include<string>
#include<iostream>
#include<string>
#include<string>
#include<algorithm>
using namespace std;
int main()
 {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
	  string s1,s2;
	  cin>>s1>>s2;
	  if(s1.size()==s2.size())
	  {
	  int c[26]={0};
	 for(int i=0;i<s1.size();i++)
	 c[s1[i]-'a']++;
	 for(int i=0;i<s2.size();i++)
	 c[s2[i]-'a']--;
	 if(count(c,c+26,0)==26)
	 cout<<"YES"<<endl;
	 else
	 cout<<"NO"<<endl;
	  }
	  else
	  cout<<"NO"<<endl;
	}
	return 0;
}

