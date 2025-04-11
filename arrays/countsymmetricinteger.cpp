class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        
        int count =0;
        
        for( int i = low; i<=high; i++){
             string str = to_string(i);
             if( str.size() %2 ==0){
     

                int mid = str.size()/2;

               int sum1 =0,  sum2 =0; 

               for( int j =0; j< mid; j++){
                sum1+= str[j] -'0';
                sum2+= str[mid+j] -'0';
               }

               if(sum1== sum2){
                count++;
               }
             }
             else{
                continue;
             }
        }
        return count;
        
    }
}; 
