class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int length = 0;
        ListNode* curr = head;
        while (curr) {
            curr = curr->next;
            length += 1;
        }
        int baseLength = length / k;
        int remainder = length % k;
        curr = head;
        vector<ListNode*> res;
        for (int i = 0; i < k; i++) {
            res.push_back(curr);
            int limit = baseLength - 1 + (remainder ? 1 : 0);
            for (int j = 0; j < limit; j++) {
                if (!curr) {
                    break;
                }
                curr = curr->next;
            }
            remainder -= (remainder ? 1 : 0);
            if (curr) {
                ListNode* temp = curr->next;
                curr->next = nullptr;
                curr = temp;
            }
        }
        return res;
    }
};
