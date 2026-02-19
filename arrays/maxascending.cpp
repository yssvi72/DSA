class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        prev=nums[0]
        val=prev
        res=prev
        for i in range(1,len(nums)):
            if nums[i] > prev:
                val+=nums[i]
            else:
                res = max(res,val)
                val=nums[i]
            prev = nums[i]
        res = max(res,val)
        return res
