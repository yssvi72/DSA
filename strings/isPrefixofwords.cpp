class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        string a=" "+ sentence,b=" "+searchWord;
        if(a.find(b)==-1) return -1;
        return 1+count(a.begin(),a.begin()+a.find(b),' ');
    }
};
