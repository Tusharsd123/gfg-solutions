//* the diameter of T’s left subtree
//* the diameter of T’s right subtree
//* the longest path between leaves that goes through the root of T (this can be computed from the heights of the subtrees of T)

//T.C - O(n^2)

int height(struct Node* node);
  int max(int a, int b) 
{ 
  return (a >= b)? a: b; 
}    
  int diameter(struct Node* node)
  {
      if(node==NULL)
         return 0;
         
      int lheight = height(node->left);
      int rheight = height(node->right);
      
      int ldiameter = diameter(node->left);
      int rdiameter = diameter(node->right);
      
      return max(1+lheight+rheight,max(ldiameter,rdiameter));
  }
  
  int height(struct Node* node)
  {
      if(node==NULL)
         return 0;
         
      return (1+ max(height(node->left),height(node->right)));     
  }
  
  
  //A simpler O(n) approach is there
  //In this post a new simple O(n) method is discussed. Diameter of a tree can be calculated by only using the height function
  //because the diameter of a tree is nothing but maximum value of (left_height + right_height + 1) for each node.
  //So we need to calculate this value (left_height + right_height + 1) for each node and update the result. 
  
  //Time complexity – O(n)
  
  int height(Node* root, int& ans) 
{ 
    if (root == NULL) 
        return 0; 
  
    int left_height = height(root->left, ans); 
  
    int right_height = height(root->right, ans); 
  
    // update the answer, because diameter of a 
    // tree is nothing but maximum value of 
    // (left_height + right_height + 1) for each node 
    ans = max(ans, 1 + left_height + right_height); 
  
    return 1 + max(left_height, right_height); 
} 
  
/* Computes the diameter of binary tree with given root. */
int diameter(Node* root) 
{ 
    if (root == NULL) 
        return 0; 
    int ans = INT_MIN; // This will store the final answer 
    int height_of_tree = height(root, ans); 
    return ans; 
} 
