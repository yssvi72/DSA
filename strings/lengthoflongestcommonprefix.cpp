class TrieNode{
    public:
    TrieNode* child[10];
    TrieNode(){
        for(int i=0;i<10;i++)
        child[i]=nullptr;
    }
};

class Trie{
    public:
    TrieNode* root;
    Trie(){
        root=new TrieNode();
    }
    void insert(string str)
    {
        TrieNode* temp=root;
        for(int i=0;i<str.size();i++)
        {
            int idx=str[i]-'0';
            if(temp->child[idx]==nullptr)
            temp->child[idx]=new TrieNode();
            temp=temp->child[idx];
        }
    }
    int check_depth(string str)
    {
        TrieNode* temp=root;
        int cnt=0;
        for(int i=0;i<str.size();i++)
        {
            int idx=str[i]-'0';
            if(temp->child[idx]==nullptr)
            break;
            temp=temp->child[idx];
            cnt++;
        }
        return cnt;
    }

};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;
        //step 1 first insert all the numbrs in arr1
        for(int i=0;i<arr1.size();i++)
        {
            string str=to_string(arr1[i]);
            trie.insert(str);
        }
        //start checking for longest prefix
        int ans=0;
        for(int i=0;i<arr2.size();i++)
        {
            string str=to_string(arr2[i]);
            ans=max(ans,trie.check_depth(str));
        }
        return ans;

    }
};
