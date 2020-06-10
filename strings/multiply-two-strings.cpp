string multiplyStrings(string s1, string s2) {
 vector<string> ans;
long long int res1=0,res2=0,m=0,n=0;
   long long int sign=1;
        if(s1[0]=='-' && s2[0]=='-') 
      {
          sign = 1;
          s2.erase(s2.begin());
          s1.erase(s1.begin());
          
      }
      
      if(s1[0]=='-' && s2[0]!='-' )
      {
      	sign = -1;
      	s1.erase(s1.begin());
      }
      
      if(s2[0]=='-' && s1[0]!='-')
      {
      	sign = -1;
      	s2.erase(s2.begin());
      }
         
for(int i=s1.length()-1;i>=0;i--)
{
int n1=s1[i]-'0';
res1=res1 + n1*(pow(10,m));
m++;
}
for(int j=s2.length()-1;j>=0;j--)
{
int n2=s2[j]-'0';
res2=res2 + n2*(pow(10,n));
n++;
}

string s ="";
s += res1*res2;
if (sign == -1)
        s.insert(s.begin(), '-');
        
        
return s;        
        
        
}
