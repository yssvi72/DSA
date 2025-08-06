class SegTree:
    def __init__(self, nodes: List[int]):
        self.max = max(nodes)
        self.left = self.right = None
        if len(nodes) > 1:
            mid = len(nodes) // 2
            self.left = SegTree(nodes[:mid])
            if len(nodes[mid:]) > 0:
                self.right = SegTree(nodes[mid:])

    def tryPlace(self, fruit: int) -> int:
        if fruit > self.max:
            return 1
        res = -1
        if self.left and fruit <= self.left.max:
            res = self.left.tryPlace(fruit)
            if res < 0:
                self.left = None
                if self.right:
                    self.max = self.right.max
                    return 0
        elif self.right:
            res = self.right.tryPlace(fruit)
            if res < 0:
                self.right = None
                if self.left:
                    self.max = self.left.max
                    return 0
        if res == 0:
            self.max = max(
                self.left.max if self.left else -1, 
                self.right.max if self.right else -1
            )
        return res
    

class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        seg = SegTree(baskets)
        res = 0
        for fruit in fruits:
            res += seg.tryPlace(fruit)
        return max(0, res)
