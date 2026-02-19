class Solution {
public:
    //function to calculate the maximum matrix sum
    long long maxMatrixSum(vector<vector<int>>& matrix) {
    long long int totalSum = 0; // variable to store the total sum of the matrix
    bool zeroExists = false; // variable to check if there is any 0 in the matrix
    int negativeCount = 0; // variable to store the count of negative numbers in the matrix
    int minimumAbsoluteValue = INT_MAX; // variable to store the minimum absolute value of the matrix
        //iterating through the matrix
    for(auto it: matrix)
    {
        for(auto i: it)
        {
            if(i==0)
                zeroExists = true; // setting the zeroExists variable to true if there is 0 in the matrix
            if(i<0)
                negativeCount++; // incrementing the negativeCount variable if the current number is negative
            totalSum += abs(i); // adding the absolute value of the current number to the totalSum
            if(abs(i)<minimumAbsoluteValue)
                minimumAbsoluteValue = abs(i); // updating the minimumAbsoluteValue variable if the current absolute value is less than the current value
        }
    }
    //if there is zero or even number of negative numbers
    if(zeroExists || negativeCount%2==0)
        return totalSum;
    return totalSum-2*minimumAbsoluteValue; // returning the totalSum - 2* minimumAbsoluteValue
}
};
