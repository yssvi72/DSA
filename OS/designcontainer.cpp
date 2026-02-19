class NumberContainers {
private:
    unordered_map<int,int> m1;//idx->no.
    unordered_map<int,set<int>> m2;//no.->all idxs set

public:
    NumberContainers() {}
    
    void change(int index, int number) {
        if(m1.find(index)!=m1.end()){//if idx already in map with a no.
            int prevno=m1[index];//extract the prevno.
            m1[index]=number;//change the idx with new no.
            m2[prevno].erase(index);//erase that idx from set of idxs of prevno.
            m2[number].insert(index);//add the idx to the set of the new no. as well
        }
        else{
            m1[index]=number;//add in m1 idx->no.
            m2[number].insert(index);//insert in m2 the no.->set of idxs
        }
    }
    
    int find(int number) {
        if(m2.find(number)!=m2.end() && !m2[number].empty()){
            return *m2[number].begin();//to get the 1st ele of ordered set since ele in asc order by deafult in ordered set
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
