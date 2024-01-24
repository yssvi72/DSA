// For any two linked lists to be identical : 1. Length of list should be same   2. Values at each node should be same.

// In this program while writing remember  EDI( whether they are empty , Check for next node if iDentical , Increment the node by 1 with node-->next)

//PROGRAM : 

// Why struct as it allows a user to combine data items of different data types under a single name whereas class only combine datatypes of similar characteristics
  struct Node {  
               int data ;       // LL has node which contains data which is integer and a pointer which points to *next* node h
               struct Node * next;     
              } ;    // Declaration of struct class closed     


// Why bool because I want to return solution in 'Yes' /'No' i.e  whether they are identical or not. 
bool areIdentical(struct Node *list1 , struct Node *list2) // Function to compare both lists
{
   while( list1!=NULL && list2!=NULL) // Till the time both lists did not reach their end i.e  pointing to NULL , iterate the loop till then.
       {  if(list1->data != list2->data)  //  if the data is not same , return false as both are not identical 
             return false ;
          else 
          list1=list1->next;
          list2=list2->next; 
       }
 
     // If linked lists are identical, then list1 and list2 must be NULL at this point
   return (list1 == NULL && list2 == NULL); 

}

// Time Complexity : O(min(m,n)) where m and n are sizes of list1 and list2
// Space Complexity : O(1)



/* Not a Leetcode problem but GFG problem */
/* But Imp for Interview point of view */
