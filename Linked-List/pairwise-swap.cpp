Node* pairWiseSwap(struct Node* head) {
    struct Node* prehead = new Node(-1);
    prehead->next = head;
    struct Node* pre = prehead;
    struct Node* curr = prehead;
    struct Node* nex;
    int num = 0;
    while(curr->next!=NULL)
      { num++;
        curr = curr->next;
      }
    while(num>=2)
    {
        curr = pre->next;
        nex = curr->next;
            curr->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = curr->next;
        pre = curr;
        num = num-2;
    }
    return prehead->next;
}
