T.C - O(n)

void detectAndRemoveLoop(Node* head) 
{ 
    // If list is empty or has only one node 
    // without loop 
    if (head == NULL || head->next == NULL) 
        return; 
  
    Node *slow = head, *fast = head; 
  
    // Move slow and fast 1 and 2 steps 
    // ahead respectively. 
    slow = slow->next; 
    fast = fast->next->next; 
  
    // Search for loop using slow and 
    // fast pointers 
    while (fast && fast->next) { 
        if (slow == fast) 
            break; 
        slow = slow->next; 
        fast = fast->next->next; 
    } 
  
    /* If loop exists */
    if (slow == fast) { 
        slow = head; 
        while (slow->next != fast->next) { 
            slow = slow->next; 
            fast = fast->next; 
        } 
  
        /* since fast->next is the looping point */
        fast->next = NULL; /* remove loop */
    } 
} 
  
