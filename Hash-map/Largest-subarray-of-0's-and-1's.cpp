int maxLen(int arr[], int n) {
    
    for(int i = 0;i<n;i++)
       {
           if(arr[i]==0)
               arr[i] = -1;
               
       }
       
       int sum = 0;
       int max_len =0;
       map<int,int> st;
       for(int i = 0;i<n;i++)
       {
           sum += arr[i];
           
           if(arr[i]==0 && max_len==0 )
              max_len = 1;
              
            if(sum==0)
               max_len = i + 1;
               
            if(st.find(sum) != st.end())
              max_len = max(max_len,i-st[sum]);
              
            else
              st[sum] = i;
       }
       
       
       return max_len;
}
