class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if(sentence1==sentence2)return true;
        vector<string>s1;
        vector<string>s2;
        sentence1.push_back(' ');
        sentence2.push_back(' ');
        string word=" ";
        for(int i=0;i<sentence1.size();i++){
            if(sentence1[i]==' '){
                s1.push_back(word);
                word=" ";
            }
            else word+=sentence1[i];
        }
        word=' ';
        for(int i=0;i<sentence2.size();i++){
            if(sentence2[i]==' '){
                s2.push_back(word);
                word=" ";
            }
            else word+=sentence2[i];
        }
        int st1=0,en1=s1.size()-1;
        int st2=0,en2=s2.size()-1;
        while(st1<=en1&&st2<=en2){
            if(s1[st1]==s2[st2]){
                st1++;
                st2++;
            }
            else if(s1[en1]==s2[en2]){
                en1--;
                en2--;
            }
            else break;
        }
        return (en1+1==st2||en2+1==st2);
    }
};
