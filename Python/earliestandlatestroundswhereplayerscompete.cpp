import functools
import math
from typing import List

class Solution:
    def earliestAndLatest(self, n: int, firstPlayer: int, secondPlayer: int) -> List[int]:
        """
        Computes the earliest and latest rounds in which two players can meet in a single-elimination tournament.
        Players are indexed from 1 to n, and matches are conducted in pairs from outermost inwards each round.

        Args:
            n (int): Total number of players.
            firstPlayer (int): Index of the first player.
            secondPlayer (int): Index of the second player.

        Returns:
            List[int]: A list containing the earliest and latest round they can meet.
        """

        @functools.lru_cache(maxsize=None)
        def dp(l: int, r: int, k: int) -> List[int]:
            """
            Recursive helper function using memoization to find the earliest and latest
            meeting rounds for players at positions l and r among k players.
            """
            # Base case: same position implies they meet in this round
            if l == r:
                return [1, 1]

            # Ensure l < r for symmetric handling
            if l > r:
                return dp(r, l, k)

            earliest = math.inf
            latest = -math.inf

            # Enumerate all valid player positions in the next round
            for i in range(1, l + 1):
                for j in range(l - i + 1, r - i + 1):
                    # Valid position range check for round splitting
                    if not (l + r - k // 2 <= i + j <= (k + 1) // 2):
                        continue

                    # Recursive call: simulate next round with updated positions
                    early, late = dp(i, j, (k + 1) // 2)
                    earliest = min(earliest, early + 1)
                    latest = max(latest, late + 1)

            return [earliest, latest]

        # Adjust second player's index to reflect mirrored positioning in the first round
        return dp(firstPlayer, n - secondPlayer + 1, n)
