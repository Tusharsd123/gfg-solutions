//T.C - O(n)

void printLeaves(struct Node* root)
{
    if(root==NULL)
        return;
    printLeaves(root->left);
    if(!(root->left) && (!root->right))
       cout<<root->data<<" ";
       
    printLeaves(root->right);   
}

void printBoundaryLeft(struct Node* root)
{
    if(root==NULL)
      return;
      
    if(root->left)
    {
        cout<<root->data<<" ";
        printBoundaryLeft(root->left);
    }
    
    else if(root->right)
    {
        cout<<root->data<<" ";
        printBoundaryLeft(root->right);
    }
}

void printBoundaryRight(struct Node* root) 
{ 
    if (root == NULL) 
        return; 
  
    if (root->right) { 
        printBoundaryRight(root->right); 
        printf("%d ", root->data); 
    } 
    else if (root->left) { 
        printBoundaryRight(root->left); 
        printf("%d ", root->data); 
    } 
    
}    
void printBoundary(struct Node *root)
{
     if(root==NULL)
         return;
         
    cout<<root->data<<" ";     
    printBoundaryLeft(root->left);
    printLeaves(root->left);
    printLeaves(root->right);
    printBoundaryRight(root->right);
    
}
