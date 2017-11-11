/*
   Find merge point of two linked lists
   Node is defined as
   struct Node
   {
       int data;
       Node* next;
   }
*/
int FindMergeNode(Node *head1, Node *head2)
{
    //start
    
    struct Node *temp1 = head1;
    struct Node *temp2 = head2;
    int output = 0;
    //Find the length of both the linked lists : 
    int length1=0,length2=0;
    while(temp1 != NULL)
    {
        length1++;
        temp1 = temp1->next;
    }
    
   
    
    while(temp2 != NULL)
    {
        length2++;
        temp2 = temp2->next;
    }
   
    if(length2 > length1)
    {
     
        int diff = length2 - length1;
        for(int i=0;i<diff;i++)
        {
            head2 = head2->next;
        }
    }
    else if(length1 > length2){
     
         int diff = length1 - length2;
        for(int i=0;i<diff;i++)
        {
            head1 = head1->next;
        }
    }
    while(head1 != NULL )
    {
     
        if(head1 == head2)
        {
         
            output = head1->data;
           break;
        }
        
            
            head1 = head1->next;
            head2 = head2->next;
       
            
    }
   
    return output;
    
    // end
}


