The worst case time complexity of search and insert operations is O(h) where h is height of Binary Search Tree. 
//In worst case, we may have to travel from root to the deepest leaf node.
//The height of a skewed tree may become n and the time complexity of search and insert operation may become O(n).



struct node* insert(struct node* node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key);    
  
    /* return the (unchanged) node pointer */
    return node; 
} 
