class Solution:
    def shiftingLetters(self, s: str, shifts: List[List[int]]) -> str:
        n = len(s)

        count = [0]*(n+1)

        for st,en,di in shifts:
            op = 1
            if di == 0:
                op = -1

            count[st] += op
            count[en+1] -= op

        ans = []

        total = 0

        for i in range(n):
            curr = ord(s[i]) - ord('a')
            total = (total + count[i])

            newC = (curr + total)%26 + ord('a')

            ans.append(chr(newC))

        return "".join(ans)


