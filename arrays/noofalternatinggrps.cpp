#define ll long long
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define boost    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define test() ll t;cin>>t;while(t--)
#define fl(i,a,b) for(ll i=a;i<b;i++)
#define pb push_back
#define N cout<<"\n"
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& c, int k) {
        for(int i = 0 ; i<k-1;i++){
            c.pb(c[i]);
        }
        int i = 0,j=1,ctr =0;
        bool flag = false;
        while(j<c.size()){
            if(c[j]!=c[j-1]){
                if(j-i+1==k)flag = true;
                if(flag) {
                    ctr++;
                    i++;
                }
                j++;
            }
            else{
                i=j;
                j++;
                flag = false;
            }
        }
        return ctr;

    }
};
