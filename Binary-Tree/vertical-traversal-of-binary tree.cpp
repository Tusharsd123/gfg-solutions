void verticalOrder(Node *root)
{
    if(root==NULL)
       return;
    map<int,vector<int>> mp;
    int hd=0;
    queue<pair<Node*,int>> q;
    q.push(make_pair(root,hd));
    while(!q.empty())
    {
        pair<Node*,int> temp = q.front();
        q.pop();
        hd = temp.second;
        Node* node = temp.first;
        mp[hd].push_back(node->data);
        if(node->left!=NULL)
        {
            q.push(make_pair(node->left,hd-1));
        }
        if(node->right!=NULL)
        {
            q.push(make_pair(node->right,hd+1));
        }
    }
    
    map<int,vector<int>>::iterator it;
    for(it=mp.begin();it!=mp.end();it++)
    {
        for(int i = 0;i<it->second.size();i++)
        {
            cout<<it->second[i]<<" ";
        }
    }
    
}

