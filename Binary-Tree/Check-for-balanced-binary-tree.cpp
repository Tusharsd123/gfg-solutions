int max(int a,int b);
int height(Node* root);
// This function should return tree if passed  tree 
// is balanced, else false. 
bool isBalanced(Node *root)
{
    int lh,rh;
    
    if(root==NULL)
       return 1;
       
    lh = height(root->left);
    rh = height(root->right);
    
    if(abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right))
       return 1;
    else   
      return 0;   
}


int height(Node* root)
{
    if(root==NULL)
       return 0;
       
    else
    
    {
        return 1 + max(height(root->left),height(root->right));
    }
}

int max(int a,int b)
{
    return a>=b?a:b;
}
