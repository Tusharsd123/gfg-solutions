Node* deleteNode(Node *head,int x)
{   if(x==1)
        return head->next;
    Node* n=head;
    x=x-2;
    while(x--){
        n=n->next;
    }
    n->next=n->next->next;
    return head;
}
