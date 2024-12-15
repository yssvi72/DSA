class Solution:
    def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:

        total = len(classes)
        total_ratio = 0
        heap = []
        heapify(heap)

        #Create a max heap of marginal gain for each class to keep track of the maximum gain dynamically
        for clss in classes:
            a, b = clss
            """
            ratio = a / b
            marginal gain = (a+1)/(b+1) - a/b = (b-a) / b(b+1)
            """
            total_ratio += (a / b)
            marginal_gain = (b-a) / (b*(b+1)) 
            heappush(heap, (-marginal_gain, a, b))
        
        #Iterate over the extraStudents to calculate the total_ratio and push the new marginal gain to the heap
        for _ in range(extraStudents):
            marginal_gain, a, b = heappop(heap)
            total_ratio += -marginal_gain
            a, b = a+1, b+1
            new_marginal_gain = (b-a) / (b*(b+1))
            heappush(heap, (-new_marginal_gain, a, b))
        
        return total_ratio / total


