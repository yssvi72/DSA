class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        
        # Initialize lists to hold the product values
        left = [1] * n  # Product of elements to the left of each index
        right = [1] * n # Product of elements to the right of each index
        ans = [1] * n   # Result list

        # Calculate left product for each element
        for i in range(1, n):
            left[i] = left[i - 1] * nums[i - 1]

        # Calculate right product for each element
        for i in range(n - 2, -1, -1):
            right[i] = right[i + 1] * nums[i + 1]

        # Calculate final product except self
        for i in range(n):
            ans[i] = left[i] * right[i]

        return ans
