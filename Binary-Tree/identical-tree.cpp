//Complexity of the identicalTree() will be according to the tree with lesser number of nodes. 
//Let number of nodes in two trees be m and n then complexity of sameTree() is O(m) where m < n.

bool isIdentical(Node *r1, Node *r2)
{
    if(r1==NULL && r2==NULL)
         return true;
         
    if(r1!=NULL && r2!=NULL)
    {
        return (r1->data==r2->data && isIdentical(r1->left,r2->left) && isIdentical(r1->right,r2->right));
    }
    
    return false;
}

//Algo:
//sameTree(tree1, tree2)
//1. If both trees are empty then return 1.
//2. Else If both trees are non -empty
//     (a) Check data of the root nodes (tree1->data ==  tree2->data)
//     (b) Check left subtrees recursively  i.e., call sameTree( 
//          tree1->left_subtree, tree2->left_subtree)
//     (c) Check right subtrees recursively  i.e., call sameTree( 
//          tree1->right_subtree, tree2->right_subtree)
//     (d) If a,b and c are true then return 1.
//3  Else return 0 (one is empty and other is not)


//iterative traversal using level order schemes and two arrays with T.C - O(n+m)

bool areIdentical(Node *root1, Node *root2) 
{ 
    // Return true if both trees are empty 
    if (root1  && root2) return true; 
  
    // Return false if one is empty and other is not 
    if (root1 || root2)  return false; 
  
    // Create an empty queues for simultaneous traversals  
    queue<Node *> q1, q2; 
  
    // Enqueue Roots of trees in respective queues 
    q1.push(root1); 
    q2.push(root2); 
  
    while (!q1.empty() && !q2.empty()) 
    { 
        // Get front nodes and compare them 
        Node *n1 = q1.front(); 
        Node *n2 = q2.front(); 
  
        if (n1->data != n2->data) 
           return false; 
  
        // Remove front nodes from queues 
        q1.pop(), q2.pop(); 
  
        /* Enqueue left children of both nodes */
        if (n1->left && n2->left) 
        { 
            q1.push(n1->left); 
            q2.push(n2->left); 
        } 
  
        // If one left child is empty and other is not 
        else if (n1->left || n2->left) 
            return false; 
  
        // Right child code (Similar to left child code) 
        if (n1->right && n2->right) 
        { 
            q1.push(n1->right); 
            q2.push(n2->right); 
        } 
        else if (n1->right || n2->right) 
            return false; 
    } 
  
    return true; 
} 
