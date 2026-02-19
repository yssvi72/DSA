class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        if len(nums) < 3:  # need at least 3 sides
            return 0
        
        x = sorted(nums)  # sort ascending

        # check triplets from largest to smallest
        for i in range(len(x)-1, 1, -1):
            a = x[i-2]
            b = x[i-1]
            c = x[i]
            if a + b > c:  # must be strictly greater
                return a + b + c  # only sum these three, not all numbers
        
        return 0  # if no valid triangle found
