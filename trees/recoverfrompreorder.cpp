/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) 
    {
        vector<TreeNode*>nodes;
        vector<int>depths;
        int i=0;
        int n=traversal.length();
        while(i<traversal.length())
        {
            string s="";
            int depth=0;
            while(i<n and traversal[i]=='-')
            {
                depth++;
                i++;
            }
            while(i<n and traversal[i]!='-' and traversal[i]!='\0')
            {
                s+=traversal[i];
                i++;
            }
            int val=stoi(s);
            
            TreeNode* node=new TreeNode(val);
            nodes.push_back(node);
            depths.push_back(depth);
        }
        
        for(int i=1;i<depths.size();i++)
        {
            int j=i-1;
            while(depths[j]>=depths[i])
            {
                j--;
            }
            if(nodes[j]->left==NULL)
            {
                nodes[j]->left=nodes[i];
            }
            else
            {
                nodes[j]->right=nodes[i];
                
            }
        
        }
        return nodes[0];
        
    }
};
