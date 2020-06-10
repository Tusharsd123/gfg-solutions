//O(n+m) T.C
//Merge is one of those nice recursive problems where the recursive solution code is much cleaner than the iterative code. 
//You probably wouldn’t want to use the recursive version for production code however,
//because it will use stack space which is proportional to the length of the lists.

Node* SortedMerge(Node* a, Node* b)  
{  
    Node* result = NULL;  
      
    /* Base cases */
    if (a == NULL)  
        return(b);  
    else if (b == NULL)  
        return(a);  
      
    /* Pick either a or b, and recur */
    if (a->data <= b->data)  
    {  
        result = a;  
        result->next = SortedMerge(a->next, b);  
    }  
    else
    {  
        result = b;  
        result->next = SortedMerge(a, b->next);  
    }  
    return(result);  
}  

//to do in place

Node* merge(Node* h1, Node* h2) 
{ 
    if (!h1) 
        return h2; 
    if (!h2) 
        return h1; 
  
    // start with the linked list 
    // whose head data is the least 
    if (h1->data < h2->data) { 
        h1->next = merge(h1->next, h2); 
        return h1; 
    } 
    else { 
        h2->next = merge(h1, h2->next); 
        return h2; 
    } 
} 
