int detectloop(Node *head) {

      Node* slow_p = head;
      Node* fast_p = head;
      
      while(slow_p && fast_p && fast_p->next!=NULL)
      {
          slow_p = slow_p->next;
          fast_p = fast_p->next->next;
          
          if(slow_p==fast_p)
          {
              return 1;
          }
      }
      
      return 0;
      
}
