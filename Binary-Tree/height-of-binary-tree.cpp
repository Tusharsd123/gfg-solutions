int height(Node* root)
{
    if(root==NULL)
       return 0;
    int l = height(root->left);
    int r = height(root->right);
    return (1+max(l,r));
}

//Time complexity of binary tree traversals is O(n)
//space complexity can be O(1) if we don't consider the function call stack size otherwise it's O(n).
