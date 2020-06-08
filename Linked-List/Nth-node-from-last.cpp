int getNthFromLast(Node *head, int n)
{
    Node* first = head;
    int length=0;
    while(first!=NULL)
    {
        length++;
        first=first->next;
    }
    length = length-n;
    while(length>0)
    {
        length--;
        first = first->next;
    }
    return first->data;
}

