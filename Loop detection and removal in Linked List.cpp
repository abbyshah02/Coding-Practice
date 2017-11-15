/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    
       
    Node* slow_ptr = head, *fast_ptr = head;
    
    while(slow_ptr && fast_ptr && fast_ptr->next)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        
        if(slow_ptr == fast_ptr)
        {
             Node *ptr1 = slow_ptr, *ptr2 = slow_ptr;
             int k=1;
             //ptr2 = ptr2->next;
             
             //count the number of nodes in loop
             while(ptr2->next!=ptr1)
             {
                 ptr2 = ptr2->next;
                 k++;
             }
            
             
             ptr1 = head;
             ptr2 = head;
             
             for(int i=0;i<k;i++)
             ptr2 = ptr2->next;
             
             
             while(ptr1 != ptr2)
             {
                 ptr1 = ptr1->next;
                 ptr2 = ptr2->next;
             }
             
             while(ptr2->next != ptr1)
             {
                 ptr2 = ptr2->next;
             }
             
             ptr2->next = NULL;
          
             
            
            
            return true;
        }
    }
    return false;
}
