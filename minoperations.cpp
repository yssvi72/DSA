class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        n = len(boxes)
        pre = [0] * n
        suf = [0] * n
        numOf1 = 0
        index = 0
        for i in range(n):
            pre[i] = i*numOf1 - index
            if boxes[i] == '1':
                numOf1 += 1
                index += i
        backindex = 0
        numOf1 = 0
        for i in range(n-1,-1,-1):
            suf[i] = backindex - i * numOf1
            if boxes[i] == '1':
                numOf1 += 1
                backindex += i
        ans = []
        for i in range(n):
            ans.append(pre[i] + suf[i])
        return ans
            
        
