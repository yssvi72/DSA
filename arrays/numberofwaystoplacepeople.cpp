from typing import List
from math import inf

class Solution:
    def numberOfPairs(self, points: List[List[int]]) -> int:
        # Sort points by x-coordinate (ascending), then by y-coordinate (descending)
        # This ensures we process points from left to right, with higher points first
        points.sort(key=lambda point: (point[0], -point[1]))
      
        # Initialize counter for valid pairs
        pair_count = 0
      
        # Iterate through each point as the potential left point of a pair
        for i, (x1, y1) in enumerate(points):
            # Track the maximum y-coordinate seen so far for valid right points
            # This helps avoid counting pairs where another point blocks the view
            max_y_seen = -inf
          
            # Check all points to the right of current point
            for x2, y2 in points[i + 1:]:
                # A valid pair must satisfy:
                # 1. y2 is not higher than y1 (y2 <= y1)
                # 2. y2 is higher than any previously seen valid point (y2 > max_y_seen)
                # This ensures no other point blocks the rectangular region
                if max_y_seen < y2 <= y1:
                    max_y_seen = y2
                    pair_count += 1
      
        return pair_count
