//BFS or the breadth first search traversal is same as the level order traversal in the tree but it becomes
//a bit different in graphs because we can cycles in a graph so eventually we acn traverse the same vertex again
//and again. So we use a visited array here to keep the track of vertices.

void bfs(int s, vector<int> adj[], bool vis[], int N)
{
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while(!q.empty())
    {
        int node = q.front();
        cout<<node<<" ";
        q.pop();
        for(auto i : adj[node])
        {
            if(!vis[i])
            {
                vis[i] = true;
                q.push(i);
            }
        }
    }
    
}
