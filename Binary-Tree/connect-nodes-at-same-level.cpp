/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */

// Should set the nextRight for all nodes
void connect(Node *p)
{
   
   if(p==NULL)
      return ;
   queue<Node*>q;
   q.push(p);
   while(!q.empty())
   {
          int t=q.size();
          Node* temp;
     while(t--)
     {
             temp=q.front();
             q.pop();
             if(temp->left)
                q.push(temp->left);

             if(temp->right)
                  q.push(temp->right);
             if(t>0)
                temp->nextRight=q.front();
     }
             temp->nextRight=NULL;
    }
}

