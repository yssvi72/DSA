/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    unordered_set<int>gcd(int n){
        unordered_set<int>divisor;
        for(int i=1;i<=n;i++){
            if(n%i==0){
                divisor.insert(i);
            }
        }
        return divisor;

    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head->next) return head;

        ListNode *node1=head;
        ListNode *node2=head->next;
        while(node1 &&  node1->next){
               int firstval=node1->val;
               int secondval=node2->val;
               unordered_set<int>firstnum=gcd(firstval);
               unordered_set<int>secondnum=gcd(secondval);
               int max1=0;
               for(auto &i:firstnum){
                if(secondnum.find(i)!=secondnum.end()){
                    max1=max(max1,i);
                }
               }
               ListNode *temp=new ListNode(max1);
               node1->next=temp;
               temp->next=node2;
               //if(!node2->next) return head;
               node1=node2;
               node2=node1->next;


        }
        return head;
    }
};
