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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int total=m*n;
        ListNode*curr=head;
        int startrow=0,endrow=m-1,startcol=0,endcol=n-1;
        vector<vector<int>>ans(m,vector<int>(n,-1));
        while(curr!=NULL)
        {
            for(int i=startcol;curr!=NULL && i<=endcol;i++)
            {
                ans[startrow][i]=curr->val;
                curr=curr->next;
            }
            startrow++;
            for(int i=startrow;curr!=NULL && i<=endrow;i++)
            {
                ans[i][endcol]=curr->val;
                curr=curr->next;
            }
            endcol--;
            for(int i=endcol;curr!=NULL && i>=startcol;i--)
            {
                ans[endrow][i]=curr->val;
                curr=curr->next;
            }
            endrow--;
            for(int i=endrow;curr!=NULL && i>=startrow;i--)
            {
                ans[i][startcol]=curr->val;
                curr=curr->next;
            }
            startcol++;
        }
        return ans;
    }
};
