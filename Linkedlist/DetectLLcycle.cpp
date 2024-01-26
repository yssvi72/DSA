// To proceed , detecting cycle in linked list means there is occurrence of loop in the linked list 
// Aim is to detect the cycle and return true/ false

// Approach 1: Using Hashset
//iii.  In each iteration, we check if the current node (head) is already in the hash set. If it is, it means we have encountered the same node before, indicating the presence of a cycle.
//iv.   If the current node is not in the hash set, we insert it into the hash set and move to the next node (head = head->next).
//v.    If we reach the end of the linked list without detecting a cycle, we return false.

bool hasCycle( ListNode *head){  // bool to detect cycle
  std::unordered_set<ListNode*> visited;  //We start with an empty hash set (visited) to keep track of nodes we have visited.
  while( head ! = NULL)
    {  //  Traverse the linked list until we reach the end
         if( visited.find(head) != visited.end())
              {   //In each iteration, we check if  current node (head) is already in the hash set. If it is, it means we have encountered the same node before, indicating the presence of a cycle
                   return true ; //Cycle detected 
              } 
        visited.insert(head); //Mark the current node as visited
        head = head->next;  // Move to next node

    }
  return false; //No cycle
} 
