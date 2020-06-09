Time-Complexity - O(n)
//Space complexity - O(1)

Node *removeDuplicates(Node *root)
{
   Node *after=NULL;
   Node *curr=root;
  while(curr->next!=NULL)
  {
     after=curr->next;
     if(curr->data==curr->next->data)
     {
        curr->next=after->next;
     }
     else
    {
        curr=curr->next;
    }
  }
    return root;
}
