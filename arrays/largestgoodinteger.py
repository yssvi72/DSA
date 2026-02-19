class Solution:
    def largestGoodInteger(self, num: str) -> str:

        matches = []
        final_result = []

        for i in range(len(num) - 2): 
            if num[i] == num[i+1] == num[i+2]:  
                matches.append(num[i]*3)
            
        list_sorted = sorted(matches, reverse=True)

        if len(list_sorted) > 0:
            final_result.append(list_sorted[0])
            answer = ''.join(map(str, final_result))
            return answer
        else:
            return ""
