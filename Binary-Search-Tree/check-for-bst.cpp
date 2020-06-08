//For each node, check if max value in left subtree is smaller than the node and min value in right subtree greater than the node.
//ineficient 
//This Method above runs slowly since it traverses over some parts of the tree many times
int isBST(struct node* node)  
{  
  if (node == NULL)  
    return 1;  
      
  /* false if the max of the left is > than us */
  if (node->left!=NULL && maxValue(node->left) > node->data)  
    return 0;  
      
  /* false if the min of the right is <= than us */
  if (node->right!=NULL && minValue(node->right) < node->data)  
    return 0;  
    
  /* false if, recursively, the left or right is not a BST */
  if (!isBST(node->left) || !isBST(node->right))  
    return 0;  
      
  /* passing all that, it's a BST */
  return 1;  
}  

//more efficient method

int isBST(node* node)  
{  
    return(isBSTUtil(node, INT_MIN, INT_MAX));  
}  
  
/* Returns true if the given 
tree is a BST and its values 
are >= min and <= max. */
int isBSTUtil(node* node, int min, int max)  
{  
    /* an empty tree is BST */
    if (node==NULL)  
        return 1;  
              
    /* false if this node violates 
    the min/max constraint */
    if (node->data < min || node->data > max)  
        return 0;  
      
    /* otherwise check the subtrees recursively,  
    tightening the min or max constraint */
    return
        isBSTUtil(node->left, min, node->data-1) && // Allow only distinct values  
        isBSTUtil(node->right, node->data+1, max); // Allow only distinct values  
}  

//inorder traversal approach
//inorder traversal gives a sorted array. Comparing the elements for their previous node helps here to solve the problem.
bool isBST(node* root)  
{  
    static node *prev = NULL;  //made static so that the function can retain that value.
      
    // traverse the tree in inorder fashion  
    // and keep track of prev node  
    if (root)  
    {  
        if (!isBST(root->left))  
        return false;  
  
        // Allows only distinct valued nodes  
        if (prev != NULL &&  
            root->data <= prev->data)  
        return false;  
  
        prev = root;  
  
        return isBST(root->right);  
    }  
  
    return true;  
}  
