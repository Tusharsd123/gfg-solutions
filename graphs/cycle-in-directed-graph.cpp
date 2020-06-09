//Detecting a cycle in a directed graph involves using depth first search where we explore the whole graph
//starting from a single vertex source and explore as deep as possible(till its neighbors become zero) and finally we backtrack

//Depth First Traversal can be used to detect a cycle in a Graph. DFS for a connected graph produces a tree. 
//There is a cycle in a graph only if there is a back edge present in the graph. 
//A back edge is an edge that is from a node to itself (self-loop) or one of its ancestors in the tree produced by DFS. 

//To detect a back edge, keep track of vertices currently in the recursion stack of function for DFS traversal. 
//If a vertex is reached that is already in the recursion stack, then there is a cycle in the tree. 
//The edge that connects the current vertex to the vertex in the recursion stack is a back edge.
//Use incallstack[] array to keep track of vertices in the recursion stack.

bool Cyclic(bool visited[],bool incallstack[],int V,vector<int> adj[],int i)
{
    visited[i]=true;
    incallstack[i]=true;
    for(int j=0;j<adj[i].size();j++)
    {
        if(!visited[adj[i][j]] && Cyclic(visited,incallstack,V,adj,adj[i][j]))
           return true;
        else if(incallstack[adj[i][j]]) //condition for self-loop or the back edge.
            return true;
    }
    incallstack[i]=false; //backtrack
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
   bool visited[V];
   bool incallstack[V];
   for(int i = 0;i<V;i++)
   {
       visited[i]=false;
       incallstack[i]=false;
   }
   for(int i = 0;i<V;i++)
   {
       if(!visited[i])
          if(Cyclic(visited,incallstack,V,adj,i))
             return true;
   }
   return false;
}


//Time complexity is O(V+E)
//Space complexity is O(V)
