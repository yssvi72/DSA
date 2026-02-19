class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        answer = []
        n = len(prices)
        
        # Iterate through each item in the prices list
        for i in range(n):
            discount = 0  # Initialize discount as 0 for current item
            
            # Find the first item on the right that satisfies the condition
            for j in range(i + 1, n):
                if prices[j] <= prices[i]:
                    discount = prices[j]
                    break
            
            # Calculate the final price and add it to the answer list
            answer.append(prices[i] - discount)
        
        return answer




