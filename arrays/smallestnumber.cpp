class Solution {
public:
    void solve(string &p,string &t,string &ans,int i,int state){
        if(i>=p.size()){
            ans=min(ans,t);
            return ;
        }
        for(char x='1';x<='9';x++){
            auto cur=x-'0';
            if(state&(1<<cur))continue;
            int newstate=state|(1<<cur);
            if(t.empty()){
                t.push_back(x);
                solve(p,t,ans,i,newstate);
                t.pop_back();}
            else{
                auto pr=t.back()-'0';
                char c=p[i];
                auto cur=x-'0';
                if(c=='I'&&cur>pr){
                    t.push_back(x);
                    solve(p,t,ans,i+1,newstate);
                    t.pop_back();
                }else if(c=='D'&&cur<pr){
                    t.push_back(x);
                    solve(p,t,ans,i+1,newstate);
                    t.pop_back();
                }
            }
        }
    }   
    string smallestNumber(string pattern) {
        int state=0;
        string temp="";
        string ans="99999999999";
        solve(pattern,temp,ans,0,state);
        return ans;
    }
};
