struct node *reverse (struct node *head, int k)
{ 
   if(head==NULL||k==1)
      return head;
   int num = 0;
   struct node* prehead = new node(-1);
   prehead->next = head;
   struct node* pre = prehead;
   struct node* curr = prehead;
   struct node* nex;
   while(curr=curr->next)
       num++;
    while(num>=k)
    {
        curr = pre->next;
        nex = curr->next;
        for(int i = 0;i<k;i++)
        {
            curr->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = curr->next;
        }
        pre = curr;
        num = num-k;
    }
    
    return prehead->next;
}
