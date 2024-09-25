class Node{
    public:
        Node* childs[26];
        bool isEnd;
        int c;
        Node(){
            c=0;
            isEnd=false;
            for(int i=0;i<26;i++){
                childs[i]=nullptr;
            }
        }
};
class Trie{
    private:
        void doInsert(Node* root,string s){
            Node* curr=root;
            for(char c:s){
                int i=c-'a';
                if(curr->childs[i]==nullptr){
                    curr->childs[i]=new Node();
                }
                curr=curr->childs[i];
                curr->c+=1;
            }
            curr->isEnd=true;
        }
        int doStartWith(Node* root,string s){
            int cnt=0;
            Node* curr=root;
            for(char c:s){
                int i=c-'a';
                if(curr->childs[i]==nullptr)return 0;
                curr=curr->childs[i];
                cnt+=curr->c;
            }
            return cnt;
        }
    public:
        Node* root;
        Trie(){
            root=new Node();
        }
        void insert(string s){
            doInsert(root,s);
        }
        int startWith(string s){
            return doStartWith(root,s);
        }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie t;
        for(string str:words){
            t.insert(str);
        }
        vector<int> ans;
        for(string s:words){
            ans.push_back(t.startWith(s));
        }
        return ans;
    }
};
