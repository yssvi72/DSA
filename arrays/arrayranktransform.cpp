class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size()==0){
            return {};
        }

// to remove the duplicates from the arr
     set<int> set1(arr.begin(),arr.end());
     // to map the element with its rank
     map<int,int> mpp;
     
     
     int cnt=1;
     // mapping the element with its rank
     for(auto i:set1){
        mpp[i]=cnt++;
     }


    // updating the 
     for(int i=0;i<=arr.size()-1;i++){
        arr[i] = mpp[arr[i]];
        
     }

    


  

    return arr;
    }
};
