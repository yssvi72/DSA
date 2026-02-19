lass Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int>m;
        for(int i=0;i<bills.size();i++)
        {
            if(bills[i]==5)
            {
                m[5]++;
            }
            else if(bills[i]==10)
            {
                m[10]++;
                if(m[5]>0)
                {
                    m[5]--;
                    
                }
                else
                {
                    return false;
                }
            }
            else if(bills[i]==20)
            {
                if(m[10]>0)
                {
                    m[10]--;
                    
                    if(m[5]>0)
                    {
                        m[5]--;
                        
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if(m[10]==0)
                {
                    if(m[5]<3)
                    {
                        return false;
                    }
                    else
                    {
                        m[5]--;
                        m[5]--;
                        m[5]--;
                        
                    }
                }
                else 
                {
                    return false;
                }
                

                
                
            }
        }
        return true;
    }
};
