//Time complexity in worst case is O(n^2) in case of skewed trees.

int sum(struct node *root) 
{ 
   if(root == NULL) 
     return 0; 
   return sum(root->left) + root->data + sum(root->right); 
} 
  
/* returns 1 if sum property holds for the given 
    node and both of its children */
int isSumTree(struct node* node) 
{ 
    int ls, rs; 
  
    /* If node is NULL or it's a leaf node then 
       return true */
    if(node == NULL || 
            (node->left == NULL && node->right == NULL)) 
        return 1; 
  
   /* Get sum of nodes in left and right subtrees */
   ls = sum(node->left); 
   rs = sum(node->right); 
  
   /* if the node and both of its children satisfy the 
       property return 1 else 0*/
    if((node->data == ls + rs)&& 
            isSumTree(node->left) && 
            isSumTree(node->right)) 
        return 1; 
  
   return 0; 
} 
