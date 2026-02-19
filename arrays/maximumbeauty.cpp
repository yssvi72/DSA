class Solution {
    public:
        vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
            // Create a vector to store the result for each query
            vector<int> results;
            
            // Sort the items by price first, and then by beauty in non-increasing order
            // (if price is the same, sort by beauty in non-decreasing order)
            sort(items.begin(), items.end(), [](const vector<int>& a, const vector<int>& b) {
                return (a[0] < b[0] || (a[0] == b[0] && a[1] <= b[1]));
            });

            // Dictionary to store the maximum beauty found for each price point
            unordered_map<int, int> max_Beauty_At_Price;
            int max_Beauty = 0;
            
            // Iterate through the sorted items to fill in the dictionary
            for(auto& item: items) {
                int price = item[0], beauty = item[1];
                // Update the maximum beauty found so far
                max_Beauty = max(max_Beauty, beauty);
                // Store the maximum beauty for this price
                max_Beauty_At_Price[price] = max_Beauty;
            }

            // Lambda function to perform binary search to find the maximum beauty for a given maxPrice
            function<int(int, int, int)> findMaxBeauty = [&](int startIndex, 
                                                                int endIndex, 
                                                                int maxPrice) -> int {
                // Base case: if the search range is invalid (startIndex > endIndex), return 0
                if (startIndex > endIndex)
                    return 0;

                // Find the middle index of the current search range
                int midIndex = (startIndex + endIndex) / 2;
                int price = items[midIndex][0];  // Price of the item at midIndex
                int beauty = items[midIndex][1]; // Beauty of the item at midIndex

                // If the price of the current item is less than or equal to the maxPrice, we consider this item
                if (price <= maxPrice) {
                    // Recursively search the right half of the list for potentially better items
                    int rightBeauty = findMaxBeauty(midIndex + 1, endIndex, maxPrice);  // Search right half
                    // Return the maximum beauty found between the current item and the right half
                    return max(max_Beauty_At_Price[price], rightBeauty);
                }
                
                // If the current item's price is greater than the maxPrice, search the left side
                return findMaxBeauty(startIndex, midIndex - 1, maxPrice);
            };

            // For each query, call the findMaxBeauty function to find the maximum beauty within the given price limit
            for (const int& maxPrice : queries) {
                // Append the result of the query to the results vector
                results.emplace_back(findMaxBeauty(0, items.size() - 1, maxPrice));
            }

            // Return the list of results for all queries
            return results;
        }
};
