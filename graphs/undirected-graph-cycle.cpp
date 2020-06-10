//Time Complexity: O(V+E).
//The program does a simple DFS Traversal of the graph which is represented using adjacency list. So the time complexity is O(V+E).
//pace Complexity: O(V).
//To store the visited array O(V) space is required.

//the main condition is that if the node is visited and its not the parent of the given node then it proves
//that the graph has an cycle.

bool dfs(int i,bool visited[] , vector<int> adj[], int prev ){
    
    visited[i]=1;
    
    for(auto it=adj[i].begin();it!=adj[i].end();it++){
         if(!visited[*it]){
            if(dfs(*it,visited,adj,i))
                return true;    
        }
        else if((*it!=prev)) return true;
    }
  
    return false;
}

bool isCyclic(vector<int> adj[],int v){
  
  bool  visited[v];
  memset(visited,0,sizeof(visited));
  for(int i=0;i<v;i++){
      if(!visited[i] && dfs(i,visited,adj,-1)) return 1;
  }
  return false;
}
