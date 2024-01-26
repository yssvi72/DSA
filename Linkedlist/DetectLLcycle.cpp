// To proceed , detecting cycle in linked list means there is occurrence of loop in the linked list 
// Aim is to detect the cycle and return true/ false

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Approach 1: Using Hashset ( Beginner Level Approach ) 
bool hasCycle( ListNode *head){  // bool to detect cycle
  std::unordered_set<ListNode*> visited;  //We start with an empty hash set (visited) to keep track of nodes we have visited.
  while( head ! = NULL)
    {  //  Traverse the linked list until we reach the end
         if( visited.find(head) != visited.end())
              {   //In each iteration, we check if  current node (head) is already in the hash set. If it is, it means we have encountered the same node before, indicating the presence of a cycle
                   return true ; //Cycle detected 
              } 
        visited.insert(head); //If the current node is not in the hash set, we insert it into the hash set and move to the next node (head = head->next).Mark the current node as visited
        head = head->next;  // Move to next node

    }
  return false; //No cycle
} 
//-----------------------Time Complexity --> O(N) and Space Complexity --> O(N)-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Approach 2 : ( Floyd's Tortoise and Hare Algorithm ) or slow , fast pointer approach -->Intermediate level
// Idea behind it is : we will have two pointers , slow and fast , slow will move one step at a time and fast will move two steps at a time , if both pointers meet at particular time after n iterations then there is cycle
bool hasCycle(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
    {
           return false;      // No cycle if list is empty or has only one node
    }

    ListNode* slow = head;    // Initialise slow as head i.e moving with head  and fast as head->next  i.e moving a step ahead of head , overall taking two steps at a toime 
    ListNode* fast = head->next;

    while (slow != fast) { // Till the time slow has not met fast 
        if (fast == nullptr || fast->next == nullptr) { // Same as fast->next=null or fast->next->next=null which means we are considering even list and odd list simulatenously , if it has reached end , no cycle
            return false; // No cycle
        }
        slow = slow->next;  // else till the time both reach last node or null iterate slow and fast pointers 
        fast = fast->next->next;   // Aim is to make both slow and fast meet 
    }
  // End of while loop 

    return true; // If both met , cycle detected 
}
//----------------------Time Complexity ---> O(N) and Space Complexity ---> O(1)-------------------------------------------------------------------------------------------------------------------------------------------=-----------------------------------------------------------------------------

//Approach 3 : Advanced : same as intermediate but here we use a do-while loop, ensuring that the pointers start at the same node initially and then continue the traversal until they meet.
//This eliminates the initial comparison before entering the loop and hence be efficient. Complexity is same as intermediate one 
bool hasCycle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return false; // No cycle if list is empty or has only one node
    }

    ListNode* slow = head;
    ListNode* fast = head;

    do {  // Diff is prevent checking the initial comparision of whether slow is equal to fast before entering the loop 
        if (fast == nullptr || fast->next == nullptr) { 
            return false; // No cycle
        }
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    return true; // Cycle detected
}
//------------------------Time Complexity ----> O(N)  and Space Complexity ---->O(1)---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
