

void printSibling(Node* node)
{
  if(node==NULL) 
       return;
  queue<Node*> q;
  q.push(node);
  vector<int> v;
  while(!q.empty())
  {
     Node* t = q.front();
     q.pop();
  if(t->left==NULL || t->right==NULL) //if left or right child is null
  {
  if(t->left) 
      v.push_back(t->left->data);
  else if(t->right) 
      v.push_back(t->right->data);
  }
 if(t->left) 
      q.push(t->left);
 if(t->right) 
      q.push(t->right);
 }
 if(v.size()==0) cout<<-1;
 else {
 sort(v.begin(), v.end());
 for(auto u: v){
 cout<<u<<" ";
 }
}
}
