class Solution:
    def minCost(self, basket1: List[int], basket2: List[int]) -> int:
        counter = Counter(basket1)
        target = counter + Counter(basket2)
        for k, v in target.items():
            if v%2!=0:
                return -1
        total = 0
        mv = min(target.keys())
        swap = []
        for k, v in target.items():
            t = v//2
            diff = counter.get(k, 0)-t
            for _ in range(abs(diff)):
                swap.append(k)
        swap.sort()
        swaps = len(swap)//2
        for i in range(swaps):
            total += min(swap[i], 2*mv)
        return total
