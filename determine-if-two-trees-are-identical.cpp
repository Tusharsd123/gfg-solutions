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
