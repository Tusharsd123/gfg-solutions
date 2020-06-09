Node* addTwoLists(Node* first, Node* second) {
    if (first==NULL)
        return second;
        
    if(second==NULL)
        return first;
        
    int a = first->data+second->data;
    Node *p = new Node(a%10);
    p->next = addTwoLists(first->next,second->next);
    if(a>=10)
      p->next = addTwoLists(p->next,new Node(1));
      
      
    return p;  
}
