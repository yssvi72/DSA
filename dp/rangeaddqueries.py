class Solution:
    def rangeAddQueries(self, n: int, queries: List[List[int]]) -> List[List[int]]:
        # 2D difference matrix
        mat = [[0]*n for _ in range(n)]
        for x1, y1, x2, y2 in queries:
            mat[x1][y1] += 1
            if x2+1 < n: mat[x2+1][y1] -= 1
            if y2+1 < n: mat[x1][y2+1] -= 1
            if x2+1 < n and y2+1 < n: mat[x2+1][y2+1] += 1

        # prefix sum
        for i in range(n):
            for j in range(n):
                if i-1 >= 0: mat[i][j] += mat[i-1][j]
                if j-1 >= 0: mat[i][j] += mat[i][j-1] 
                if i-1 >=0 and j-1 >= 0: mat[i][j] -= mat[i-1][j-1]
        return mat   
