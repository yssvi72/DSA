class Solution:
    def partitionArray(self, nums: List[int], k: int) -> int:
        nums.sort()
        
        count = 0
        currentMin = nums[0]

        for i in range(len(nums)):
            if nums[i] - currentMin > k:
                currentMin = nums[i]
                count += 1
        
        return count + 1
        
