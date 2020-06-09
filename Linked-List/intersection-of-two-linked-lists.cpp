int intersectPoint(Node* head1, Node* head2)
{
    if(head1==NULL||head2==NULL)
       return 0;
    Node* i = head1;
    Node* j = head2;
    while(i!=j)
    {
        if(i==NULL)
           i = head2;
        else
           i = i->next;
        if(j==NULL)
           j= head1;
        else   
           j = j->next;
    }
    
    return i->data;
}
