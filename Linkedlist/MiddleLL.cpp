// Middle of Linked list 
// To find middle of linked list , we must be aware that it  can be of either even length or odd length.

// Approach  1:  Beginner level ( Dividing the list by 2 )

ListNode *middleNode(ListNode *head) // head represent start of list , can take other varaible name but it should start from the beginning node i.e you have to initialise it to head
{
   int count = 0;  // Counter for traversal of LL
   ListNode *temp = head;   // Create temp and intialise it to head , temp for traversal 
   while ( temp ! = NULL)   // till the time temp hasn't reached last node
     {   count ++;          // Increment the counter
         temp = temp->next;   // Move it forward
     }
    int half = count /2 ;   // Declare half as arbitary middle of list , for traversing till middle
    temp = head;
    while (half--)  // till the time it hasn't reached hald
    {
      temp= temp->next;
    }
    return temp; // Return value of temp
}
     


// Approach 2 : Slow and fast pointer , till the time fast pointer which moves 2 steps at a time reached end , slow pointer which moves one step at a time  , will still be pointing at middle most position.

ListNode * middleNode(ListNode *head)
{
  int n = 0;
  ListNode *slow = head , *fast = head;
  while( fast!=NULL && fast->next!=NULL) // i.e fast!=null is odd list case and fast->next!=null is even length case 
    {  slow = slow->next;    // Move slow only one step at a time
       fast = fast->next->next;  // Move fast two step at a time

    }
  return slow; // As when fast reaches end , slow reaches middle
}
    






   
  

