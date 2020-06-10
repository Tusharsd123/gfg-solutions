void inorder(Node* root,queue<Node*> &q)
{
    if(root==NULL)
       return;
    inorder(root->left,q);
    q.push(root);
    inorder(root->right,q);
}

void bToDLL(Node *root, Node **head)
{
    
    queue<Node*> q;
    inorder(root,q);
    *head = q.front();
    Node* prev = NULL;
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        temp->left = prev;
        if(!q.empty())
         temp->right = q.front();
        else
           temp->right = NULL;
        prev = temp;   
    }
    
     
}
