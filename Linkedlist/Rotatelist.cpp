class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode *slow=head,*fast=head;
        int len=0;
        while(slow!=NULL){
            len++;
            slow=slow->next;
        }
        k=k%len;
        slow=head;
        while(k--){
            fast=fast->next;
        }
        cout<<fast->val<<endl;
        if(fast==NULL){
            return head;
        }
        while(fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        fast->next=head;
        head=slow->next;
        slow->next=NULL;
        return head;       
    }
};
