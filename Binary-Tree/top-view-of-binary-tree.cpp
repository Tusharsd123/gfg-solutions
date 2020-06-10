void topView(struct Node *root)
{
    map<int,int> mp;
    queue<pair<Node*,int>> q;
    q.push(make_pair(root,0));
    while(!q.empty())
    {
        pair<Node*,int> curr = q.front();
        q.pop();
        if(mp.find(curr.second)==mp.end())
        {
            mp[curr.second] = curr.first->data;
        }
        if(curr.first->left)
        q.push(make_pair(curr.first->left,curr.second-1));
        if(curr.first->right)
        q.push(make_pair(curr.first->right,curr.second+1));
    }
    auto p=mp.begin();
    while(p!=mp.end())
    {
        cout<<p->second<<" ";
        p++;
    }
}
