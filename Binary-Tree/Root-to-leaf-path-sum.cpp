//if(node == NULL || sum ==0)//this line will only execute if we reach at any end of some leaf node without sum being zero 
//OR sum became 0 at non leaf node..
//if(!node->right && !node ->left) return (sum - node->data == 0)
//it checks whether this is leaf node and if yes then check whether sum here is 0...if 0 then path is found whose cumulative sum == sum.
//return (hasPathSum(node->left,sum - node->data) || hasPathSum(node->right ,sum - node->data)
//this is further recursion going down on both ends until we either we get to leaf or sum becomes zero or to the end of branch...

bool hasPathSum(Node *root, int sum)
{
   if(root==NULL || sum==0)
            return 0;
   if(!root->left && !root->right) 
         return (sum-root->data == 0);
   
   return( hasPathSum(root->left,sum-root->data)|| hasPathSum(root->right,sum-root->data) );
   
}

//Time-complexity is O(n)
