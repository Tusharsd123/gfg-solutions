//in case of skewed trees time complexity may get to O(n^2) in worst case.

int print(Node* root,int level,int ltr);
int height(Node* root);
int max(int a,int b);
void printSpiral(Node *root)
{
    int h = height(root);
    int i;
    bool ltr = false;
    for(i=1;i<=h;i++)
      { print(root,i,ltr);
           ltr = !ltr;
       
      }
}

int print(Node* root,int level,int ltr)
{
    if(root==NULL)
       return 0;
       
    if(level==1)
       cout<<root->data<<" ";
       
    if(level>1)
    {
        if(ltr)
        {
            print(root->left,level-1,ltr);
            print(root->right,level-1,ltr);
        }
        
        else
        {
            print(root->right,level-1,ltr);
            print(root->left,level-1,ltr);
        }
    }
}

int height(Node* root)
{
    if(root==NULL)
      return 0;
    else
    {
        int lheight = height(root->left);
        int rheight = height(root->right);
        
        return 1+max(lheight,rheight);
    }
}

int max(int a,int b)
{
    return a>=b?a:b;
}


//iterative method is there using stacks 
//T.C - O(n)
//S.C - O(n)

void printSpiral(struct node* root) 
{ 
    if (root == NULL) 
        return; // NULL check 
  
    // Create two stacks to store alternate levels 
    stack<struct node*> s1; // For levels to be printed from right to left 
    stack<struct node*> s2; // For levels to be printed from left to right 
  
    // Push first level to first stack 's1' 
    s1.push(root); 
  
    // Keep printing while any of the stacks has some nodes 
    while (!s1.empty() || !s2.empty()) { 
        // Print nodes of current level from s1 and push nodes of 
        // next level to s2 
        while (!s1.empty()) { 
            struct node* temp = s1.top(); 
            s1.pop(); 
            cout << temp->data << " "; 
  
            // Note that is right is pushed before left 
            if (temp->right) 
                s2.push(temp->right); 
            if (temp->left) 
                s2.push(temp->left); 
        } 
  
        // Print nodes of current level from s2 and push nodes of 
        // next level to s1 
        while (!s2.empty()) { 
            struct node* temp = s2.top(); 
            s2.pop(); 
            cout << temp->data << " "; 
  
            // Note that is left is pushed before right 
            if (temp->left) 
                s1.push(temp->left); 
            if (temp->right) 
                s1.push(temp->right); 
        } 
    } 
} 
