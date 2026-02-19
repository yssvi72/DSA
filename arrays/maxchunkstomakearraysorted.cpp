class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        maxseensofar=0
        chunks=0
        n=len(arr)
        for i,arr in enumerate(arr):
            maxseensofar=max(maxseensofar,arr)
            if maxseensofar==i:
                chunks+=1
        return chunks
        

            

