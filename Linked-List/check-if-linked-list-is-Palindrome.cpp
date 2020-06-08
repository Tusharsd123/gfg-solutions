//Method 1 involves using a stack. Pusing every element of the linked list into the stack using a temprory pointer. After that traverse the
//list and the stack's top elemnt simultaneously and check if any of the node's data does'nt matches with the stack's top. return false 
//in that case else return true.

//T.C - o(n)
//S.C - o(n) due to stack space

bool isPalin(Node* head){ 
          
        // Temp pointer  
        Node* slow= head; 
  
        // Declare a stack  
        stack <int> s; 
   
  
        // Push all elements of the list  
        // to the stack  
        while(slow != NULL){ 
                s.push(slow->data); 
  
                // Move ahead  
                slow = slow->ptr; 
        } 
  
        // Iterate in the list again and  
        // check by popping from the stack 
        while(head != NULL ){ 
              
            // Get the top most element  
             int i=s.top(); 
  
             // Pop the element  
             s.pop(); 
  
             // Check if data is not 
             // same as popped element  
            if(head -> data != i){ 
                return false; 
            } 
  
            // Move ahead  
           head=head->ptr; 
        } 
  
return true; 
} 


//so we needed some alternate method to reduce the stack space.
//In method 2 we first take out the midlle node of the linked list using the slow and fast pointer approach.For even and odd length linked
//lists we are going to have different cases. In even one its easy to separate the whole linked list but for odd their will always
//be a single middle node and we dont want to include it in any of the linked lists.

//Best thing to be done is to skip that node for now and reverse the second half of the linked list and compare it with the first half.
//More importantly its to be noted that after comparing the second list is to be reversed again to its normal form and the whole list.
//is formed again.

//T.C- O(n)
//S.C - O(1)


bool isPalindrome(struct Node* head) 
{ 
    struct Node *slow_ptr = head, *fast_ptr = head; 
    struct Node *second_half, *prev_of_slow_ptr = head; 
    struct Node* midnode = NULL; // To handle odd size list 
    bool res = true; // initialize result 
  
    if (head != NULL && head->next != NULL) { 
        /* Get the middle of the list. Move slow_ptr by 1 
          and fast_ptrr by 2, slow_ptr will have the middle 
          node */
        while (fast_ptr != NULL && fast_ptr->next != NULL) { 
            fast_ptr = fast_ptr->next->next; 
  
            /*We need previous of the slow_ptr for 
             linked lists  with odd elements */
            prev_of_slow_ptr = slow_ptr; 
            slow_ptr = slow_ptr->next; 
        } 
  
        /* fast_ptr would become NULL when there are even elements in list.  
           And not NULL for odd elements. We need to skip the middle node  
           for odd case and store it somewhere so that we can restore the 
           original list*/
        if (fast_ptr != NULL) { 
            midnode = slow_ptr; 
            slow_ptr = slow_ptr->next; 
        } 
  
        // Now reverse the second half and compare it with first half 
        second_half = slow_ptr; 
        prev_of_slow_ptr->next = NULL; // NULL terminate first half 
        reverse(&second_half); // Reverse the second half 
        res = compareLists(head, second_half); // compare 
  
        /* Construct the original list back */
        reverse(&second_half); // Reverse the second half again 
  
        // If there was a mid node (odd size case) which 
        // was not part of either first half or second half. 
        if (midnode != NULL) { 
            prev_of_slow_ptr->next = midnode; 
            midnode->next = second_half; 
        } 
        else
            prev_of_slow_ptr->next = second_half; 
    } 
    return res; 
} 
  
/* Function to reverse the linked list  Note that this 
    function may change the head */
void reverse(struct Node** head_ref) 
{ 
    struct Node* prev = NULL; 
    struct Node* current = *head_ref; 
    struct Node* next; 
    while (current != NULL) { 
        next = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
    } 
    *head_ref = prev; 
} 
  
/* Function to check if two input lists have same data*/
bool compareLists(struct Node* head1, struct Node* head2) 
{ 
    struct Node* temp1 = head1; 
    struct Node* temp2 = head2; 
  
    while (temp1 && temp2) { 
        if (temp1->data == temp2->data) { 
            temp1 = temp1->next; 
            temp2 = temp2->next; 
        } 
        else
            return 0; 
    } 
  
    /* Both are empty reurn 1*/
    if (temp1 == NULL && temp2 == NULL) 
        return 1; 
  
    /* Will reach here when one is NULL 
      and other is not */
    return 0; 
} 
