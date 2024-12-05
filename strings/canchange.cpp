class Solution {
public:
    bool canChange(string start, string target) {
        int n1=start.size(),n2=target.size();
        if(n1!=n2)
        {
            return false;
        }
        queue<int>s,t;
        for(int i=0;i<n1;i++)
        {
            if(start[i]=='L')
            {
                s.push(i);
            }
            if(target[i]=='L')
            {
                t.push(i);
            }
        }
        int st=0,ta=0;
        while(st<n1||ta<n2)
        {
            while(st<n1&&start[st]=='_')
            st++;
            while(ta<n2&&target[ta]=='_')
            ta++;
            if(st==n1&&ta==n2)
            {
              break;
            }
            else if((st==n1&&ta!=n2)||(st!=n1&&ta==n2))
            {
                return false;
            }
            if(start[st]!=target[ta])
            return false;
            if(start[st]=='L')
            {
            if(st<ta)
            return false;
            st++;
            ta++;
            continue;
            }
            while(!s.empty()&&s.front()<st)
            {
               s.pop();
            }
            while(!t.empty()&&t.front()<ta)
            {
               t.pop();
            }
            if(s.empty()==true&&t.empty()==true)
            {
                if(st>ta)
                return false;
                st++;
                ta++;
                continue;
            }
            if((s.empty()==true&&t.empty()==false)||(s.empty()==false&&t.empty()==true))
            {
                return false;
            }
            if(st>=t.front()||st>ta)
            {
                return false;
            }
            st++;
            ta++;
        }
        return true;
    }
};
