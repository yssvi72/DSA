
class Solution {
  void update(long long &r,int rind,vector<pa>& fac,const vector<vector<int>>& factory,const vector<int> &robot){
    int rp=robot[rind];
    auto it=lower_bound(fac.begin(),fac.end(),rp,[](const auto &v,int target){return target>v.loc;});
    if(it==fac.end()) it=prev(it);
    else if(it!=fac.begin() && abs(rp-prev(it)->loc)<abs(rp-it->loc)) it=prev(it);
    if(it->lim){it->lim--;r+=abs(rp-it->loc);return;}
    //if space of closest factory is non zero, just put it there and update the result.
    auto itr=next(it);
    while(itr!=fac.end())//try pushing it to the right
      if(itr->lim==0) itr++;
      else break;
    if(it==fac.begin()){itr->lim--;r+=abs(rp-itr->loc);return;}
    //if the cloest factory is the first one and it's full, we have to push it to the right
    int incr=itr==fac.end()?INT_MAX:abs(rp-itr->loc);
    //if no space to the right at all, we set the increment to infinity, so it'll push to the left for sure
    long long rl=0;
    auto itl=prev(it);
    while(itl!=fac.begin()){//try pushing it to the left
      if((*itl).lim==0) itl--;
      else break;
    }
    if(itl->lim==0){itr->lim--;r+=incr;return;}//no space on left, have to push to the right
    int incl=abs(rp-it->loc),facl=itl->loc,cind=it-fac.begin(),lind=itl-fac.begin();
    for(;cind!=lind;--cind){
      rind-=factory[cind][1];//jump by the factory capacity,that's the robot that needs to move
      incl+=abs(robot[rind]-fac[cind-1].loc)-abs(robot[rind]-fac[cind].loc);//update the distance increment
    }
    if(incl<incr){itl->lim--;r+=incl;}
    else {itr->lim--;r+=incr;}
    //update the capacity in `fac` and the total distance accordingly.
  }
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        vector<pa> fac;
        fac.reserve(factory.size());
        for(const auto &v:factory) fac.emplace_back(pa{v[0],v[1]});
        sort(fac.begin(),fac.end());
        for(int i=0;i<factory.size();++i) factory[i][0]=fac[i].loc,factory[i][1]=fac[i].lim;
        long long r=0;
        for(int i=0;i<robot.size();++i) update(r,i,fac,factory,robot);
        return r;
    }
};
