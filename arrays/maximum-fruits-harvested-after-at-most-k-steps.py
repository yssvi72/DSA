class Solution:
    def maxTotalFruits(self, fruits: List[List[int]], startPos: int, k: int) -> int:
        max_fruits = 0
        current_sum = 0
        left_pointer = 0
        
        # Iterate over each fruit position with the right pointer
        for right_pointer in range(len(fruits)):
            # Add fruits at the current right position
            current_sum += fruits[right_pointer][1]
            
            # While the steps required to reach the leftmost and rightmost positions exceed k
            while left_pointer <= right_pointer and self.calculate_steps(fruits[left_pointer][0], fruits[right_pointer][0], startPos) > k:
                # Remove fruits at the left position
                current_sum -= fruits[left_pointer][1]
                # Move the left pointer to the right
                left_pointer += 1
            
            max_fruits = max(max_fruits, current_sum)
        
        return max_fruits
        
    def calculate_steps(self, left: int, right: int, start: int) -> int:
        # Calculate the minimum steps required to reach either end of the range
        go_left = abs(start - left) + (right - left)  # Steps to go to the leftmost position
        go_right = abs(start - right) + (right - left)  # Steps to go to the rightmost position
        return min(go_left, go_right)  # Return the minimum steps
