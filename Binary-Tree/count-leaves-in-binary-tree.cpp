int countLeaves(Node* root)
{
  if(root==NULL)
      return 0;
      
  if(root->left==0 && root->right==0)
     return 1;
     
  return countLeaves(root->left)+countLeaves(root->right);     
}
