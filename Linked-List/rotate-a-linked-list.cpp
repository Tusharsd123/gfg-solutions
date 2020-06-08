//Traverse the linked list and make it a circular linked list. From the end of the list traverse till k and make the next of
//it equal to null.

//T.C - o(n)

Node* rotate(Node* head, int k) {
    Node* temp = head;
    while(temp->next)
    {
        temp = temp->next;
    }
    temp->next = head;
    Node* end;
    end = head;
    while(k--)
    {
        end = head;
        head = head->next;
    }
    end->next = NULL;
    return head;
}
