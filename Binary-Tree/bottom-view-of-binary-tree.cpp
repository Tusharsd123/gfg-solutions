void printbottom(Node*root,int hd,int level,map<int,pair<int,int>> &mp)
{
    if(root==NULL)
       return;
    if(mp.find(hd)==mp.end())
    {
        mp[hd] = make_pair(root->data,level);
    }
    else
    {
        pair<int,int> p = mp[hd];
        if(p.second<=level)
        {
            mp[hd].second = level;
            mp[hd].first = root->data;
        }
    }
    printbottom(root->left,hd-1,level+1,mp);
    printbottom(root->right,hd+1,level+1,mp);
}

void bottomView(Node *root)
{
   map<int,pair<int,int>> mp;
   printbottom(root,0,0,mp);
   map<int,pair<int,int>>::iterator it;
   for(it=mp.begin();it!=mp.end();it++)
   {
       pair<int,int> p = it->second;
       cout<<p.first<<" ";
   }
}

