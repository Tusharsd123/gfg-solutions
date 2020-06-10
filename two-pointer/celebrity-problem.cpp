//two pointer approach 
//T.C - O(n)
//S.C - O(1)

int getId(int M[MAX][MAX], int n)
{
    int start = 0;
    int end = n-1;
    while(start<end)
    {
        if(M[start][end]==1)
           start++;
        else
            end--;
    }
    
    //checking if start is the real celebrity according to the problem or not
    for(int i = 0;i<n;i++)
    {
        if((i!=start)&& (M[start][i]==1||(M[i][start]==0)))
           return -1;
    }
    
    return start;
}

//graph based indegree and outdegree approach is also there 
//T.C - O(n^2)
//S.C - O(n)

int findCelebrity(int n) 
{ 
    //the graph needs not be constructed 
    //as the edges can be found by 
    //using knows function 
      
    //degree array; 
    int indegree[n]={0},outdegree[n]={0}; 
      
    //query for all edges 
    for(int i=0; i<n; i++) 
    { 
        for(int j=0; j<n; j++) 
        { 
            int x = knows(i,j); 
              
            //set the degrees 
            outdegree[i]+=x; 
            indegree[j]+=x; 
        } 
    } 
      
    //find a person with indegree n-1 
    //and out degree 0 
    for(int i=0; i<n; i++) 
    if(indegree[i] == n-1 && outdegree[i] == 0) 
        return i; 
      
    return -1; 
} 
