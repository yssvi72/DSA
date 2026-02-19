class Solution:
    def makeTheIntegerZero(self, num1: int, num2: int) -> int:
        for t in range(61):  # Try t = 0 to 60
            s = num1 - t * num2
            if s < 0:
                continue
            if s < t:
                continue
            ones = bin(s).count('1')  # Count 1s in binary
            if ones <= t:
                return t
        return -1
